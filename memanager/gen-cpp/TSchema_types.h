/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TSchema_TYPES_H
#define TSchema_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Types_types.h"


namespace memanager {

typedef struct _TColumn__isset {
  _TColumn__isset() : comment(false), position(false) {}
  bool comment;
  bool position;
} _TColumn__isset;

class TColumn {
 public:

  static const char* ascii_fingerprint; // = "34E4D995EB8189B72763699020CD2AA9";
  static const uint8_t binary_fingerprint[16]; // = {0x34,0xE4,0xD9,0x95,0xEB,0x81,0x89,0xB7,0x27,0x63,0x69,0x90,0x20,0xCD,0x2A,0xA9};

  TColumn() : columnName(), comment(), position(0) {
  }

  virtual ~TColumn() throw() {}

  std::string columnName;
   ::memanager::TColumnType columnType;
  std::string comment;
  int32_t position;

  _TColumn__isset __isset;

  void __set_columnName(const std::string& val) {
    columnName = val;
  }

  void __set_columnType(const  ::memanager::TColumnType& val) {
    columnType = val;
  }

  void __set_comment(const std::string& val) {
    comment = val;
    __isset.comment = true;
  }

  void __set_position(const int32_t val) {
    position = val;
    __isset.position = true;
  }

  bool operator == (const TColumn & rhs) const
  {
    if (!(columnName == rhs.columnName))
      return false;
    if (!(columnType == rhs.columnType))
      return false;
    if (__isset.comment != rhs.__isset.comment)
      return false;
    else if (__isset.comment && !(comment == rhs.comment))
      return false;
    if (__isset.position != rhs.__isset.position)
      return false;
    else if (__isset.position && !(position == rhs.position))
      return false;
    return true;
  }
  bool operator != (const TColumn &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumn & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TColumn &a, TColumn &b);

typedef struct _TTableSchema__isset {
  _TTableSchema__isset() : id(false), columns(false) {}
  bool id;
  bool columns;
} _TTableSchema__isset;

class TTableSchema {
 public:

  static const char* ascii_fingerprint; // = "3606A123DEA03AAFA21D75BA9554B7B0";
  static const uint8_t binary_fingerprint[16]; // = {0x36,0x06,0xA1,0x23,0xDE,0xA0,0x3A,0xAF,0xA2,0x1D,0x75,0xBA,0x95,0x54,0xB7,0xB0};

  TTableSchema() : tbl_name(), id(0) {
  }

  virtual ~TTableSchema() throw() {}

  std::string tbl_name;
   ::memanager::TTableId id;
  std::vector<TColumn>  columns;

  _TTableSchema__isset __isset;

  void __set_tbl_name(const std::string& val) {
    tbl_name = val;
  }

  void __set_id(const  ::memanager::TTableId val) {
    id = val;
    __isset.id = true;
  }

  void __set_columns(const std::vector<TColumn> & val) {
    columns = val;
    __isset.columns = true;
  }

  bool operator == (const TTableSchema & rhs) const
  {
    if (!(tbl_name == rhs.tbl_name))
      return false;
    if (__isset.id != rhs.__isset.id)
      return false;
    else if (__isset.id && !(id == rhs.id))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    return true;
  }
  bool operator != (const TTableSchema &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTableSchema & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TTableSchema &a, TTableSchema &b);

} // namespace

#endif