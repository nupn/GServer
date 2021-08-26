#pragma once
#include <stdio.h>
#include <mutex>
#include <list>
#include <condition_variable>
#include <atomic>
#include "Singletone.h"
#include <utility>
#include "User.h"
using namespace std;


class CompletionQue : public Singletone<CompletionQue> {
	public:
		CompletionQue() noexcept = default;
		void Add(UserPtr user)
		{//move지원하도록 변경
			unique_lock<mutex> lock(_lock);
			_values.push_back(user);
			_cond.notify_one();
		}

		UserPtr Get() {

			unique_lock<mutex> lock(_lock);
			while (_values.empty()){
				_cond.wait(lock);
			}

			auto user = _values.front();	
			_values.pop_front();
			return user;
		}

		bool isEmpty() {
			unique_lock<mutex> lock(_lock);
			return _values.empty();
		}

	private:
		list<UserPtr>	_values;
		mutex		_lock;
		condition_variable _cond;
};
