#include<iostream>
using namespace std;

struct A
{
	int a;
	int b;
};

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
		,_owner(true)
	{}
	~AutoPtr()
	{
		if (_owner == true)
		delete _ptr;
	}

	//这里应该返回的是一个对象，这里T就是一个对象，然后我们需要改变里面的内容，所以这里返回的应该是T&
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()   //这里相当于是放回了一个指针，然后在使用这个指针指向一个内容
	{
		return _ptr;
	}

	AutoPtr(AutoPtr<T>& p)
		:_ptr(p._ptr)
		, _owner(p._owner)
	{
		p._owner = false;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& p)
	{
		if (&p == this)
		{
			return *this;
		}
		else
		{
			if (_owner = true)
			{
				delete _ptr;
			}
			_ptr = p._ptr;
			_owner = p._owner;
			p._owner = false;
			return *this;
		}
	}
	

private:
	T* _ptr;
	bool _owner;
};

void AutoTest()
{
	AutoPtr<int> p(new int);
	*p = 10;
	cout << *p << endl;
	AutoPtr<int> p2(p);
	*p2 = 20;
	cout << *p2 << endl;
	AutoPtr<A> pa(new A);
	AutoPtr<int> p3;
	p3 = p2;
	*p3 = 30;
	cout << *p3;
	pa->a;   //这里实际上是这个样子的pa.operator*()->a;
}