
#include<thrift/protocol/TBinaryProtocol.h>
#include<thrift/transport/TSocket.h>
#include<thrift/transport/TTransportUtils.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <vector>
#include <thread>
#include "hdfs.h"
#include "consistent.h"
#include "trans_blockInfo.h"
using std::string;
using std::cout;
using std::cerr;
using std::endl;


namespace memanager {

    class dist_file{
    public:
	dist_file();
	~dist_file () { delete ring; }
        dist_file (const dist_file&) = delete;
	dist_file& operator = (const dist_file&) = delete;

	bool init(const string& filePath);
	void trans_blockInfo(const string& host, const memanager::blockInfo& block);
	bool distribute_file(const string& readPath);
    private:
	int64_t blockSize;
	int32_t blockNum;
	Consistent::HashRing<string, string>* ring;
    };
    
    dist_file::dist_file(){
	ring = new Consistent::HashRing<string, string>(4);
	std::vector<std::string> host;
	ring->AddNode("localhost");
	ring->AddNode("127.0.0.1");
	ring->AddNode("chaoyli");
	ring->AddNode("ip6-localhost");
	// for(int i=1;i<=5;i++){
	//     ring->AddNode("localhost"+std::to_string(i));
	//     //std::cout<<"localhost"+std::to_string(i)<<std::endl;
	// }
    }

    bool dist_file::init(const string& readPath){
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

	blockSize = fileInfo->mBlockSize;
	blockNum = 1+(fileInfo->mSize) / blockSize;
	hdfsFreeFileInfo(fileInfo,1);
	
	return true;

    }
    
    void dist_file::trans_blockInfo(const string& host, const memanager::blockInfo& block){

	boost::shared_ptr<TTransport> socket(new TSocket(host,9191));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	memanager::trans_blockInfoClient client(protocol);

	try{
	    transport->open();
	    client.trans_blockInfo(block);
	    transport->close();
	} catch (TException& tx){
	    cout << "ERROR: %s\n" << tx.what() << endl;
	}
	
    }

    bool dist_file::distribute_file(const string& readPath){
	memanager::blockInfo block;
	block.__set_filePath(readPath);
	block.__set_blockSize(this->blockSize);
	cout << "the blockNums of " << readPath << " is " << this->blockNum << endl;
	for(int i = 0; i < this->blockNum; i++){
	    string host = ring->GetNode(readPath + std::to_string(i));
    	    cout << "Storing " << readPath+std::to_string(i) << " on server " << host << endl;
	    block.__set_offset(i);
	    block.__set_storeHost(host);
	    std::thread t(&dist_file::trans_blockInfo, this, host, block);
	    t.join();
	    //t.detach();
	}

    }
    
}

int main(int argc, char*argv[]){

    memanager::dist_file fi;
    fi.init(argv[1]);
    fi.distribute_file(argv[1]);
    
    return 0;
}
