#include<iostream>
using namespace std;

int errorTest()
{
	int flag = 0;
	cin >> flag;
	int* p = new int;
	if (flag)         //flagΪ���ʱ��ֱ�ӷ��أ���Դû���ͷŵ�
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
	catch (...)   //���������һ���쳣������ͻ���ת�ˣ�Ȼ���û�������delete��
	{
		throw;
	}
	delete p;
}