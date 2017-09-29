#pragma once
#include<iostream>
using namespace std;

#include<list>

template<class T, class Que = list<T>>
class Queue
{
public:
	Queue()
	{}
	void push(const T& data)
	{
		_q.push_back(data);
	}
	void pop()
	{
		_q.pop_front();
	}
	T front()
	{
		return _q.front();
	}
	bool Empty()
	{
		return _q.empty();
	}

private:
	Que _q;
};

void TestQueue()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();


}