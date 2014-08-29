
namespace cpp memanager

include "Types.thrift"

struct TColumn {
  1: required string columnName
  2: required Types.TColumnType columnType
  3: optional string comment
  // Ordinal position in the source table
  4: optional i32 position
}

// Represents a table or view.
struct TTableSchema {

  // Unqualified table name. Case insensitive, expected to be stored as lowercase.
  1: required string tbl_name

  // Set if there were any errors loading the Table metadata. The remaining fields in
  // the struct may not be set if there were problems loading the table metadata.
  // By convention, the final error message in the Status should contain the call stack
  // Table identifier.
  2: optional Types.TTableId id

  // List of columns (excludes clustering columns)
  3: optional list<TColumn> columns
 
}
