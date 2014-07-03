/*
  author:lichaoyong
  date:2014-05-20
  the cpp is to load table data from localFS or HDFS
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<cstdint>
#include "load_data.h"
using namespace std;

namespace memanager{
  
  bool load_hdfs(TResultSet& set)
     /*hdfs中读取文件插入到表中*/ 
  {
    hdfsFS fs = hdfsConnect("localhost", 9300);
    if(!fs) {
      fprintf(stderr,"Oops! Failed to connect to hdfs!\n");
      exit(-1);
    } 
 
    const char* readPath = "/tmp/table.tbl";
    hdfsFile readFile = hdfsOpenFile(fs, readPath, O_RDONLY, 0, 0, 0);
    static char buffer[40000];
    tSize num_read_bytes = hdfsPread(fs,readFile,0,(void*)buffer,sizeof(buffer));
    hdfsCloseFile(fs, readFile);
    hdfsDisconnect(fs);
    //fprintf(stderr,"%s\n",buffer);
    //cout<<buffer<<endl;
    vector<TResultRow> rows;
    TColumnValue cval;
    string username;
    string age;
    int64_t i = 0;
    int64_t k = 0;
    while(buffer[k]!=0x0){
      while(buffer[k] != 0x7c){
		/*0x7c就是竖线'|'*/
			k++;
	  }
	  username.append(buffer,i,k-i);
	  i = ++k;
	  while(buffer[k] != 0xa){
			k++;
	  }
	  age.append(buffer,i,k-i);
	  i = ++k;
	  TResultRow row;
	  cval.__set_string_val(username);
	  row.colVals.push_back(cval);
      cval.__set_int_val(atoi(age.c_str()));
      row.colVals.push_back(cval);
      rows.push_back(row);
      //cout<<username<<'\x20'<<age<<endl;
      username.clear();
      age.clear();
    }
    set.__set_rows(rows);
    return true;

  }
 
  bool load_local(TResultSet& set){
    /*从本地磁盘读取文件插入到表中*/
    vector<TResultRow> rows;
    TResultRow row;
    TColumnValue cval;
    ifstream file("table.tbl",ios::in|ios::out);
    string username;
    int age;
    while(file.peek()!=EOF){
      file>>username>>age;
      TResultRow row;
      cval.__set_string_val(username);
      row.colVals.push_back(cval);
      cval.__set_int_val(age);
      row.colVals.push_back(cval);
      rows.push_back(row);
    }
 
    set.__set_rows(rows);
    return true;
  }

}

