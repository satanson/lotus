
HDFS_INCLUDE=${HADOOP_PREFIX}/src/c++/libhdfs
THRIFT_GEN=../gen-cpp
CPPFLAGS=-I${HDFS_INCLUDE} -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${THRIFT_GEN}
LIBHDFS= -L/home/chaoyli/hadoop/c++/Linux-amd64-64/lib
LIBJAVA= -L${JAVA_HOME}/jre/lib/amd64/server/

#SER_OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp)) $(patsubst %.hpp,%.o,$(wildcard *.hpp))
SER_RECV_OBJS=recv_block_info.o organize_data.o
CXX = g++ -std=c++11 -Wno-deprecated
BUILD_DIR=${THRIFT_GEN}/build-in.o

all: recv_block_info
	echo ${SER_OBJS}

%.o: %.cpp
	$(CXX) -c $< -o $@ ${CPPFLAGS}
%.o: %.hpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)

recv_block_info: ${SER_RECV_OBJS}
	$(CXX) $^ ${BUILD_DIR} -o $@ $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -lcrypto -lthrift
clean:
	rm -rf *.o recv_block_info
