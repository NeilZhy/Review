#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	void ShowA()
//	{
//		cout << "I am A." << endl;
//	}
//	void ShowAA()
//	{
//		ShowA();
//	}
//public:
//	int _a;
//};
//
//
//class B : public A
//{
//public:
//	B(int a)
//		:A(a)
//		, _b(a)
//	{
//	}
//	void ShowB()
//	{
//		cout << "B" << endl;
//		//ShowA();
//	}
//public:
//	int _b;
//};

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
	}

	A(const A& a)
	{
		_a = a._a;
	}

	A& operator=(const A& a)
	{
		if (this == &a)
		{
		}
		else
		{
			_a = a._a;
		}
		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

class B : public A
{
public:
	B(int a = 0,int b = 1)
		:A(a)
		,_b(b)
	{
	}

	B(const B& b)
		:A(b)
	     ,_b(b._b)
	{
	}

	B& operator=(const B& b)
	{
		if (this != &b)
		{
			A::operator=(b);
			_b = b._b;

		}
		return *this;
	}

	~B()
	{
		cout << "~B()"<<endl;
	}

private:
	int _b;
};

int main()
{
	A a(0);
	B b(0);
	/*B c(0);
	b = c;*/
	return 0;

}