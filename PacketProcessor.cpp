#include "PacketProcessor.h"
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

void PacketProcessor::Run(int nSize) {
	_pthreads.resize(nSize);
	for (int i = 0; i< nSize; ++i) {
		_pthreads.at(i).reset(new thread([=](){
					this->Work();
					}));
	}
}


void PacketProcessor::Work() {
	while(1) {
		Connection* con = CompletionQue::GetInstance()->Get();		
		printf("onWork : %d\n", con->GetSocket());
		char buf[BUF_SIZE];
		int size = __ReadPacketBuf(con->GetSocket(), buf, BUF_SIZE);
		if (size == 0)	{
			con->Close();
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
		switch (packetType) {
			case C_LOGIN:
				{
					game::c_login payload;
					parseSuccess = payload.ParseFromCodedStream(&coded_input);
					packet.SetData((void *)&payload);
					packet.SetConnection(con);
					con->OnPacket(packet);
					//func(packet);
				}
				break;

			case C_CHAT:
				{
					game::chat_message payload;
					parseSuccess = payload.ParseFromCodedStream(&coded_input);
					packet.SetData((void *)&payload);
					packet.SetConnection(con);
					con->OnPacket(packet);
					//func(packet);
				}
		}
	}
}

void PacketProcessor::__close(int socket)
{
	//epoll_ctl(nEpollFd, EPOLL_CTL_DEL, socket, NULL);
	//close(socket);
	printf("close connect\n");
}

int PacketProcessor::__ReadPacketBuf(int socket, char* buf, const int bufSize)
{
	while (1){
		//read Head
		const int headerSize = 8;
		if (!__readSocket(socket, buf, headerSize)){
			return 0;
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

		if (!__readSocket(socket, buf + headerSize, packetSize)){
			printf("read Body Fail %d\n", socket);
			return 0;
		}

		return packetSize + headerSize;
	}
}

bool PacketProcessor::__readSocket(int socket, char* buf, int size)
{
	printf("read Start %d : %d \n", socket, size);
	int readLen = read(socket, buf, size);
	printf("read end %d : %d \n", socket, readLen);

	if (readLen==0) {
		__close(socket);
		return false;
	}	

	if (readLen<0 && errno == EAGAIN) {
		return false;
	}

	if (readLen < 0) {
		__close(socket);
		return false;
	}

	return true;
}

void PacketProcessor::Join() {
	for (int i = 0; i< _pthreads.size(); ++i) {
		_pthreads.at(i)->join();
	}
}

google::protobuf::uint32 PacketProcessor::__readHeader(char *buf)
{
	google::protobuf::uint32 size;
	google::protobuf::io::ArrayInputStream ais(buf,4);
	CodedInputStream coded_input(&ais);
	coded_input.ReadVarint32(&size);
	printf("	sizeof payload %d\n", size);
	return size;
}

void PacketProcessor::__readPacket(char* buf, google::protobuf::uint32 bodySize)
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

