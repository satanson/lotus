
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include "print_data.h"
using namespace std;

namespace memanager{

  bool printTableMeta(TResultSet& set,
		      TTable& tb)
  {
    cout<<left;
    cout<<"table name:"<<tb.tbl_name<<"\x20"<<endl;
    vector<TColumn>::iterator it;
    for(it=tb.columns.begin();it!=tb.columns.end();it++){
      cout<<setw(20)<<(*it).columnName<<"\x20";
    }
    cout<<endl;

    return true;
  }

  bool printTableRow(TResultSet& set){
    vector<TResultRow>::iterator setIt;
    for(setIt=set.rows.begin();setIt!=set.rows.end();setIt++){
      vector<TColumnValue>::iterator colIt;
      vector<TColumn>::iterator cIt = set.schema.columns.begin();

      for(colIt=(*setIt).colVals.begin();colIt!=(*setIt).colVals.end();colIt++){
	switch((*cIt).columnType.type){
	case TPrimitiveType::STRING :
	  cout<<setw(20)<<(*colIt).string_val<<"\x20";
	  break;
	case TPrimitiveType::INT :
	  cout<<setw(20)<<(*colIt).int_val<<"\x20";
	  break;
	}
	cIt++;
      }
    	cout<<endl;
    }
    return true;
  }
}

