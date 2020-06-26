#pragma once
#include <string>
#include "User.h"
#include "Config.h"
#include <sys/socket.h>
#include <unistd.h>

#include "msg.pb.h"
using namespace google::protobuf::io;

class Connection {
	public:
		Connection(){};
		virtual ~Connection(){};

		void SetSocket(int socket);
		int GetSocket();

		void SetUser(User user);
		User* GetUser();

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
		User _player;
};


using ConnectionPtr=std::shared_ptr<Connection>;
