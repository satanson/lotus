/*
  author:cyongli
  date:2014-05-20
  the cpp is to set table meta
*/

#ifndef SET_TBMETA_H
#define SET_TBMETA_H

#include "Data_types.h"
using namespace std;

namespace memanager{
  bool createTableMeta(TTable& tb);

  bool setSchema(TResultSet& set, TTable& tb);

}

#endif
