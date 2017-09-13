#include<iostream>
using namespace std;

class A
{
public:
	A()
		:_a(0)
	{}
public:
	int _a;
};
	

class B : public A
{
public:
	B()
		:_b(0)
	{
	}
public:
	int _b;
};

int main()
{
	A a;
	B b;
	a = b;
	return 0;

}