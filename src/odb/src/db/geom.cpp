///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2024, The Regents of the University of California
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "odb/geom.h"

#include "odb/geom_boost.h"

namespace odb {

Polygon Polygon::correct() const
{
  std::vector<Point> pts = points_;
  boost::geometry::correct(pts);
  return Polygon(pts);
}

Polygon Polygon::bloat(int margin) const
{
  const odb::Polygon polygon = correct();

  // convert to native boost types to avoid needed a mutable access
  // to odb::Polygon
  using pt = boost::geometry::model::d2::point_xy<int>;
  using poly = boost::geometry::model::polygon<pt>;
  using multipoly = boost::geometry::model::multi_polygon<poly>;
  poly polygon_in;
  multipoly polygons_out;

  boost::geometry::assign_points(polygon_in, polygon.getPoints());

  using dist = boost::geometry::strategy::buffer::distance_symmetric<int>;
  boost::geometry::strategy::buffer::side_straight side_strategy;
  boost::geometry::strategy::buffer::join_round join_strategy;
  boost::geometry::strategy::buffer::end_flat end_strategy;
  boost::geometry::strategy::buffer::point_circle point_strategy;

  boost::geometry::buffer(polygon_in,
                          polygons_out,
                          dist(margin),
                          side_strategy,
                          join_strategy,
                          end_strategy,
                          point_strategy);

  // return to Polygon type
  std::vector<odb::Point> out_points;
  for (const auto& pt : polygons_out[0].outer()) {
    out_points.emplace_back(pt.x(), pt.y());
  }

  return Polygon(out_points);
}

}  // namespace odb
