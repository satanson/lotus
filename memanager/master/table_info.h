
#include <map>
#include <cstdlib>
#include<ext/hash_map>
#include <iostream>
#include "Data_type.h"
#include "consistent.h"
#include "hdfs.h"
using std::string;
using std::cout;
using std::endl;

class File_Info{
 public:
    size_t CacheFile(const string& fileName);
    size_t FlushFile(const string& fileName);
 private:
    std::map<string,string> fileTbMap;
};


size_t File_Info::CacheFile(const string& fileName){
    hdfsFs fs = hdfsConnect("localhost",9300);
    const string readPath = "/tmp/"+fileName;
    int exists = hdfsExists(fs,readPath.c_str());
    if(exists){
	cout<<"Failed to validate the existence of " << readPath << endl;
	exit(EXIT_FAILURE);
    }
    hdfsFileInfo* fileInfo = hdfsGetPathInfo(fs,readPath);
    if(fileInfo ! = NULL){
	cout << fileInfo->mName << "\x20";
	cout << fileInfo->mReplication << "\x20";
	cout << fileInfo->mBlockSize << "\x20";
	cout << fileInfo->msize << endl;
    }
    hdfsFreeFileInfo(fileInfo,1);
}
