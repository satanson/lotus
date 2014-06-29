namespace cpp memanager

enum TStatusCode {
  OK,
  CANCELLED,
  ANALYSIS_ERROR,
  NOT_IMPLEMENTED_ERROR,
  RUNTIME_ERROR,
  MEM_LIMIT_EXCEEDED,
  INTERNAL_ERROR,
  RECOVERABLE_ERROR
}

struct TStatus {
  1: required TStatusCode status_code
  2: list<string> error_msgs
}
