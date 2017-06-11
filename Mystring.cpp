#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str = "")          //const�����Ǵ���Ĳ�����һ�����ַ���
		:_str(new char[strlen(str) + 1])    //strlen�Ĳ��Գ��Ȳ�����\0
	{
		strcpy(_str,str);                   //strcpy��������Ҫ���õ�ָ�����ǰ��
	}

	MyString(const MyString& str)
		:_str(new char[strlen(str._str) + 1])   //����ע�����������ֿ�������Ĵ��ݵ���һ��ָ�룬�����ﴫ�ݵ�һ������
	{
		strcpy(_str,str._str);
	}

	~MyString()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;         //����Ҫע��ľ��ǣ��ͷ�_str֮�����ǵ�_strҪ��ָ��һ��NULL
		}
	}

	MyString& operator=(const MyString& str)
	{
		if (this == &str)    //����һ�� Ҫ�ж��Ը�ֵ������
		{
			return *this;   //���ص���һ��*this
		}
		else
		{
			delete[] _str;
			_str = new char[(strlen(str._str) + 1)];
			strcpy(_str,str._str);
			return *this;
		}
	}
private:
	char* _str;
};

int main()
{
	MyString s1;
	MyString s2("hello");
	MyString s3 = "";
	s1 = s2;
	return 0;
}