#include<iostream>
using namespace std;

template<class T>
class Weak_ptr;

template<class T>
class Shared_Ptr
{
	
public:
	friend class Weak_ptr<T>;
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


protected:
	T* _ptr;
	int* _count;
};

template<class T>
class Weak_ptr
{
public:
	Weak_ptr()
		:_ptr(NULL)
	{}
	Weak_ptr(Shared_Ptr<T> ptr)
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
	Weak_ptr<Str> _prev;
	Weak_ptr<Str> _next;
	int _a;
};


void TestPtr()
{
	

	Shared_Ptr<Str> a = new Str;
	Shared_Ptr<Str> b = new Str;

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



