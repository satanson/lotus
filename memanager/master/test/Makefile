
HDFS_INCLUDE=${HADOOP_PREFIX}/src/c++/libhdfs
THRIFT_GEN=../gen-cpp
CPPFLAGS=-I${HDFS_INCLUDE} -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${THRIFT_GEN}
LIBHDFS= -L/home/chaoyli/hadoop/c++/Linux-amd64-64/lib
LIBJAVA= -L${JAVA_HOME}/jre/lib/amd64/server/

SER_OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
CXX = g++ -std=c++11
BUILD_DIR=${THRIFT_GEN}/build-in.o

all: master

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
master: ${SER_OBJS}
	$(CXX) $^ ${BUILD_DIR} $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -o $@ -lthrift
clean:
	rm -rf *.o master
