#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
#include"auto_ptr.h"
#include"shared_ptr.h"




void Test()
{
	/*int *p = new int(5);
	int flag = 0;*/

	//动态开辟的空间没有释放
	/*if (cin >> flag)
	{
	cout << *p << endl;
	delete p;
	}
	else
	{
	return -1;
	}*/

	//动态开辟的空间没有释放
	/*try
	{
		cin >> flag;
		if (flag)
		{
			throw int(0);
		}
		delete p;
	}

	catch (int a)
	{
		cout << a << endl;
	}*/
}

int main()
{
	//Test();
	//TestAuto_ptr();
	TestShared_ptr();

	


	return 0;
}
