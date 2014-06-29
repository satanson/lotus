
#ifndef PRINT_DATA_H
#define PRINT_DATA_H

#include "Data_types.h"
using namespace std;

namespace memanager{

  bool printTableMeta(TResultSet& set, TTable& tb);

  bool printTableRow(TResultSet& set);

}

#endif
