/*
  author:cyongli
  date:2014-05-20
  the cpp is to set table meta
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include "set_tbmeta.h"
using namespace std;

namespace memanager{
  bool createTableMeta(TTable& tb){
    tb.__set_tbl_name("hello");
    tb.__set_access_level(TAccessLevel::type::READ_WRITE);
    vector<TColumn> columns;
    TColumn tmpCol;
    TColumnType colType;
    colType.__set_type(TPrimitiveType::type::STRING);
    tmpCol.__set_columnName("usrname");
    tmpCol.__set_columnType(colType);
    columns.push_back(tmpCol);

    colType.__set_type(TPrimitiveType::type::INT);
    tmpCol.__set_columnName("age");
    tmpCol.__set_columnType(colType);
    columns.push_back(tmpCol);

    tb.__set_columns(columns);
  
    return true;
  }

  bool setSchema(TResultSet& set,
		 TTable& tb)
  {

    TResultSetMetadata schema;
    schema.__set_columns(tb.columns);
    set.__set_schema(schema);
  
    return true;
  }
}

