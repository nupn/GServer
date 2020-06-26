CC=g++
TARGET=a.out
SRC=$(wildcard *.cpp) $(wildcard *.cc)
OBJ=$(SRC:.cpp=.o)
CXXFLAGS=-std=c++17 -c -pthread -lprotoc `pkg-config --cflags --libs protobuf`

LIB_DIR=-L/home/ubuntu/work/libnp/libnp/Common
LIB_INC=-I/home/ubuntu/work/libnp/libnp/Common


$(TARGET): $(OBJ)
	$(CC) -std=c++17 -pthread -lprotoc -o $(TARGET) $(OBJ) `pkg-config --cflags --libs protobuf`

.cpp.o:
	$(CC) -c -std=c++17 -pthread -lprotoc `pkg-config --cflags --libs protobuf` -lnp $(LIB_INC) $(LIB_DIR) $(SRC)

.cc.o:
	$(CC) -c -std=c++17 -pthread -lprotoc `pkg-config --cflags --libs protobuf` -lnp $(LIB_INC) $(LIB_DIR) $(SRC)


clean:
	rm -f $(TARGET)
