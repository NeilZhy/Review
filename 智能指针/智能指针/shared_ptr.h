#include<iostream>
using namespace std;


//һ��Ҫע��һ�����������ʹ��ģ���ʱ��ÿһ���ĵط�,��Ҫ����ƥ�䣬��ʹ��������ʱ��
//����ɾ�������º���

struct DelF
{
	void operator()(FILE* p)
	{
		fclose(p);
		cout << "flose" << endl;
	}
};


struct Del
{
	void operator()(void* p)   //����һ��ʼ��ʱ�򣬲�֪�����������������ǿ��Լ�����void*
	{
		delete p;
		cout << "del" << endl;
	}
};

template<class T,class D>   //������Ҫ�������Shared_ptr
class Shared_ptr;

template<class T,class D>
class Weak_ptr
{
public:
	Weak_ptr()
	{
	}

	Weak_ptr(Shared_ptr<T,D>& pa)
		:_wptr(pa._ptr)
	{}

	T* operator->()
	{
		return *_wptr;
	}

private:
	T* _wptr;
};

template<class T,class D>
class Shared_ptr
{
	friend Weak_ptr<T,D>;
public:
	Shared_ptr(T* p, D d)
		:_ptr(p)
		, _count(new int(1))
		, _d(d)
	{}

	Shared_ptr(Shared_ptr& pa)
		:_ptr(pa._ptr)
		, _count(pa._count)
	{
		(*_count)++;
	}

	Shared_ptr& operator=(Shared_ptr& pa)
	{
		cout << "operator" << endl;
		if (_ptr != pa._ptr)
		{
			if ((*_count) == 1)
			{
				_d(_ptr);
				delete _count;
			}
			_ptr = pa._ptr;
			_count = pa._count;
			++(*_count);
		}
		return *this;
	}

	~Shared_ptr()
	{
		if ((*_count) == 1)
		{
			_d(_ptr);
			delete _count; 
			_count = NULL;
			_ptr = NULL;
		}
		else
		{
			--(*_count);
			_count = NULL;
			_ptr = NULL;
		}

		cout << "~Shared_ptr" << endl;
		
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

private:
	T* _ptr;
	int* _count;
	D _d;
};

template<class T>
struct AA
{
	Weak_ptr<AA,Del> _prev;
	Weak_ptr<AA,Del> _next;
	T _data;
};


void TestShared_ptr()
{
	Del a;
	DelF d;
	Shared_ptr<AA<int>,Del> pa(new AA<int>,a);
	Shared_ptr<AA<int>,Del> pb(new AA<int>,a);
	
	Shared_ptr<FILE, DelF> pf(fopen("w.txt", "w"), d);

	FILE* p = fopen("w.txt","w");



	/*pa->_next = pb;
	pb->_prev = pa;*/
 	
}