/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Table_types.h"

#include <algorithm>

namespace memanager {

int _kTAccessLevelValues[] = {
  TAccessLevel::NONE,
  TAccessLevel::READ_WRITE,
  TAccessLevel::READ_ONLY,
  TAccessLevel::WRITE_ONLY
};
const char* _kTAccessLevelNames[] = {
  "NONE",
  "READ_WRITE",
  "READ_ONLY",
  "WRITE_ONLY"
};
const std::map<int, const char*> _TAccessLevel_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kTAccessLevelValues, _kTAccessLevelNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* TTableStats::ascii_fingerprint = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
const uint8_t TTableStats::binary_fingerprint[16] = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

uint32_t TTableStats::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_num_rows = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->num_rows);
          isset_num_rows = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_num_rows)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TTableStats::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TTableStats");

  xfer += oprot->writeFieldBegin("num_rows", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->num_rows);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TTableStats &a, TTableStats &b) {
  using ::std::swap;
  swap(a.num_rows, b.num_rows);
}

const char* TColumnStats::ascii_fingerprint = "D5FF58B203C57D2B1EF98050D612DB56";
const uint8_t TColumnStats::binary_fingerprint[16] = {0xD5,0xFF,0x58,0xB2,0x03,0xC5,0x7D,0x2B,0x1E,0xF9,0x80,0x50,0xD6,0x12,0xDB,0x56};

uint32_t TColumnStats::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_avg_size = false;
  bool isset_max_size = false;
  bool isset_num_distinct_values = false;
  bool isset_num_nulls = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->avg_size);
          isset_avg_size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->max_size);
          isset_max_size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->num_distinct_values);
          isset_num_distinct_values = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->num_nulls);
          isset_num_nulls = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_avg_size)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_max_size)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_num_distinct_values)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_num_nulls)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TColumnStats::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TColumnStats");

  xfer += oprot->writeFieldBegin("avg_size", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->avg_size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("max_size", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->max_size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("num_distinct_values", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->num_distinct_values);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("num_nulls", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->num_nulls);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TColumnStats &a, TColumnStats &b) {
  using ::std::swap;
  swap(a.avg_size, b.avg_size);
  swap(a.max_size, b.max_size);
  swap(a.num_distinct_values, b.num_distinct_values);
  swap(a.num_nulls, b.num_nulls);
}

const char* TColumn::ascii_fingerprint = "46C7DD290D595CB60E9B67D118AACBA9";
const uint8_t TColumn::binary_fingerprint[16] = {0x46,0xC7,0xDD,0x29,0x0D,0x59,0x5C,0xB6,0x0E,0x9B,0x67,0xD1,0x18,0xAA,0xCB,0xA9};

uint32_t TColumn::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_columnName = false;
  bool isset_columnType = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->columnName);
          isset_columnName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->columnType.read(iprot);
          isset_columnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->comment);
          this->__isset.comment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->col_stats.read(iprot);
          this->__isset.col_stats = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->position);
          this->__isset.position = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_columnName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_columnType)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TColumn::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TColumn");

  xfer += oprot->writeFieldBegin("columnName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->columnName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("columnType", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->columnType.write(oprot);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.comment) {
    xfer += oprot->writeFieldBegin("comment", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->comment);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.col_stats) {
    xfer += oprot->writeFieldBegin("col_stats", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->col_stats.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.position) {
    xfer += oprot->writeFieldBegin("position", ::apache::thrift::protocol::T_I32, 5);
    xfer += oprot->writeI32(this->position);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TColumn &a, TColumn &b) {
  using ::std::swap;
  swap(a.columnName, b.columnName);
  swap(a.columnType, b.columnType);
  swap(a.comment, b.comment);
  swap(a.col_stats, b.col_stats);
  swap(a.position, b.position);
  swap(a.__isset, b.__isset);
}

const char* TTable::ascii_fingerprint = "8F9D83B52B4DC73301968602CA0884AE";
const uint8_t TTable::binary_fingerprint[16] = {0x8F,0x9D,0x83,0xB5,0x2B,0x4D,0xC7,0x33,0x01,0x96,0x86,0x02,0xCA,0x08,0x84,0xAE};

uint32_t TTable::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_tbl_name = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->tbl_name);
          isset_tbl_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->load_status.read(iprot);
          this->__isset.load_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->access_level = (TAccessLevel::type)ecast0;
          this->__isset.access_level = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->columns.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _etype4;
            xfer += iprot->readListBegin(_etype4, _size1);
            this->columns.resize(_size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              xfer += this->columns[_i5].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.columns = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->clustering_columns.clear();
            uint32_t _size6;
            ::apache::thrift::protocol::TType _etype9;
            xfer += iprot->readListBegin(_etype9, _size6);
            this->clustering_columns.resize(_size6);
            uint32_t _i10;
            for (_i10 = 0; _i10 < _size6; ++_i10)
            {
              xfer += this->clustering_columns[_i10].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.clustering_columns = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->table_stats.read(iprot);
          this->__isset.table_stats = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_tbl_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TTable::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TTable");

  xfer += oprot->writeFieldBegin("tbl_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->tbl_name);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.load_status) {
    xfer += oprot->writeFieldBegin("load_status", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->load_status.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.id) {
    xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->id);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.access_level) {
    xfer += oprot->writeFieldBegin("access_level", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32((int32_t)this->access_level);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.columns) {
    xfer += oprot->writeFieldBegin("columns", ::apache::thrift::protocol::T_LIST, 5);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->columns.size()));
      std::vector<TColumn> ::const_iterator _iter11;
      for (_iter11 = this->columns.begin(); _iter11 != this->columns.end(); ++_iter11)
      {
        xfer += (*_iter11).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.clustering_columns) {
    xfer += oprot->writeFieldBegin("clustering_columns", ::apache::thrift::protocol::T_LIST, 6);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->clustering_columns.size()));
      std::vector<TColumn> ::const_iterator _iter12;
      for (_iter12 = this->clustering_columns.begin(); _iter12 != this->clustering_columns.end(); ++_iter12)
      {
        xfer += (*_iter12).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.table_stats) {
    xfer += oprot->writeFieldBegin("table_stats", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->table_stats.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TTable &a, TTable &b) {
  using ::std::swap;
  swap(a.tbl_name, b.tbl_name);
  swap(a.load_status, b.load_status);
  swap(a.id, b.id);
  swap(a.access_level, b.access_level);
  swap(a.columns, b.columns);
  swap(a.clustering_columns, b.clustering_columns);
  swap(a.table_stats, b.table_stats);
  swap(a.__isset, b.__isset);
}

} // namespace