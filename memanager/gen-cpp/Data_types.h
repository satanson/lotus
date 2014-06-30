/**Re
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Data_TYPES_H
#define Data_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Types_types.h"
#include "Table_types.h"


namespace memanager {

typedef struct _TRowBatch__isset {
  _TRowBatch__isset() : tuple_offsets(false), tuple_data(false), is_compressed(false) {}
  bool tuple_offsets;
  bool tuple_data;
  bool is_compressed;
} _TRowBatch__isset;

class TRowBatch {
 public:

  static const char* ascii_fingerprint; // = "DA731EC0B9FA69ECC857FB6D2038C1D3";
  static const uint8_t binary_fingerprint[16]; // = {0xDA,0x73,0x1E,0xC0,0xB9,0xFA,0x69,0xEC,0xC8,0x57,0xFB,0x6D,0x20,0x38,0xC1,0xD3};

  TRowBatch() : num_rows(0), tuple_data(), is_compressed(0) {
  }

  virtual ~TRowBatch() throw() {}

  int32_t num_rows;
  std::vector< ::memanager::TTupleId>  row_tuples;
  std::vector<int32_t>  tuple_offsets;
  std::string tuple_data;
  bool is_compressed;

  _TRowBatch__isset __isset;

  void __set_num_rows(const int32_t val) {
    num_rows = val;
  }

  void __set_row_tuples(const std::vector< ::memanager::TTupleId> & val) {
    row_tuples = val;
  }

  void __set_tuple_offsets(const std::vector<int32_t> & val) {
    tuple_offsets = val;
  }

  void __set_tuple_data(const std::string& val) {
    tuple_data = val;
  }

  void __set_is_compressed(const bool val) {
    is_compressed = val;
  }

  bool operator == (const TRowBatch & rhs) const
  {
    if (!(num_rows == rhs.num_rows))
      return false;
    if (!(row_tuples == rhs.row_tuples))
      return false;
    if (!(tuple_offsets == rhs.tuple_offsets))
      return false;
    if (!(tuple_data == rhs.tuple_data))
      return false;
    if (!(is_compressed == rhs.is_compressed))
      return false;
    return true;
  }
  bool operator != (const TRowBatch &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRowBatch & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TRowBatch &a, TRowBatch &b);

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

typedef struct _TResultRow__isset {
  _TResultRow__isset() : colVals(false) {}
  bool colVals;
} _TResultRow__isset;

class TResultRow {
 public:

  static const char* ascii_fingerprint; // = "0010C6F851B6BC51F346FDABAD206952";
  static const uint8_t binary_fingerprint[16]; // = {0x00,0x10,0xC6,0xF8,0x51,0xB6,0xBC,0x51,0xF3,0x46,0xFD,0xAB,0xAD,0x20,0x69,0x52};

  TResultRow() {
  }

  virtual ~TResultRow() throw() {}

  std::vector<TColumnValue>  colVals;

  _TResultRow__isset __isset;

  void __set_colVals(const std::vector<TColumnValue> & val) {
    colVals = val;
  }

  bool operator == (const TResultRow & rhs) const
  {
    if (!(colVals == rhs.colVals))
      return false;
    return true;
  }
  bool operator != (const TResultRow &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TResultRow & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TResultRow &a, TResultRow &b);

typedef struct _TColumnData__isset {
  _TColumnData__isset() : bool_vals(false), byte_vals(false), short_vals(false), int_vals(false), long_vals(false), double_vals(false), string_vals(false), binary_vals(false) {}
  bool bool_vals;
  bool byte_vals;
  bool short_vals;
  bool int_vals;
  bool long_vals;
  bool double_vals;
  bool string_vals;
  bool binary_vals;
} _TColumnData__isset;

class TColumnData {
 public:

  static const char* ascii_fingerprint; // = "2F7A9538DF8A57EF0FF04950F29792C2";
  static const uint8_t binary_fingerprint[16]; // = {0x2F,0x7A,0x95,0x38,0xDF,0x8A,0x57,0xEF,0x0F,0xF0,0x49,0x50,0xF2,0x97,0x92,0xC2};

  TColumnData() {
  }

  virtual ~TColumnData() throw() {}

  std::vector<bool>  is_null;
  std::vector<bool>  bool_vals;
  std::vector<int8_t>  byte_vals;
  std::vector<int16_t>  short_vals;
  std::vector<int32_t>  int_vals;
  std::vector<int64_t>  long_vals;
  std::vector<double>  double_vals;
  std::vector<std::string>  string_vals;
  std::vector<std::string>  binary_vals;

  _TColumnData__isset __isset;

  void __set_is_null(const std::vector<bool> & val) {
    is_null = val;
  }

  void __set_bool_vals(const std::vector<bool> & val) {
    bool_vals = val;
    __isset.bool_vals = true;
  }

  void __set_byte_vals(const std::vector<int8_t> & val) {
    byte_vals = val;
    __isset.byte_vals = true;
  }

  void __set_short_vals(const std::vector<int16_t> & val) {
    short_vals = val;
    __isset.short_vals = true;
  }

  void __set_int_vals(const std::vector<int32_t> & val) {
    int_vals = val;
    __isset.int_vals = true;
  }

  void __set_long_vals(const std::vector<int64_t> & val) {
    long_vals = val;
    __isset.long_vals = true;
  }

  void __set_double_vals(const std::vector<double> & val) {
    double_vals = val;
    __isset.double_vals = true;
  }

  void __set_string_vals(const std::vector<std::string> & val) {
    string_vals = val;
    __isset.string_vals = true;
  }

  void __set_binary_vals(const std::vector<std::string> & val) {
    binary_vals = val;
    __isset.binary_vals = true;
  }

  bool operator == (const TColumnData & rhs) const
  {
    if (!(is_null == rhs.is_null))
      return false;
    if (__isset.bool_vals != rhs.__isset.bool_vals)
      return false;
    else if (__isset.bool_vals && !(bool_vals == rhs.bool_vals))
      return false;
    if (__isset.byte_vals != rhs.__isset.byte_vals)
      return false;
    else if (__isset.byte_vals && !(byte_vals == rhs.byte_vals))
      return false;
    if (__isset.short_vals != rhs.__isset.short_vals)
      return false;
    else if (__isset.short_vals && !(short_vals == rhs.short_vals))
      return false;
    if (__isset.int_vals != rhs.__isset.int_vals)
      return false;
    else if (__isset.int_vals && !(int_vals == rhs.int_vals))
      return false;
    if (__isset.long_vals != rhs.__isset.long_vals)
      return false;
    else if (__isset.long_vals && !(long_vals == rhs.long_vals))
      return false;
    if (__isset.double_vals != rhs.__isset.double_vals)
      return false;
    else if (__isset.double_vals && !(double_vals == rhs.double_vals))
      return false;
    if (__isset.string_vals != rhs.__isset.string_vals)
      return false;
    else if (__isset.string_vals && !(string_vals == rhs.string_vals))
      return false;
    if (__isset.binary_vals != rhs.__isset.binary_vals)
      return false;
    else if (__isset.binary_vals && !(binary_vals == rhs.binary_vals))
      return false;
    return true;
  }
  bool operator != (const TColumnData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumnData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TColumnData &a, TColumnData &b);


class TResultSetMetadata {
 public:

  static const char* ascii_fingerprint; // = "9844D65221B9D9152C1984B941D08BBB";
  static const uint8_t binary_fingerprint[16]; // = {0x98,0x44,0xD6,0x52,0x21,0xB9,0xD9,0x15,0x2C,0x19,0x84,0xB9,0x41,0xD0,0x8B,0xBB};

  TResultSetMetadata() {
  }

  virtual ~TResultSetMetadata() throw() {}

  std::vector< ::memanager::TColumn>  columns;

  void __set_columns(const std::vector< ::memanager::TColumn> & val) {
    columns = val;
  }

  bool operator == (const TResultSetMetadata & rhs) const
  {
    if (!(columns == rhs.columns))
      return false;
    return true;
  }
  bool operator != (const TResultSetMetadata &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TResultSetMetadata & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TResultSetMetadata &a, TResultSetMetadata &b);


class TResultSet {
 public:

  static const char* ascii_fingerprint; // = "1362716866A6FEEEE411C44C41CC0015";
  static const uint8_t binary_fingerprint[16]; // = {0x13,0x62,0x71,0x68,0x66,0xA6,0xFE,0xEE,0xE4,0x11,0xC4,0x4C,0x41,0xCC,0x00,0x15};

  TResultSet() {
  }

  virtual ~TResultSet() throw() {}

  std::vector<TResultRow>  rows;
  TResultSetMetadata schema;

  void __set_rows(const std::vector<TResultRow> & val) {
    rows = val;
  }

  void __set_schema(const TResultSetMetadata& val) {
    schema = val;
  }

  bool operator == (const TResultSet & rhs) const
  {
    if (!(rows == rhs.rows))
      return false;
    if (!(schema == rhs.schema))
      return false;
    return true;
  }
  bool operator != (const TResultSet &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TResultSet & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TResultSet &a, TResultSet &b);

} // namespace

#endif
