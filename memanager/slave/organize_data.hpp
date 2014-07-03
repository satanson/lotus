
#ifndef ORGANIZE_DATA_HPP
#define ORGANIZE_DATA_HPP

#include "hdfs.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
using std::string;

namespace memanager{

    class organize_data{
    public:
	organize_data(const string& readPath, const int32_t& offset,
		      const int64_t& blockSize, const string& storeHost);
	~organize_data();
	bool read_block();
	bool hash_record();
    private:
	string readPath;
	int32_t offset;
	int64_t blockSize;
	string storeHost;
	char* buffer;
	organize_data (const organize_data& ) = delete;
	organize_data& operator= ( const organize_data& ) = delete;
    };

    organize_data::organize_data(const string& readPath, const int32_t& offset, 
				 const int64_t& blockSize, const string& storeHost)
 	:readPath(readPath),
	 offset(offset),
	 blockSize(blockSize),
	 storeHost(storeHost)
    {  
	buffer = new char[blockSize];
    }

    organize_data::~organize_data(){
	delete [] buffer;
    }

    bool organize_data::read_block(){
	hdfsFS fs = hdfsConnect("localhost", 9300);
	if(!fs){
	    cerr << "Oops! Failed to connect to hdfs!" << endl;
	}
	hdfsFile readFile = hdfsOpenFile(fs, readPath.c_str(), O_RDONLY, 0, 0, 0);
	tSize num_read_bytes = hdfsPread(fs,readFile,0,(void*)buffer,blockSize);
	cout << "num_read_bytes" << num_read_bytes << endl;
	cout << buffer << endl;
	hdfsCloseFile(fs, readFile);
	hdfsDisconnect(fs);
	
	return true;
    }
   
    bool organize_data::hash_record(){
	return true;
    }

}

#endif //ORGANIZE_DATA_HPP
