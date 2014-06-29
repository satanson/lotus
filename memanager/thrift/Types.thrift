
namespace cpp memanager

typedef i64 TTimestamp
typedef i32 TPlanNodeId
typedef i32 TTupleId
typedef i32 TSlotId
typedef i32 TTableId

enum TPrimitiveType {
  INVALID_TYPE,
  NULL_TYPE,
  BOOLEAN,
  TINYINT,
  SMALLINT,
  INT,
  BIGINT,
  FLOAT,
  DOUBLE,
  DATE,
  DATETIME,
  TIMESTAMP,
  STRING,
  // Unsupported types
  BINARY,
  DECIMAL,
  // CHAR(n). Currently only supported in UDAs
  CHAR,
}

struct TColumnType {
  1: required TPrimitiveType type

  // Only set if type == CHAR
  2: optional i32 len

  // Only set if type == DECIMAL
  3: optional i32 precision
  4: optional i32 scale
}


// Level of verboseness for "explain" output.
enum TExplainLevel {
  MINIMAL,
  STANDARD,
  EXTENDED,
  VERBOSE
}

// A TNetworkAddress is the standard host, port representation of a
// network address. The hostname field must be resolvable to an IPv4
// address.
struct TNetworkAddress {
  1: required string hostname
  2: required i32 port
}

// Wire format for UniqueId
struct TUniqueId {
  1: required i64 hi
  2: required i64 lo
}

