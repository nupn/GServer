#pragma once
#include <stdio.h>
#include <mutex>
#include <list>
#include <condition_variable>
#include <atomic>
#include "Singletone.h"
#include <utility>
#include "Connection.h"
using namespace std;


class CompletionQue : public Singletone<CompletionQue> {
	public:
		CompletionQue() noexcept = default;
		void Add(Connection* p)
		{//move지원하도록 변경
			unique_lock<mutex> lock(_lock);
			_values.push_back(p);
			_cond.notify_one();
		}

		Connection* Get() {

			unique_lock<mutex> lock(_lock);
			while (_values.empty()){
				_cond.wait(lock);
			}

			auto ret = _values.front();	
			_values.pop_front();
			return ret;
		}

		bool isEmpty() {
			unique_lock<mutex> lock(_lock);
			return _values.empty();
		}

	private:
		list<Connection *>	_values;
		mutex		_lock;
		condition_variable _cond;
};
