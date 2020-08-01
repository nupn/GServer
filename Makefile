CC=g++
TARGET=a.out
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
CXXFLAGS=-std=c++17 -c -g -pthread -lprotoc `pkg-config --cflags --libs protobuf`

LIB_DIR=-L/home/ubuntu/work/libnp/libnp/Common
LIB_INC=-I/home/ubuntu/work/libnp/libnp/Common


$(TARGET): $(OBJ) msg.pb.o
	$(CC) -std=c++17 -pthread -lprotoc -g -o $(TARGET) $(OBJ) msg.pb.o `pkg-config --cflags --libs protobuf`

.cpp.o:
	$(CC) -c -g -std=c++17 -pthread -lprotoc `pkg-config --cflags --libs protobuf` -lnp $(LIB_INC) $(LIB_DIR) $(SRC)

msg.pb.o:
	$(CC) -c -g -std=c++17 -pthread -lprotoc `pkg-config --cflags --libs protobuf` -lnp $(LIB_INC) $(LIB_DIR) msg.pb.cc


clean:
	rm -f $(TARGET) $(OBJ)
