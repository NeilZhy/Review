#include<iostream>
using namespace std;
#include<assert.h>
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1



struct DelFile
{
	void operator()(FILE* f)
	{
		fclose(f);
		cout << "fclose" << endl;
	}
};


struct DelDel
{
	void operator()(void* p)
	{
		assert(p);
		delete p;
		cout << "delete" << endl;
	}
};

template<class T,class Del>
class Weak_ptr;

template<class T,class Del>
class Shared_Ptr
{
	
public:
	friend class Weak_ptr<T,Del>;
	Shared_Ptr(T* ptr,Del d)
		:_ptr(ptr)
		,_count(new int(1))
		, _del(d)
	{
	}

	Shared_Ptr(const Shared_Ptr& ptr)
		:_ptr(ptr._ptr)
		, _count(ptr._count)
	{
		(*_count)++;
	}

	Shared_Ptr& operator=(Shared_Ptr& ptr)
	{
		if (this == &ptr)
		{
			return *this;
		}

		else
		{
			if (!--(*_count))
			{
				del(_ptr);
				delete _count;
				cout << "delete older" << endl;
			}
			_ptr = ptr._ptr;
			_count = ptr._count;
			(*_count)++;
		}
		return *this;
	}

	~Shared_Ptr()
	{
		(*_count)--;
		if ((*_count) == 0)
		{
			_del(_ptr);
			delete _count;
			_ptr = NULL;
			_count = NULL;
			//cout << "delete" << endl;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}


protected:
	T* _ptr;
	int* _count;
	Del _del;
};

template<class T, class Del>
class Weak_ptr
{
public:
	Weak_ptr()
		:_ptr(NULL)
	{}
	Weak_ptr(Shared_Ptr<T,Del> ptr)
	{
		_ptr = ptr._ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


struct Str
{
	Weak_ptr<Str,DelDel> _prev;
	Weak_ptr<Str, DelDel> _next;
	int _a;
};

void TestFile()
{
	DelFile d;
	Shared_Ptr<FILE, DelFile> a(fopen("w.ss","w"),d);   //注意这里传参的时候，首先要实例化一个对象
			//我一开始使用的是Shared_Ptr<FILE, DelFile> a(fopen("w.ss","w"),DelFile d)
			//这种方式显然是错误的，我不能在一个函数里面去实例化一个对象
}


void TestPtr()
{
	DelDel d;
	Shared_Ptr<Str, DelDel> a(new Str, d);
	Shared_Ptr<Str, DelDel> b(new Str, d);

	a->_next = b;
	b->_prev = a;
	a->_next->_a = 0;
	cout << b->_a;



	/*Shared_Ptr<int> ptr(new int(1));
	cout << *ptr << endl;
	Shared_Ptr<int> ptr2(ptr);
	*ptr2 = 2;
	cout << *ptr << endl;
	Shared_Ptr<AA> a(new AA);
	a->a = 1;
	a->b = 2;
	cout << "a  "<<a->a;
	cout << "b  "<<a->b;*/

	//Shared_Ptr<AA> ptr1(new AA[10]);
	//Shared_Ptr<AA> ptr2(new AA);


	/*Str* a = new Str;
	Str* b = new Str;
	a->_next = b;
	b->_prev = a;

	delete a;
	delete b;*/
	
}

struct Compare
{
	bool operator()(int a,int b)
	{
		return a > b;
	}
};

void test()
{
	Compare com;
	cout << com(1,2);
}



