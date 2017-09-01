#include<iostream>
using namespace std;

int errorTest()
{
	int flag = 0;
	cin >> flag;
	int* p = new int;
	if (flag)         //flag为真的时候，直接返回，资源没有释放掉
	{
		cout << "success" << endl;
		return 0;
	}
	else
	{
		delete p;
		cout << "error" << endl;
		return 1;
	}
}

void errorTest2()
{
	int* p;
	try
	{
		p = (int*)malloc(1000);
	}
	catch (...)   //如果捕获到了一个异常，程序就会跳转了，然后就没有下面的delete了
	{
		throw;
	}
	delete p;
}