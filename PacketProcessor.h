#pragma once

#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <memory>
#include <thread>
#include <vector>
#include <functional>
#include "Packet.h"
#include "Connection.h"

using namespace std;
using namespace google::protobuf::io;
class PacketProcessor{
public:
	void Run(int nSize, std::function<void(Packet)> func);
	void Work(std::function<void(Packet)> func);
	void Join();

private:
	void __close(int socket);
	int __ReadPacketBuf(int socket, char *buf, const int MaxSize);
	bool __readSocket(int socket, char* buf, int size);


	google::protobuf::uint32 __readHeader(char* buf);
	void __readPacket(char* buf, google::protobuf::uint32 bodySize);
private:
	std::vector<shared_ptr<thread>> _pthreads;
};
