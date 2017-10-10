#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class A
{
public:

	virtual void show()
	{
		cout << "A show()" << endl;
	}

	void display()
	{
		cout << "A display()" << endl;
	}

public:
	int _a;
};

class B : public A
{
public:

	void show()
	{
		cout << "B show()" << endl;
	}

	void display()
	{
		cout << "B display()" << endl;
	}

public:
	int _b;
};


class C : public A
{
public:

	void show()
	{
		cout << "C show()" << endl;
	}

	void display()
	{
		cout << "C display()" << endl;
	}

public:
	int _b;
};

class D : public B, public C
{

};

int main()
{
	A a;
	B b;
	return 0;
}