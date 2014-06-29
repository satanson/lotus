#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include "hdfs.h"
#include "trans_blockInfo.h"

class trans_blockInfoHandler : virtual public memanager::trans_blockInfoIf {
public:
    trans_blockInfoHandler() { }
    void trans_blockInfo(const memanager::blockInfo& block){
	cout << block.filePath << "\x20";
	cout << block.offset << "\x20";
	cout << block.blockSize << "\x20";
	cout << block.storeHost << endl;
    }
};


int main(int argc, char **argv) {
  int port = 9191;
  boost::shared_ptr<trans_blockInfoHandler> handler(new trans_blockInfoHandler());
  boost::shared_ptr<TProcessor> processor(new memanager::trans_blockInfoProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

// hdfsFS fs = hdfsConnect("localhost",9300);
// static char buffer[67108864];
// int32_t offset = 0;
// for(it=blockList.begin(); it != blockList.end(); it++){
//     hdfsFile readFile = hdfsOpenFile(fs,(*it).filePath.c_str(),O_RDONLY,0,0,0);
//     if(!readFile){
// 	cout << "Failed to open " << (*it).filePath << " for reading!" << endl;
// 	exit(EXIT_FAILURE);
//     }
//     int32_t num_read_bytes = hdfsPread(fs, readFile, offset, (void*)buffer, sizeof(buffer));
//     offset += 67108864;
//     //cout << endl << "offset:" << offset << endl;
//     cout << buffer;
// }
