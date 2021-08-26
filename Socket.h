#pragma once
#include "msg.pb.h"
#include "Macro.h"
#include <sys/socket.h>
#include <unistd.h>

using namespace google::protobuf::io;
class Socket {
	public:
		Socket();
		Socket(int nSocket);

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

		int GetSocketNum();

	private:
		int _socket;
};
