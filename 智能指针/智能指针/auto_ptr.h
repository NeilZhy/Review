#include<iostream>
using namespace std;
#include<assert.h>

template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* p = NULL)
		:_ptr(p)
		, _flag(true)
	{
	}

	Auto_ptr(Auto_ptr& pa)   //这里是不能使用const的，因为我需要修改里面的内容
		:_ptr(pa._ptr)
		, _flag(pa._flag)
	{
		pa._flag = false;
	}

	Auto_ptr& operator=(Auto_ptr& pa)
	{
		if (this != &pa)
		{
			if (_flag)
			{
				delete _ptr;
			}
			_ptr = pa._ptr;
			_flag = pa._flag;
			pa._flag = false;
		}
		return *this;
	}

	~Auto_ptr()
	{
		if (_flag)
		{
			delete _ptr;
			_flag = false;
		}
		_ptr = NULL;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}


private:
	T* _ptr;
	bool _flag;
};

void TestAuto_ptr()
{
	Auto_ptr<int> p(new int(7));
	cout << *p << endl;
	Auto_ptr<int> p2 = p;
	cout << *p2 << endl;
	Auto_ptr<int> p3;
	p3 = p2;
	int *m = NULL;
	delete m;
	if (1)
	{
		Auto_ptr<int> p4 = p3;
	}
	cout << *p3<<endl;
	
}