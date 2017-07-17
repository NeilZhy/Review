#include<iostream>
using namespace std;




////class Anmail
////{
////public:
////	//virtual void Howl()   //作用是定义了一个接口但是不实现它，目的是为了让各个派生类能够个性化定制
////	//{}
////
////	virtual void A()
////	{}
////
////	virtual void B()
////	{}
////
////	virtual void C()
////	{}
////
////
////	//void A()
////	//{
////
////	//}
////
////	///*int A()
////	//{}*/
////
////	//void A(int a)
////	//{}
////
////	//void A(double b)
////	//{}
////};
////
////class Dog :public Anmail
////{
////public:
////	virtual void Howl()
////	{
////		cout << "汪汪" << endl;
////	}
////};
////
////class Cat :public Anmail
////{
////public:
////	virtual void Howl()
////	{
////		cout << "喵喵" << endl;
////	}
////
////};
////
////
////int main()
////{
////	///*Dog a;
////	//a.Howl();
////	//Cat b;
////	//b.Howl();*/
////	//Anmail* an = new Dog();
////	//an->Howl();
////	//Anmail* bn = new Cat();
////	//bn->Howl();
////
////	Anmail a;
////	/*a.A();
////	a.A(1);
////	a.A(1.2);*/
////	Dog b;
////	return 0;
////}
//
//class Base
//{
//public:
//	virtual void A()
//	{
//		cout << "BaseA" << endl;
//	}
//	virtual void B()
//	{
//		cout << "BaseB" << endl;
//	}
//	virtual void C()
//	{}
//};
//
//class Base1
//{
//public:
//	virtual void A()
//	{}
//	virtual void B()
//	{}
//	virtual void C()
//	{}
//};
//class Base2
//{
//public:
//	virtual void A()
//	{}
//	virtual void B()
//	{}
//	virtual void C()
//	{}
//};
//
//class Derived:public Base,public Base1,public Base2
//{
//	virtual void A()
//	{
//		cout << "Derived" << endl;
//	}
//};
//int main()
//{
//	typedef void (*func)();   //函数指针
//	Base bs;
//	Base1 bs1;
//	Base2 bs2;
//	Derived de;
//	int* p = (int*)*(int*)*(int*)(&bs);  //第一个虚函数的指针
//	int* m =        (int*)*(int*)(&bs);
//	func f = (func)*((int*)*(int*)(&bs)+1);
//	f();
//
//	return 0;
//}
//
////class Base {
////public:
////	virtual void f() { cout << "Base::f" << endl; }
////	virtual void g() { cout << "Base::g" << endl; }
////	virtual void h() { cout << "Base::h" << endl; }
////
////};
////
////int main()
////{
////	typedef void(*Fun)(void);
////
////	Base b;
////
////	Fun pFun = NULL;
////
////	cout << "虚函数表地址：" << (int*)(&b) << endl;
////	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
////
////	// Invoke the first virtual function
////	pFun = (Fun)*((int*)*(int*)(&b));
////	pFun();
////	return 0;
////}


class Base
{
	virtual void A()
	{
		cout << "BaseA()" << endl;
	}
	virtual void B()
	{
		cout << "BaseB()" << endl;
	}
};

class Derived:public virtual Base
{
	void A()
	{
		cout << "DerivedA" << endl;
	}

};

int main()
{
	Base bs;
	Derived de;
	return 0;
}