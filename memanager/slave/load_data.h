/*
  author:cyongli
  date:2014-05-20
  the cpp is to load table data
*/
#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "Data_types.h"
#include "hdfs.h"
using namespace std;

namespace memanager{
  
  bool load_hdfs(TResultSet& set);
     /*hdfs中读取文件插入到表中*/ 

  bool load_local(TResultSet& set);
    /*从本地磁盘读取文件插入到表中*/
}

#endif
