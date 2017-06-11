#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str = "")          //const，考虑传入的参数是一个空字符串
		:_str(new char[strlen(str) + 1])    //strlen的测试长度不包括\0
	{
		strcpy(_str,str);                   //strcpy函数中需要放置的指针放在前面
	}

	MyString(const MyString& str)
		:_str(new char[strlen(str._str) + 1])   //这里注意和上面的区分开，上面的传递的是一个指针，而这里传递的一个对象
	{
		strcpy(_str,str._str);
	}

	~MyString()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;         //这里要注意的就是，释放_str之后我们的_str要在指向一个NULL
		}
	}

	MyString& operator=(const MyString& str)
	{
		if (this == &str)    //这里一定 要判断自赋值的问题
		{
			return *this;   //返回的是一个*this
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