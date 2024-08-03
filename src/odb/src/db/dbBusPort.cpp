///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2022, The Regents of the University of California
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
#include "dbBusPort.h"

#include "dbBlock.h"
#include "dbBusPort.h"
#include "dbDatabase.h"
#include "dbDiff.hpp"
#include "dbHashTable.hpp"
#include "dbModBTerm.h"
#include "dbModITerm.h"
#include "dbModNet.h"
#include "dbModule.h"
#include "dbModuleBusPortModBTermItr.h"
#include "dbTable.h"
#include "dbTable.hpp"
#include "dbVector.h"
#include "odb/db.h"
namespace odb {
template class dbTable<_dbBusPort>;

bool _dbBusPort::operator==(const _dbBusPort& rhs) const
{
  if (_flags != rhs._flags) {
    return false;
  }
  if (_from != rhs._from) {
    return false;
  }
  if (_to != rhs._to) {
    return false;
  }
  if (_port != rhs._port) {
    return false;
  }
  if (_members != rhs._members) {
    return false;
  }
  if (_parent != rhs._parent) {
    return false;
  }

  return true;
}

bool _dbBusPort::operator<(const _dbBusPort& rhs) const
{
  return true;
}

void _dbBusPort::differences(dbDiff& diff,
                             const char* field,
                             const _dbBusPort& rhs) const
{
  DIFF_BEGIN
  DIFF_FIELD(_flags);
  DIFF_FIELD(_from);
  DIFF_FIELD(_to);
  DIFF_FIELD(_port);
  DIFF_FIELD(_members);
  DIFF_FIELD(_parent);
  DIFF_END
}

void _dbBusPort::out(dbDiff& diff, char side, const char* field) const
{
  DIFF_OUT_BEGIN
  DIFF_OUT_FIELD(_flags);
  DIFF_OUT_FIELD(_from);
  DIFF_OUT_FIELD(_to);
  DIFF_OUT_FIELD(_port);
  DIFF_OUT_FIELD(_members);
  DIFF_OUT_FIELD(_parent);

  DIFF_END
}

_dbBusPort::_dbBusPort(_dbDatabase* db)
{
  _flags = 0;
  _from = 0;
  _to = 0;
}

_dbBusPort::_dbBusPort(_dbDatabase* db, const _dbBusPort& r)
{
  _flags = r._flags;
  _from = r._from;
  _to = r._to;
  _port = r._port;
  _members = r._members;
  _parent = r._parent;
}

dbIStream& operator>>(dbIStream& stream, _dbBusPort& obj)
{
  if (obj.getDatabase()->isSchema(db_schema_update_hierarchy)) {
    stream >> obj._flags;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream >> obj._from;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream >> obj._to;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream >> obj._port;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream >> obj._members;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream >> obj._parent;
  }
  return stream;
}

dbOStream& operator<<(dbOStream& stream, const _dbBusPort& obj)
{
  if (obj.getDatabase()->isSchema(db_schema_update_hierarchy)) {
    stream << obj._flags;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream << obj._from;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream << obj._to;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream << obj._port;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream << obj._members;
  }
  if (obj.getDatabase()->isSchema(db_schema_odb_busport)) {
    stream << obj._parent;
  }
  return stream;
}

_dbBusPort::~_dbBusPort()
{
  // User Code Begin d
  if (_members_iter != nullptr) {
    delete (_members_iter);
  }
  // User Code End d
}

////////////////////////////////////////////////////////////////////
//
// dbBusPort - Methods
//
////////////////////////////////////////////////////////////////////

int dbBusPort::getFrom() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  return obj->_from;
}

int dbBusPort::getTo() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  return obj->_to;
}

dbModBTerm* dbBusPort::getPort() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  if (obj->_port == 0) {
    return nullptr;
  }
  _dbBlock* par = (_dbBlock*) obj->getOwner();
  return (dbModBTerm*) par->_modbterm_tbl->getPtr(obj->_port);
}

dbModBTerm* dbBusPort::getMembers() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  if (obj->_members == 0) {
    return nullptr;
  }
  _dbBlock* par = (_dbBlock*) obj->getOwner();
  return (dbModBTerm*) par->_modbterm_tbl->getPtr(obj->_members);
}

dbModule* dbBusPort::getParent() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  if (obj->_parent == 0) {
    return nullptr;
  }
  _dbBlock* par = (_dbBlock*) obj->getOwner();
  return (dbModule*) par->_module_tbl->getPtr(obj->_parent);
}

// User Code Begin dbBusPortPublicMethods

/*
  Get the indexed element. eg b[2] gets the element in the sequence
  at index 2. Note that depending on the from/to the offset
  of this index will change. eg
  b[1:5]
  element is at offset 1 in the array
  b[5:1] element is at offset 4 in the array
 */
dbModBTerm* dbBusPort::getBusIndexedElement(int index) const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  _dbBlock* block_ = (_dbBlock*) obj->getOwner();
  int offset;
  if (getUpdown()) {
    offset = index - getFrom();
  } else {
    offset = getFrom() - index;
  }
  if (offset < getSize()) {
    //
    // TODO. Future pull request: support for making vector of objects unclean.
    // if we cannot count on the order, skip to the dbModBterm
    //
    // the _flags are set to non zero if we cannot
    // count on the order of the modbterms (eg
    // if some have been deleted or added in non-linear way).
    //
    if (obj->_flags == 0U) {
      return (dbModBTerm*) (block_->_modbterm_tbl->getPtr(obj->getId() + offset
                                                          + 1));
    }
    dbModBTerm* cur = (dbModBTerm*) (block_->_modbterm_tbl->getPtr(obj->_port));
    if (cur != nullptr) {
      cur = cur->getPrev();
      for (int i = 0; i < offset; i++) {
        cur = cur->getPrev();
      }
      return cur;
    }
  }

  return nullptr;
}

void dbBusPort::setFirstMember(dbModBTerm* modbterm)
{
  if (modbterm) {
    _dbBusPort* obj = (_dbBusPort*) this;
    _dbModBTerm* mbt = (_dbModBTerm*) modbterm;
    obj->_members = mbt->getId();
  }
}

dbModBTerm* dbBusPort::getFirstMember()
{
  _dbBusPort* obj = (_dbBusPort*) this;
  _dbBlock* block = (_dbBlock*) obj->getOwner();
  if (obj->_members != 0) {
    dbModBTerm* ret
        = (dbModBTerm*) (block->_modbterm_tbl->getPtr(obj->_members));
    return ret;
  }
  return nullptr;
}

int dbBusPort::getSize() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  // we keep how the size is computed in the
  // database low level object so that if
  // we need to use it during low level
  // iterators we can.
  return obj->size();
}

bool dbBusPort::getUpdown() const
{
  _dbBusPort* obj = (_dbBusPort*) this;
  if (obj->_to >= obj->_from) {
    return true;
  }
  return false;
}

dbBusPort* dbBusPort::create(dbModule* parentModule,
                             dbModBTerm* port,
                             int from_ix,
                             int to_ix)
{
  _dbModule* module = (_dbModule*) parentModule;
  _dbBlock* block = (_dbBlock*) module->getOwner();
  _dbBusPort* busport = block->_busport_tbl->create();
  busport->_port = port->getId();
  busport->_from = from_ix;
  busport->_to = to_ix;
  busport->_flags = 0U;
  busport->_parent = module->getOID();
  return (dbBusPort*) busport;
}

dbSet<dbModBTerm> dbBusPort::getBusPortMembers()
{
  _dbBusPort* obj = (_dbBusPort*) this;
  if (obj->_members_iter == nullptr) {
    _dbBlock* block = (_dbBlock*) obj->getOwner();
    obj->_members_iter = new dbModuleBusPortModBTermItr(block->_modbterm_tbl);
  }
  return dbSet<dbModBTerm>(this, obj->_members_iter);
}

//
// TODO future pull request: Reallocate the bus to preserve sequential db
// ordering This to be added as part of "scaffolding functions"
//
void dbBusPort::Realloc()
{
  /*
  _dbBusPort* obj = (_dbBusPort*) this;
  _dbBlock* block = (_dbBlock*) obj->getOwner();
  dbModule* parentModule (_dbModule*) obj -> getParent();
  if (obj -> _flags !=0U){
    dbModBTerm* busport = block -> modbterm_tbl -> getPtr(obj -> _port);
    dbModBTerm* cur = busport -> getPrev();
    //
    //sequentially reallocate the elements
    //to assure they are layed out for sequential access
    //after being tampered with.
    //
    int size = obj -> getSize();
    for (int i =0; i < size; i++){
      dbModBTerm* new_cur = dbModBTerm::create(parentModule,cur -> getName());
      new_cur -> _modnet = cur -> _modnet;
      new_cur -> _next_net_modbterm = cur -> _modbterm;
      new_cur -> _prev_net_modbterm = cur -> _modbterm;
      new_cur -> _busPort = cur -> _busPort;
      new_cur -> _name = cur -> _name;
      new_cur -> _parent = cur -> _parent;
    }
  }
 */
}

// User Code End dbBusPortPublicMethods
}  // namespace odb
   // Generator Code End Cpp
