#pragma once
#include <memory>
#include <string>
#include <list>
#include <sys/socket.h>
#include <unistd.h>
#include "Config.h"
#include "msg.pb.h"
#include "PacketHandler.h"
#include "Match.h"

using namespace google::protobuf::io;
class Process;
class User;
using UserPtr=std::shared_ptr<User>;
using UserWeakPtr=std::weak_ptr<User>;
using UserList=std::list<UserPtr>;

class User : public PacketHandler, public MatchSeed, std::enable_shared_from_this<User>{
public:
	User(int socket);
	int GetSocket() {
		return _socket;
	};

	bool OnPacket(Packet& packet);
	void SetProcess(std::weak_ptr<Process> process);
	std::weak_ptr<Process> GetProcess();

	/*template <typename T>
			void SendPacket(int type, T *payload) {
				_socket.SendPacket<T>(type, payload);
			}*/
	template <typename T>
			void SendPacket(int type, T *payload) {
				char sendbuf[512];
				int sendSize = payload->ByteSizeLong() + 8;

				google::protobuf::io::ArrayOutputStream aos(sendbuf, sendSize);
				CodedOutputStream* coded_output = new CodedOutputStream(&aos);

				coded_output->WriteVarint32(type);
				coded_output->WriteVarint32(payload->ByteSizeLong());

				payload->SerializeToCodedStream(coded_output);
				write(_socket, sendbuf, sendSize);
			}

	
	//for Ma;tch
	virtual bool Equal(const MatchSeedWeakPtr user);
	virtual bool Greater(const MatchSeedWeakPtr user);
	int MatchValue();
	UserPtr GetSharedPtr();

private:
	int _matchValue;
	std::weak_ptr<Process> _process;
	int _socket;
	int _id;
	std::string _name;
};


