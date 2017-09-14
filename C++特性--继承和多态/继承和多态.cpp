#include<iostream>
using namespace std;
class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	void ShowA()
	{
		cout << "I am A." << endl;
	}
	void ShowAA()
	{
		ShowA();
	}
public:
	int _a;
};
	

class B : public A
{
public:
	B(int a)
		:_b(0)
		, A(a)
	{
	}
	void ShowB()
	{
		cout << "B" << endl;
		//ShowA();
	}
public:
	int _b;
};

int main()
{
	A a(0);
	B b(0);
	a = b;
	return 0;

}