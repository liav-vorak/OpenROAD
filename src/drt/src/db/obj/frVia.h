/* Authors: Lutong Wang and Bangqi Xu */
/*
 * Copyright (c) 2019, The Regents of the University of California
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FR_VIA_H_
#define _FR_VIA_H_

#include <memory>

#include "db/obj/frRef.h"
#include "db/obj/frShape.h"
#include "db/tech/frViaDef.h"

namespace fr {
class frNet;
class drVia;
class frVia : public frRef
{
 public:
  // constructors
  frVia()
      : viaDef_(nullptr),
        owner_(nullptr),
        tapered_(false),
        bottomConnected_(false),
        topConnected_(false)
  {
  }
  frVia(frViaDef* in)
      : frRef(),
        origin_(),
        viaDef_(in),
        owner_(nullptr),
        tapered_(false),
        bottomConnected_(false),
        topConnected_(false)
  {
  }
  frVia(const frVia& in)
      : frRef(in),
        origin_(in.origin_),
        viaDef_(in.viaDef_),
        owner_(in.owner_),
        tapered_(in.tapered_),
        bottomConnected_(in.bottomConnected_),
        topConnected_(in.topConnected_)
  {
  }
  frVia(const drVia& in);
  // getters
  frViaDef* getViaDef() const { return viaDef_; }
  void getLayer1BBox(Rect& boxIn) const
  {
    auto& figs = viaDef_->getLayer1Figs();
    bool isFirst = true;
    Rect box;
    frCoord xl = 0;
    frCoord yl = 0;
    frCoord xh = 0;
    frCoord yh = 0;
    for (auto& fig : figs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    boxIn.init(xl, yl, xh, yh);
    dbTransform xform;
    xform.setOffset(origin_);
    xform.apply(boxIn);
  }
  void getCutBBox(Rect& boxIn) const
  {
    auto& figs = viaDef_->getCutFigs();
    bool isFirst = true;
    Rect box;
    frCoord xl = 0;
    frCoord yl = 0;
    frCoord xh = 0;
    frCoord yh = 0;
    for (auto& fig : figs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    boxIn.init(xl, yl, xh, yh);
    dbTransform xform;
    xform.setOffset(origin_);
    xform.apply(boxIn);
  }
  void getLayer2BBox(Rect& boxIn) const
  {
    auto& figs = viaDef_->getLayer2Figs();
    bool isFirst = true;
    Rect box;
    frCoord xl = 0;
    frCoord yl = 0;
    frCoord xh = 0;
    frCoord yh = 0;
    for (auto& fig : figs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    boxIn.init(xl, yl, xh, yh);
    dbTransform xform;
    xform.setOffset(origin_);
    xform.apply(boxIn);
  }
  // setters
  void setViaDef(frViaDef* in) { viaDef_ = in; }
  // others
  frBlockObjectEnum typeId() const override { return frcVia; }

  /* from frRef
   * getOrient
   * setOrient
   * getOrigin
   * setOrigin
   * getTransform
   * setTransform
   */

  dbOrientType getOrient() const override { return dbOrientType(); }
  void setOrient(const dbOrientType& tmpOrient) override { ; }
  void getOrigin(Point& tmpOrigin) const override { tmpOrigin = origin_; }
  const Point getOrigin() const { return origin_; }
  void setOrigin(const Point& tmpPoint) override { origin_ = tmpPoint; }
  void getTransform(dbTransform& xformIn) const override
  {
    xformIn.setOffset(origin_);
  }
  void setTransform(const dbTransform& xformIn) override {}

  /* from frPinFig
   * hasPin
   * getPin
   * addToPin
   * removeFromPin
   */
  bool hasPin() const override
  {
    return (owner_) && ((owner_->typeId() == frcBPin) ||
                         owner_->typeId() == frcMPin);
  }
  frPin* getPin() const override { return reinterpret_cast<frPin*>(owner_); }
  void addToPin(frPin* in) override
  {
    owner_ = reinterpret_cast<frBlockObject*>(in);
  }
  void addToPin(frBPin* in) override
  {
    owner_ = reinterpret_cast<frBlockObject*>(in);
  }
  void removeFromPin() override { owner_ = nullptr; }

  /* from frConnFig
   * hasNet
   * getNet
   * addToNet
   * removeFromNet
   */
  bool hasNet() const override
  {
    return (owner_) && (owner_->typeId() == frcNet);
  }
  frNet* getNet() const override { return reinterpret_cast<frNet*>(owner_); }
  void addToNet(frNet* in) override
  {
    owner_ = reinterpret_cast<frBlockObject*>(in);
  }
  void removeFromNet() override { owner_ = nullptr; }

  /* from frFig
   * getBBox
   * move
   * intersects
   */

  void getBBox(Rect& boxIn) const override
  {
    auto& layer1Figs = viaDef_->getLayer1Figs();
    auto& layer2Figs = viaDef_->getLayer2Figs();
    auto& cutFigs = viaDef_->getCutFigs();
    bool isFirst = true;
    Rect box;
    frCoord xl = 0;
    frCoord yl = 0;
    frCoord xh = 0;
    frCoord yh = 0;
    for (auto& fig : layer1Figs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    for (auto& fig : layer2Figs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    for (auto& fig : cutFigs) {
      fig->getBBox(box);
      if (isFirst) {
        xl = box.xMin();
        yl = box.yMin();
        xh = box.xMax();
        yh = box.yMax();
        isFirst = false;
      } else {
        xl = std::min(xl, box.xMin());
        yl = std::min(yl, box.yMin());
        xh = std::max(xh, box.xMax());
        yh = std::max(yh, box.yMax());
      }
    }
    boxIn.init(xl, yl, xh, yh);
    dbTransform xform;
    xform.setOffset(origin_);
    xform.apply(boxIn);
  }
  void move(const dbTransform& xform) override { ; }
  bool intersects(const Rect& box) const override { return false; }

  void setIter(frListIter<std::unique_ptr<frVia>>& in) { iter_ = in; }
  frListIter<std::unique_ptr<frVia>> getIter() const { return iter_; }
  void setTapered(bool t) { tapered_ = t; }

  bool isTapered() const { return tapered_; }

  bool isBottomConnected() const { return bottomConnected_; }
  bool isTopConnected() const { return topConnected_; }
  void setBottomConnected(bool c) { bottomConnected_ = c; }
  void setTopConnected(bool c) { topConnected_ = c; }

 private:
  Point origin_;
  frViaDef* viaDef_;
  frBlockObject* owner_;
  bool tapered_ : 1;
  bool bottomConnected_ : 1;
  bool topConnected_ : 1;
  frListIter<std::unique_ptr<frVia>> iter_;

  template <class Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    (ar) & boost::serialization::base_object<frRef>(*this);
    (ar) & origin_;
    (ar) & viaDef_;
    (ar) & owner_;
    bool tmp = false;
    if (is_loading(ar)) {
      (ar) & tmp;
      tapered_ = tmp;
      (ar) & tmp;
      bottomConnected_ = tmp;
      (ar) & tmp;
      topConnected_ = tmp;
    } else {
      tmp = tapered_;
      (ar) & tmp;
      tmp = bottomConnected_;
      (ar) & tmp;
      tmp = topConnected_;
      (ar) & tmp;
    }
    // iter is handled by the owner
  }

  friend class boost::serialization::access;
};
}  // namespace fr

#endif
