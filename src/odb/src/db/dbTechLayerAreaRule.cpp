///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2020, The Regents of the University of California
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

// Generator Code Begin Cpp
#include "dbTechLayerAreaRule.h"

#include "db.h"
#include "dbDatabase.h"
#include "dbDiff.hpp"
#include "dbTable.h"
#include "dbTable.hpp"
#include "dbTechLayer.h"
// User Code Begin Includes
// User Code End Includes
namespace odb {

template class dbTable<_dbTechLayerAreaRule>;

bool _dbTechLayerAreaRule::operator==(const _dbTechLayerAreaRule& rhs) const
{
  if (flags_.except_rectangle != rhs.flags_.except_rectangle)
    return false;

  if (area != rhs.area)
    return false;

  if (except_min_witdh != rhs.except_min_witdh)
    return false;

  if (except_edge_length != rhs.except_edge_length)
    return false;

  if (trim_layer_ != rhs.trim_layer_)
    return false;

  if (overlap != rhs.overlap)
    return false;

  if (mask != rhs.mask)
    return false;

  if (rect_width != rhs.rect_width)
    return false;

  // User Code Begin ==
  // User Code End ==
  return true;
}
bool _dbTechLayerAreaRule::operator<(const _dbTechLayerAreaRule& rhs) const
{
  // User Code Begin <
  // User Code End <
  return true;
}
void _dbTechLayerAreaRule::differences(dbDiff& diff,
                                       const char* field,
                                       const _dbTechLayerAreaRule& rhs) const
{
  DIFF_BEGIN

  DIFF_FIELD(flags_.except_rectangle);
  DIFF_FIELD(area);
  DIFF_FIELD(except_min_witdh);
  DIFF_FIELD(except_edge_length);
  DIFF_FIELD(trim_layer_);
  DIFF_FIELD(overlap);
  DIFF_FIELD(mask);
  DIFF_FIELD(rect_width);
  // User Code Begin Differences
  // User Code End Differences
  DIFF_END
}
void _dbTechLayerAreaRule::out(dbDiff& diff, char side, const char* field) const
{
  DIFF_OUT_BEGIN
  DIFF_OUT_FIELD(flags_.except_rectangle);
  DIFF_OUT_FIELD(area);
  DIFF_OUT_FIELD(except_min_witdh);
  DIFF_OUT_FIELD(except_edge_length);
  DIFF_OUT_FIELD(trim_layer_);
  DIFF_OUT_FIELD(overlap);
  DIFF_OUT_FIELD(mask);
  DIFF_OUT_FIELD(rect_width);

  // User Code Begin Out
  // User Code End Out
  DIFF_END
}
_dbTechLayerAreaRule::_dbTechLayerAreaRule(_dbDatabase* db)
{
  uint32_t* flags__bit_field = (uint32_t*) &flags_;
  *flags__bit_field = 0;
  // User Code Begin Constructor
  // User Code End Constructor
}
_dbTechLayerAreaRule::_dbTechLayerAreaRule(_dbDatabase* db,
                                           const _dbTechLayerAreaRule& r)
{
  flags_.except_rectangle = r.flags_.except_rectangle;
  flags_.spare_bits_ = r.flags_.spare_bits_;
  area = r.area;
  except_min_witdh = r.except_min_witdh;
  except_edge_length = r.except_edge_length;
  trim_layer_ = r.trim_layer_;
  overlap = r.overlap;
  mask = r.mask;
  rect_width = r.rect_width;
  // User Code Begin CopyConstructor
  // User Code End CopyConstructor
}

dbIStream& operator>>(dbIStream& stream, _dbTechLayerAreaRule& obj)
{
  uint32_t* flags__bit_field = (uint32_t*) &obj.flags_;
  stream >> *flags__bit_field;
  stream >> obj.area;
  stream >> obj.except_min_witdh;
  stream >> obj.except_edge_length;
  stream >> obj.except_edge_lengths;
  stream >> obj.except_min_size;
  stream >> obj.except_step;
  stream >> obj.trim_layer_;
  stream >> obj.overlap;
  stream >> obj.mask;
  stream >> obj.rect_width;
  // User Code Begin >>
  // User Code End >>
  return stream;
}
dbOStream& operator<<(dbOStream& stream, const _dbTechLayerAreaRule& obj)
{
  uint32_t* flags__bit_field = (uint32_t*) &obj.flags_;
  stream << *flags__bit_field;
  stream << obj.area;
  stream << obj.except_min_witdh;
  stream << obj.except_edge_length;
  stream << obj.except_edge_lengths;
  stream << obj.except_min_size;
  stream << obj.except_step;
  stream << obj.trim_layer_;
  stream << obj.overlap;
  stream << obj.mask;
  stream << obj.rect_width;
  // User Code Begin <<
  // User Code End <<
  return stream;
}

_dbTechLayerAreaRule::~_dbTechLayerAreaRule()
{
  // User Code Begin Destructor
  // User Code End Destructor
}

// User Code Begin PrivateMethods
// User Code End PrivateMethods

////////////////////////////////////////////////////////////////////
//
// dbTechLayerAreaRule - Methods
//
////////////////////////////////////////////////////////////////////

void dbTechLayerAreaRule::setArea(int area)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->area = area;
}

int dbTechLayerAreaRule::getArea() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->area;
}

void dbTechLayerAreaRule::setExceptMinWitdh(int except_min_witdh)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->except_min_witdh = except_min_witdh;
}

int dbTechLayerAreaRule::getExceptMinWitdh() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->except_min_witdh;
}

void dbTechLayerAreaRule::setExceptEdgeLength(int except_edge_length)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->except_edge_length = except_edge_length;
}

int dbTechLayerAreaRule::getExceptEdgeLength() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->except_edge_length;
}

void dbTechLayerAreaRule::setExceptEdgeLengths(
    std::pair<int, int> except_edge_lengths)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->except_edge_lengths = except_edge_lengths;
}

std::pair<int, int> dbTechLayerAreaRule::getExceptEdgeLengths() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->except_edge_lengths;
}

void dbTechLayerAreaRule::setExceptMinSize(std::pair<int, int> except_min_size)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->except_min_size = except_min_size;
}

std::pair<int, int> dbTechLayerAreaRule::getExceptMinSize() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->except_min_size;
}

void dbTechLayerAreaRule::setExceptStep(std::pair<int, int> except_step)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->except_step = except_step;
}

std::pair<int, int> dbTechLayerAreaRule::getExceptStep() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->except_step;
}

void dbTechLayerAreaRule::setOverlap(int overlap)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->overlap = overlap;
}

int dbTechLayerAreaRule::getOverlap() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->overlap;
}

void dbTechLayerAreaRule::setMask(int mask)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->mask = mask;
}

int dbTechLayerAreaRule::getMask() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->mask;
}

void dbTechLayerAreaRule::setRectWidth(int rect_width)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->rect_width = rect_width;
}

int dbTechLayerAreaRule::getRectWidth() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  return obj->rect_width;
}

void dbTechLayerAreaRule::setExceptRectangle(bool except_rectangle)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->flags_.except_rectangle = except_rectangle;
}

bool dbTechLayerAreaRule::isExceptRectangle() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  return obj->flags_.except_rectangle;
}

// User Code Begin dbTechLayerAreaRulePublicMethods.

dbTechLayerAreaRule* dbTechLayerAreaRule::create(dbTechLayer* _layer)
{
  _dbTechLayer* layer = (_dbTechLayer*) _layer;
  _dbTechLayerAreaRule* newrule = layer->area_rules_tbl_->create();
  return ((dbTechLayerAreaRule*) newrule);
}

void dbTechLayerAreaRule::setTrimLayer(dbTechLayer* trim_layer)
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;

  obj->trim_layer_ = trim_layer->getImpl()->getOID();
}

dbTechLayer* dbTechLayerAreaRule::getLayer() const
{
  _dbTechLayerAreaRule* obj = (_dbTechLayerAreaRule*) this;
  odb::dbTech* tech = getDb()->getTech();
  return odb::dbTechLayer::getTechLayer(tech, obj->trim_layer_);
}

void dbTechLayerAreaRule::destroy(dbTechLayerAreaRule* rule)
{
  _dbTechLayer* layer = (_dbTechLayer*) rule->getImpl()->getOwner();
  dbProperty::destroyProperties(rule);
  layer->area_rules_tbl_->destroy((_dbTechLayerAreaRule*) rule);
}

// User Code End dbTechLayerAreaRulePublicMethods
}  // namespace odb
   // Generator Code End Cpp