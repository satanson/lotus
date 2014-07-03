/*
  master接收slaver节点传来的缓存信息
 */

#include "trans_data.h"
#include "print_data.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace ::memanager;

class trans_dataHandler : virtual public trans_dataIf {
 public:
  trans_dataHandler() {  }

  void trans_data(const TResultSet& resultSet, const TTable& tb) {
    printTableMeta(const_cast<TResultSet&>(resultSet),const_cast<TTable&>(tb));
    printTableRow(const_cast<TResultSet&>(resultSet));
    printf("trans_data\n\n");
  }

};

int main(int argc, char **argv) {
  int port = 9190;
  boost::shared_ptr<trans_dataHandler> handler(new trans_dataHandler());
  boost::shared_ptr<TProcessor> processor(new trans_dataProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

