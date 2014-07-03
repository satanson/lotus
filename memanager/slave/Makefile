
HDFS_INCLUDE=${HADOOP_PREFIX}/src/c++/libhdfs
THRIFT_GEN=../gen-cpp
CPPFLAGS=-I${HDFS_INCLUDE} -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${THRIFT_GEN}
LIBHDFS= -L/home/chaoyli/hadoop/c++/Linux-amd64-64/lib
LIBJAVA= -L${JAVA_HOME}/jre/lib/amd64/server/

SER_OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
CXX = g++ -std=c++11
BUILD_DIR=${THRIFT_GEN}/build-in.o

all: recv_block_info

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
recv_block_info: ${SER_OBJS}
	$(CXX) $^ ${BUILD_DIR} -o $@ $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -lcrypto -lthrift
clean:
	rm -rf *.o recv_block_info
