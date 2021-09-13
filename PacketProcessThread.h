#pragma once

#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <memory>
#include <thread>
#include <vector>
#include <functional>
#include "Packet.h"
#include "User.h"

using namespace std;
using namespace google::protobuf::io;
class PacketProcessThread {
public:
	void Run(int nSize);
	void Work();
	void Join();

private:
	int __ReadPacket(int socket, char *buf, const int MaxSize);
	int __ReadSocket(int socket, char* buf, int size);


	google::protobuf::uint32 __readHeader(char* buf);
	void __readPacket(char* buf, google::protobuf::uint32 bodySize);
private:
	std::vector<shared_ptr<thread>> _pthreads;
};
