#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>

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

template<class T>
bool CheckStack(T* arrin,T* arrout,size_t lenin,size_t lenout)
{
	assert(arrin);
	assert(arrout);
	if (lenin != lenout)
		return false;
	Stack<T> s;
	size_t i = 0;
	size_t j = 0;
	while (i < lenin)
	{
		s.Push(arrin[i]);
		++i;
		if (s.Top() == arrout[j])
		{
			s.Pop();
			++j;
		}
	}
	while (!s.Empty())
	{
		if (s.Top() == arrout[j])
		{
			s.Pop();
			++j;
		}
		else
		{
			return false;
		}
	}
	if (j > lenout)
	{
		return false;
	}
	return true;
}



void TestCheckStack()
{
	int arrin[] = {1,2,3,4,5};
	int arrout[] = {1,5,3,2,4};
	if (CheckStack(arrin, arrout, 5, 5))
		cout << "true"<<endl;
	else
		cout << "false"<<endl;
}




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