#include<iostream>
using namespace std;

template<class T>
class Scoped_ptr
{
public:
	Scoped_ptr(const T* p = NULL)
		:_ptr(p)
	{}
	~Scoped_ptr()
	{
		delete _ptr;
	}
private:
	Scoped_ptr(const Scoped_ptr& pa);   //只声明不定义,
private:
	T* _ptr;
};

void TestScoped_ptr()
{
	Scoped_ptr<int> p(new int(5));
	//Scoped_ptr<int> p2(p);
}