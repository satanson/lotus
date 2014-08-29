
namespace cpp memanager

include "Types.thrift"
include "TSchema.thrift"

// this is a union over all possible return types
struct TColumnValue {
  1: optional bool bool_val
  6: optional byte byte_val
  7: optional i16 short_val
  2: optional i32 int_val
  3: optional i64 long_val
  4: optional double double_val
  5: optional string string_val
  8: optional binary binary_val
}

struct TTableRow {
  1: list<TColumnValue> colVals
}

// List of rows and metadata describing their columns.
struct TTable {
  1: required list<TTableRow> rows;
  2: required TSchema.TTableSchema schema;
}

service trans_table_row{
  void trans_table_row(1:TTableRow tbRow);
}

service trans_table_data{
  void trans_table_data(1:TTable tb);
}
