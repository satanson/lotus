
namespace cpp memanager

include "Types.thrift"
include "Table.thrift"

struct TRowBatch {
  // total number of rows contained in this batch
  1: required i32 num_rows

  // row composition
  2: required list<Types.TTupleId> row_tuples

  // There are a total of num_rows * num_tuples_per_row offsets
  // pointing into tuple_data.
  // An offset of -1 records a NULL.
  3: list<i32> tuple_offsets

  // binary tuple data
  // TODO: figure out how we can avoid copying the data during TRowBatch construction
  4: string tuple_data

  // Indicates whether tuple_data is snappy-compressed
  5: bool is_compressed
}

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

struct TResultRow {
  1: list<TColumnValue> colVals
}

// A union over all possible return types for a column of data
// Currently only used by ExternalDataSource types
struct TColumnData {
  // One element in the list for every row in the column indicating if there is
  // a value in the vals list or a null.
  1: required list<bool> is_null;

  // Only one is set, only non-null values are set.
  2: optional list<bool> bool_vals;
  3: optional list<byte> byte_vals;
  4: optional list<i16> short_vals;
  5: optional list<i32> int_vals;
  6: optional list<i64> long_vals;
  7: optional list<double> double_vals;
  8: optional list<string> string_vals;
  9: optional list<binary> binary_vals;
}

struct TResultSetMetadata {
  1: required list<Table.TColumn> columns
}

// List of rows and metadata describing their columns.
struct TResultSet {
  1: required list<TResultRow> rows;
  2: required TResultSetMetadata schema;
}

service trans_data{
  void trans_data(1:TResultSet resultSet,2:Table.TTable tb);
}
