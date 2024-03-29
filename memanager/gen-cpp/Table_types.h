/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Table_TYPES_H
#define Table_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Types_types.h"
#include "TSchema_types.h"


namespace memanager {

typedef struct _TColumnValue__isset {
  _TColumnValue__isset() : bool_val(false), byte_val(false), short_val(false), int_val(false), long_val(false), double_val(false), string_val(false), binary_val(false) {}
  bool bool_val;
  bool byte_val;
  bool short_val;
  bool int_val;
  bool long_val;
  bool double_val;
  bool string_val;
  bool binary_val;
} _TColumnValue__isset;

class TColumnValue {
 public:

  static const char* ascii_fingerprint; // = "15543D4AC23DC11B825EEE5A988F6DEE";
  static const uint8_t binary_fingerprint[16]; // = {0x15,0x54,0x3D,0x4A,0xC2,0x3D,0xC1,0x1B,0x82,0x5E,0xEE,0x5A,0x98,0x8F,0x6D,0xEE};

  TColumnValue() : bool_val(0), byte_val(0), short_val(0), int_val(0), long_val(0), double_val(0), string_val(), binary_val() {
  }

  virtual ~TColumnValue() throw() {}

  bool bool_val;
  int8_t byte_val;
  int16_t short_val;
  int32_t int_val;
  int64_t long_val;
  double double_val;
  std::string string_val;
  std::string binary_val;

  _TColumnValue__isset __isset;

  void __set_bool_val(const bool val) {
    bool_val = val;
    __isset.bool_val = true;
  }

  void __set_byte_val(const int8_t val) {
    byte_val = val;
    __isset.byte_val = true;
  }

  void __set_short_val(const int16_t val) {
    short_val = val;
    __isset.short_val = true;
  }

  void __set_int_val(const int32_t val) {
    int_val = val;
    __isset.int_val = true;
  }

  void __set_long_val(const int64_t val) {
    long_val = val;
    __isset.long_val = true;
  }

  void __set_double_val(const double val) {
    double_val = val;
    __isset.double_val = true;
  }

  void __set_string_val(const std::string& val) {
    string_val = val;
    __isset.string_val = true;
  }

  void __set_binary_val(const std::string& val) {
    binary_val = val;
    __isset.binary_val = true;
  }

  bool operator == (const TColumnValue & rhs) const
  {
    if (__isset.bool_val != rhs.__isset.bool_val)
      return false;
    else if (__isset.bool_val && !(bool_val == rhs.bool_val))
      return false;
    if (__isset.byte_val != rhs.__isset.byte_val)
      return false;
    else if (__isset.byte_val && !(byte_val == rhs.byte_val))
      return false;
    if (__isset.short_val != rhs.__isset.short_val)
      return false;
    else if (__isset.short_val && !(short_val == rhs.short_val))
      return false;
    if (__isset.int_val != rhs.__isset.int_val)
      return false;
    else if (__isset.int_val && !(int_val == rhs.int_val))
      return false;
    if (__isset.long_val != rhs.__isset.long_val)
      return false;
    else if (__isset.long_val && !(long_val == rhs.long_val))
      return false;
    if (__isset.double_val != rhs.__isset.double_val)
      return false;
    else if (__isset.double_val && !(double_val == rhs.double_val))
      return false;
    if (__isset.string_val != rhs.__isset.string_val)
      return false;
    else if (__isset.string_val && !(string_val == rhs.string_val))
      return false;
    if (__isset.binary_val != rhs.__isset.binary_val)
      return false;
    else if (__isset.binary_val && !(binary_val == rhs.binary_val))
      return false;
    return true;
  }
  bool operator != (const TColumnValue &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumnValue & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TColumnValue &a, TColumnValue &b);

typedef struct _TTableRow__isset {
  _TTableRow__isset() : colVals(false) {}
  bool colVals;
} _TTableRow__isset;

class TTableRow {
 public:

  static const char* ascii_fingerprint; // = "0010C6F851B6BC51F346FDABAD206952";
  static const uint8_t binary_fingerprint[16]; // = {0x00,0x10,0xC6,0xF8,0x51,0xB6,0xBC,0x51,0xF3,0x46,0xFD,0xAB,0xAD,0x20,0x69,0x52};

  TTableRow() {
  }

  virtual ~TTableRow() throw() {}

  std::vector<TColumnValue>  colVals;

  _TTableRow__isset __isset;

  void __set_colVals(const std::vector<TColumnValue> & val) {
    colVals = val;
  }

  bool operator == (const TTableRow & rhs) const
  {
    if (!(colVals == rhs.colVals))
      return false;
    return true;
  }
  bool operator != (const TTableRow &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTableRow & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TTableRow &a, TTableRow &b);


class TTable {
 public:

  static const char* ascii_fingerprint; // = "43EC18B8E279F4536A1EBF4E1533AB23";
  static const uint8_t binary_fingerprint[16]; // = {0x43,0xEC,0x18,0xB8,0xE2,0x79,0xF4,0x53,0x6A,0x1E,0xBF,0x4E,0x15,0x33,0xAB,0x23};

  TTable() {
  }

  virtual ~TTable() throw() {}

  std::vector<TTableRow>  rows;
   ::memanager::TTableSchema schema;

  void __set_rows(const std::vector<TTableRow> & val) {
    rows = val;
  }

  void __set_schema(const  ::memanager::TTableSchema& val) {
    schema = val;
  }

  bool operator == (const TTable & rhs) const
  {
    if (!(rows == rhs.rows))
      return false;
    if (!(schema == rhs.schema))
      return false;
    return true;
  }
  bool operator != (const TTable &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTable & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TTable &a, TTable &b);

} // namespace

#endif
