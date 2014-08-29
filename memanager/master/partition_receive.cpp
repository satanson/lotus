// this cpp is to receive another record from another slave

#include "trans_table_row.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace  ::memanager;

#include "table_partition.hpp"
#include<iostream>
using std::cout;
using std::cerr;
using std::endl;

class trans_table_rowHandler : virtual public trans_table_rowIf {
 public:
  void trans_table_row(const TTableRow& tbRow) {
      table_partition subTable;
      subTable.add(tbRow);
  }

};

int main(int argc, char **argv) {
  int port = 9192;
  shared_ptr<trans_table_rowHandler> handler(new trans_table_rowHandler());
  shared_ptr<TProcessor> processor(new trans_table_rowProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

