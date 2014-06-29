
namespace cpp memanager

include "Status.thrift"
include "Types.thrift"

// The access level that is available to Impala on the Catalog object.
enum TAccessLevel {
  NONE,
  READ_WRITE,
  READ_ONLY,
  WRITE_ONLY,
}

struct TTableStats {
  // Estimated number of rows in the table or -1 if unknown
  1: required i64 num_rows;
}

// Column stats data that Impala uses.
struct TColumnStats {
  // Average size and max size, in bytes. Excludes serialization overhead.
  // For fixed-length types (those which don't need additional storage besides the slot
  // they occupy), sets avg_size and max_size to their slot size.
  1: required double avg_size
  2: required i64 max_size

  // Estimated number of distinct values.
  3: required i64 num_distinct_values

  // Estimated number of null values.
  4: required i64 num_nulls
}

struct TColumn {
  1: required string columnName
  2: required Types.TColumnType columnType
  3: optional string comment
  // Stats for this table, if any are available.
  4: optional TColumnStats col_stats
  // Ordinal position in the source table
  5: optional i32 position
}

// Represents a table or view.
struct TTable {

  // Unqualified table name. Case insensitive, expected to be stored as lowercase.
  1: required string tbl_name

  // Set if there were any errors loading the Table metadata. The remaining fields in
  // the struct may not be set if there were problems loading the table metadata.
  // By convention, the final error message in the Status should contain the call stack
  // string pointing to where the metadata loading error occurred.
  2: optional Status.TStatus load_status

  // Table identifier.
  3: optional Types.TTableId id

  // The access level Impala has on this table (READ_WRITE, READ_ONLY, etc).
  4: optional TAccessLevel access_level

  // List of columns (excludes clustering columns)
  5: optional list<TColumn> columns

  // List of clustering columns (empty list if table has no clustering columns)
  6: optional list<TColumn> clustering_columns

  // Table stats data for the table.
  7: optional TTableStats table_stats

  // Set iff this is a table from an external data source
 
}
