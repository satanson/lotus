#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include "hdfs.h"
#include "consistent.h"
using std::string;
using std::cout;
using std::cerr;
using std::endl;

bool distribute_file(const string& readPath,std::vector<int>& block){
    hdfsFS fs = hdfsConnect("localhost",9300);
    int exists = hdfsExists(fs,readPath.c_str());
    if(exists){
	cout<<"Failed to validate the existence of " << readPath << endl;
	exit(EXIT_FAILURE);
    }
    hdfsFileInfo* fileInfo = hdfsGetPathInfo(fs,readPath.c_str());
    if(fileInfo == NULL){
	cout << "Failed to get info of file " << readPath << endl;
    }

    int64_t blockSize = fileInfo->mBlockSize;
    int blocknum = 1+(fileInfo->mSize) / blockSize;
    hdfsFreeFileInfo(fileInfo,1);

    //int slaver_num = 5;
    //std::vector<int> block1;
    // for(int i=0;i<blocknum;i++)
    // 	block1.push_back(i);
    
    Consistent::HashRing<std::string, std::string> ring(4);
    std::vector<std::string> host;
    for(int i=1;i<=1;i++){
	ring.AddNode("localhost"+std::to_string(i));
	//std::cout<<"localhost"+std::to_string(i)<<std::endl;
    }
    
    for(int i = 0; i < blocknum; i++){
    string host = ring.GetNode(readPath + std::to_string(i));
    //    cout<< "Storing " << readPath+std::to_string(i) << " on server " << host<<endl;
    block.push_back(i);
    }
    
    return true;

}
