
HDFS_INCLUDE=${HADOOP_PREFIX}/src/c++/libhdfs
CPPFLAGS=-I./gen-cpp -I${HDFS_INCLUDE} -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux 
LIBHDFS= -L/home/chaoyli/hadoop/c++/Linux-amd64-64/lib
LIBJAVA= -L${JAVA_HOME}/jre/lib/amd64/server/

SER_OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
CXX = g++ -std=c++11 -Wno-deprecated
BUILD_DIR=./gen-cpp/build-in.o

all: dist_file read_block

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)
dist_file: ${SER_OBJS}
	$(CXX) dist_file.o ${BUILD_DIR} -o $@ $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -lcrypto -lthrift
read_block: ${SER_OBJS}
	$(CXX) read_block.o ${BUILD_DIR} -o $@ $(LIBHDFS) -lhdfs $(LIBJAVA) -ljvm -lcrypto -lthrift
clean:
	rm -rf *.o dist_file read_block
