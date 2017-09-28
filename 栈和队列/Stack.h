#pragma once
#include<iostream>
using namespace std;
#include<vector>

template<class T,class Sta = vector<T>>
class Stack
{
public:
	Stack()
	{}

	void Push(const T& data)
	{
		_s.push_back(data);
	}

	void Pop()
	{
		_s.pop_back();
	}

	T Top()
	{
		return _s.back();
	}

	bool Empty()
	{
		return _s.empty();
	}

private:
	Sta _s;
};

//void TestStack()
//{
//	Stack<int> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(4);
//	s.Push(5);
//	s.Push(3);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//}