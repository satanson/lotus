/* this cpp is to organize data by key*/
#ifndef ORGANIZE_DATA_HPP
#define ORGANIZE_DATA_HPP

#include<thrift/protocol/TBinaryProtocol.h>
#include<thrift/transport/TSocket.h>
#include<thrift/transport/TTransportUtils.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

#include "hdfs.h"
#include "Table_types.h"
#include "trans_table_row.h"
#include "consistent.hpp"
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
	void trans_record(const string &host, const TTableRow &row);
    private:
	string readPath;
	int32_t offset;
	int64_t blockSize;
	string storeHost;
	char* buffer;
	Consistent::HashRing<string,string> *ring;
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
	ring = new Consistent::HashRing<string,string>(4);
	std::vector<string> host;
	ring->AddNode("localhost");
	ring->AddNode("127.0.0.1");
	ring->AddNode("chaoyli");
	ring->AddNode("ip6-localhost");
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
	hdfsCloseFile(fs, readFile);
	hdfsDisconnect(fs);

	//vector<TTableRow> rows;
	TColumnValue cval;
	string username;
	string age;
	int64_t i=0;
	int64_t k=0;
	while(buffer[k]!='\0'){
	    for(; buffer[k]!='|'; ++k);
	    username.append(buffer,k,k-i);
	    i = ++k;
	    for(; buffer[k]!='\n'; ++k);
	    age.append(buffer,k,k-i);
	    i = ++k;
	    TTableRow row;
	    cval.__set_string_val(username);
	    row.colVals.push_back(cval);
	    cval.__set_int_val(stoi(age));
	    row.colVals.push_back(cval);
	    username.clear();
	    age.clear();
	    string host = ring->GetNode(row.colVals.front().string_val);
	    trans_record(host,row);
	}
	return true;
    }

    void organize_data::trans_record(const string &host, const TTableRow &row){
	boost::shared_ptr<TTransport> socket(new TSocket(host,9192));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	memanager::trans_table_rowClient client(protocol);
	
	try{
	    transport->open();
	    client.trans_table_row(row);
	    transport->close();
	} catch(TException &tx){
	    cerr << "ERROR: %s\n" << tx.what() << endl;
	}
    }

    // bool organize_data::read_block(){
    // 	hdfsFS fs = hdfsConnect("localhost", 9300);
    // 	if(!fs){
    // 	    cerr << "Oops! Failed to connect to hdfs!" << endl;
    // 	}
    // 	hdfsFile readFile = hdfsOpenFile(fs, readPath.c_str(), O_RDONLY, 0, 0, 0);
    // 	tSize num_read_bytes = hdfsPread(fs,readFile,0,(void*)buffer,blockSize);
    // 	cout << "num_read_bytes" << num_read_bytes << endl;
    // 	cout << buffer << endl;
    // 	hdfsCloseFile(fs, readFile);
    // 	hdfsDisconnect(fs);
	
    // 	return true;
    // }
   
}

#endif //ORGANIZE_DATA_HPP
