#include<iostream>
using namespace std;

struct AA
{
	int a;
	int b;
	~AA()
	{
	}
};



template<class T>
class Shared_Ptr
{
public:
	Shared_Ptr(T* ptr = NULL)
		:_ptr(ptr)
		,_count(new int(1))
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
				delete _ptr;
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
			delete _ptr;
			delete _count;
			_ptr = NULL;
			_count = NULL;
			cout << "delete" << endl;
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


private:
	T* _ptr;
	int* _count;
};

struct Str
{
	Shared_Ptr<Str> _prev;
	Shared_Ptr<Str> _next;
};

void TestPtr()
{
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

	Shared_Ptr<Str> a = new Str;
	Shared_Ptr<Str> b = new Str;

	
	/*a->_next = b;
	b->_prev = a;*/


	
}