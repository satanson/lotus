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
#include "Status_types.h"
#include "Types_types.h"


namespace memanager {

struct TAccessLevel {
  enum type {
    NONE = 0,
    READ_WRITE = 1,
    READ_ONLY = 2,
    WRITE_ONLY = 3
  };
};

extern const std::map<int, const char*> _TAccessLevel_VALUES_TO_NAMES;


class TTableStats {
 public:

  static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
  static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

  TTableStats() : num_rows(0) {
  }

  virtual ~TTableStats() throw() {}

  int64_t num_rows;

  void __set_num_rows(const int64_t val) {
    num_rows = val;
  }

  bool operator == (const TTableStats & rhs) const
  {
    if (!(num_rows == rhs.num_rows))
      return false;
    return true;
  }
  bool operator != (const TTableStats &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TTableStats & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TTableStats &a, TTableStats &b);


class TColumnStats {
 public:

  static const char* ascii_fingerprint; // = "D5FF58B203C57D2B1EF98050D612DB56";
  static const uint8_t binary_fingerprint[16]; // = {0xD5,0xFF,0x58,0xB2,0x03,0xC5,0x7D,0x2B,0x1E,0xF9,0x80,0x50,0xD6,0x12,0xDB,0x56};

  TColumnStats() : avg_size(0), max_size(0), num_distinct_values(0), num_nulls(0) {
  }

  virtual ~TColumnStats() throw() {}

  double avg_size;
  int64_t max_size;
  int64_t num_distinct_values;
  int64_t num_nulls;

  void __set_avg_size(const double val) {
    avg_size = val;
  }

  void __set_max_size(const int64_t val) {
    max_size = val;
  }

  void __set_num_distinct_values(const int64_t val) {
    num_distinct_values = val;
  }

  void __set_num_nulls(const int64_t val) {
    num_nulls = val;
  }

  bool operator == (const TColumnStats & rhs) const
  {
    if (!(avg_size == rhs.avg_size))
      return false;
    if (!(max_size == rhs.max_size))
      return false;
    if (!(num_distinct_values == rhs.num_distinct_values))
      return false;
    if (!(num_nulls == rhs.num_nulls))
      return false;
    return true;
  }
  bool operator != (const TColumnStats &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TColumnStats & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(TColumnStats &a, TColumnStats &b);

typedef struct _TColumn__isset {
  _TColumn__isset() : comment(false), col_stats(false), position(false) {}
  bool comment;
  bool col_stats;
  bool position;
} _TColumn__isset;

class TColumn {
 public:

  static const char* ascii_fingerprint; // = "46C7DD290D595CB60E9B67D118AACBA9";
  static const uint8_t binary_fingerprint[16]; // = {0x46,0xC7,0xDD,0x29,0x0D,0x59,0x5C,0xB6,0x0E,0x9B,0x67,0xD1,0x18,0xAA,0xCB,0xA9};

  TColumn() : columnName(), comment(), position(0) {
  }

  virtual ~TColumn() throw() {}

  std::string columnName;
   ::memanager::TColumnType columnType;
  std::string comment;
  TColumnStats col_stats;
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

  void __set_col_stats(const TColumnStats& val) {
    col_stats = val;
    __isset.col_stats = true;
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
    if (__isset.col_stats != rhs.__isset.col_stats)
      return false;
    else if (__isset.col_stats && !(col_stats == rhs.col_stats))
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

typedef struct _TTable__isset {
  _TTable__isset() : load_status(false), id(false), access_level(false), columns(false), clustering_columns(false), table_stats(false) {}
  bool load_status;
  bool id;
  bool access_level;
  bool columns;
  bool clustering_columns;
  bool table_stats;
} _TTable__isset;

class TTable {
 public:

  static const char* ascii_fingerprint; // = "8F9D83B52B4DC73301968602CA0884AE";
  static const uint8_t binary_fingerprint[16]; // = {0x8F,0x9D,0x83,0xB5,0x2B,0x4D,0xC7,0x33,0x01,0x96,0x86,0x02,0xCA,0x08,0x84,0xAE};

  TTable() : tbl_name(), id(0), access_level((TAccessLevel::type)0) {
  }

  virtual ~TTable() throw() {}

  std::string tbl_name;
   ::memanager::TStatus load_status;
   ::memanager::TTableId id;
  TAccessLevel::type access_level;
  std::vector<TColumn>  columns;
  std::vector<TColumn>  clustering_columns;
  TTableStats table_stats;

  _TTable__isset __isset;

  void __set_tbl_name(const std::string& val) {
    tbl_name = val;
  }

  void __set_load_status(const  ::memanager::TStatus& val) {
    load_status = val;
    __isset.load_status = true;
  }

  void __set_id(const  ::memanager::TTableId val) {
    id = val;
    __isset.id = true;
  }

  void __set_access_level(const TAccessLevel::type val) {
    access_level = val;
    __isset.access_level = true;
  }

  void __set_columns(const std::vector<TColumn> & val) {
    columns = val;
    __isset.columns = true;
  }

  void __set_clustering_columns(const std::vector<TColumn> & val) {
    clustering_columns = val;
    __isset.clustering_columns = true;
  }

  void __set_table_stats(const TTableStats& val) {
    table_stats = val;
    __isset.table_stats = true;
  }

  bool operator == (const TTable & rhs) const
  {
    if (!(tbl_name == rhs.tbl_name))
      return false;
    if (__isset.load_status != rhs.__isset.load_status)
      return false;
    else if (__isset.load_status && !(load_status == rhs.load_status))
      return false;
    if (__isset.id != rhs.__isset.id)
      return false;
    else if (__isset.id && !(id == rhs.id))
      return false;
    if (__isset.access_level != rhs.__isset.access_level)
      return false;
    else if (__isset.access_level && !(access_level == rhs.access_level))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    if (__isset.clustering_columns != rhs.__isset.clustering_columns)
      return false;
    else if (__isset.clustering_columns && !(clustering_columns == rhs.clustering_columns))
      return false;
    if (__isset.table_stats != rhs.__isset.table_stats)
      return false;
    else if (__isset.table_stats && !(table_stats == rhs.table_stats))
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
