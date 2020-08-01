#pragma once
#include <string>
#include "Config.h"
#include <sys/socket.h>
#include <unistd.h>
#include "PacketHandler.h"
#include "msg.pb.h"
using namespace google::protobuf::io;

class Connection : public PacketHandler {
	public:
		Connection(){};
		virtual ~Connection(){};

		void SetSocket(int socket);
		int GetSocket();
		void Close();

		template <typename T>
			void SendPacket(int type, T *payload) {
				char sendbuf[BUF_SIZE];
				int sendSize = payload->ByteSizeLong() + 8;

				google::protobuf::io::ArrayOutputStream aos(sendbuf, sendSize);
				CodedOutputStream* coded_output = new CodedOutputStream(&aos);

				coded_output->WriteVarint32(type);
				coded_output->WriteVarint32(payload->ByteSizeLong());

				payload->SerializeToCodedStream(coded_output);
				write(_socket, sendbuf, sendSize);
			}
	private:
		int _socket;
};


using ConnectionPtr=std::shared_ptr<Connection>;
