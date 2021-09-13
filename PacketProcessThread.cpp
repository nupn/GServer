#include "PacketProcessThread.h"
#include "Server.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/socket.h>
#include "msg.pb.h"
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "CompletionQue.h"
#include "Packet.h"
#include "protocol.h"

using namespace std;
using namespace google::protobuf::io;
#define BUF_SIZE 512

void PacketProcessThread::Run(int nSize) {
	_pthreads.resize(nSize);
	for (int i = 0; i< nSize; ++i) {
		_pthreads.at(i).reset(new thread([=](){
					this->Work();
					}));
	}
}


void PacketProcessThread::Work() {
	while(1) {
		UserPtr user = CompletionQue::GetInstance()->Get();		
		printf("onWork : %d\n", user->GetSocket());
		char buf[BUF_SIZE];

		const int READ_END = -1;
		int size = __ReadPacket(user->GetSocket(), buf, BUF_SIZE);
		if (size == 0)	{
			user->CloseConnection();
			continue;
		}

		if (size == READ_END) {
			continue;
		}

		Packet packet;
		google::protobuf::io::ArrayInputStream ais(buf, size);
		CodedInputStream coded_input(&ais);

		google::protobuf::uint32 packetType;
		coded_input.ReadVarint32(&packetType);
		packet.SetType(packetType);

		google::protobuf::uint32 packetSize;
		coded_input.ReadVarint32(&packetSize);

		bool parseSuccess = false;
		google::protobuf::io::CodedInputStream::Limit msgLimit = coded_input.PushLimit(packetSize);
		printf("on Packet %d\n", packetType);
		switch (packetType) {
			case C_LOGIN:
				{
					game::c_login payload;
					parseSuccess = payload.ParseFromCodedStream(&coded_input);
					packet.SetData((void *)&payload);
					user->OnPacket(packet);
					//func(packet);
				}
				break;

			case C_CHAT:
				{
					game::chat_message payload;
					parseSuccess = payload.ParseFromCodedStream(&coded_input);
					packet.SetData((void *)&payload);
					user->OnPacket(packet);
					//func(packet);
				}
				break;
		}
	}
}

int PacketProcessThread::__ReadPacket(int socket, char* buf, const int bufSize)
{
	while (1){
		//read Head
		const int headerSize = 8;
		int readLen = __ReadSocket(socket, buf, headerSize);
		if (readLen <= 0) {
			return readLen;
		}

		google::protobuf::io::ArrayInputStream ais(buf, headerSize);
		CodedInputStream coded_input(&ais);

		google::protobuf::uint32 type;
		coded_input.ReadVarint32(&type);

		google::protobuf::uint32 packetSize;
		coded_input.ReadVarint32(&packetSize);

		if (packetSize + headerSize >= bufSize) {
			printf("invalid packet size %d, %d, %d\n", socket, type, packetSize);
			return 0;
		}

		if (packetSize == 0) {
			return headerSize;
		}

		readLen = __ReadSocket(socket, buf + headerSize, packetSize);
		if (readLen <= 0) {
			printf("read Body Fail socket: %d len: %d\n", socket, readLen);
			return readLen;
		}

		return packetSize + headerSize;
	}
}

int PacketProcessThread::__ReadSocket(int socket, char* buf, int size)
{
	printf("read Start %d : %d \n", socket, size);
	int readLen = read(socket, buf, size);
	printf("read end %d : %d \n", socket, readLen);

	if (readLen == 0) {
		return 0;
	}	

	const int READ_END = -1;
	if (readLen < 0 && errno == EAGAIN) {
		return READ_END;
	}

	if (readLen < 0) {
		return 0;
	}

	return readLen;
}

void PacketProcessThread::Join() {
	for (int i = 0; i< _pthreads.size(); ++i) {
		_pthreads.at(i)->join();
	}
}

google::protobuf::uint32 PacketProcessThread::__readHeader(char *buf)
{
	google::protobuf::uint32 size;
	google::protobuf::io::ArrayInputStream ais(buf,4);
	CodedInputStream coded_input(&ais);
	coded_input.ReadVarint32(&size);
	printf("	sizeof payload %d\n", size);
	return size;
}

void PacketProcessThread::__readPacket(char* buf, google::protobuf::uint32 bodySize)
{
	printf("	packetSize: %d\n",  bodySize);
	google::protobuf::io::ArrayInputStream ais(buf, bodySize +4);
	CodedInputStream coded_input(&ais);

	google::protobuf::uint32 size;
	coded_input.ReadVarint32(&size);

	game::chat_message payload;
	google::protobuf::io::CodedInputStream::Limit msgLimit = coded_input.PushLimit(bodySize);
	if (!payload.ParseFromCodedStream(&coded_input)) {
		printf("	parseFromCodedStream Fail\n");
	}
	coded_input.PopLimit(msgLimit);
	printf("	payload: %d\n",  payload.id());
	printf("	payload: %s\n",  payload.name().c_str());
	printf("	payload: %s\n",  payload.msg().c_str());
}

