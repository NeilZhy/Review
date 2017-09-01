#include<iostream>
using namespace std;

template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		delete _ptr;
	}
private:
	ScopedPtr(ScopedPtr &p);   //这里采用的是只声明不定义的方式，那么这个如果我们在使用的时候，编译的时候就会出错
	//这里我们还应该注意的一点就是，我们的拷贝构造函数要放置在private中，如果放置在公有中，这个时候是很有可能被攻击
	//如果被攻击了，然后别人写了一个函数，对我们的程序不力，这个时候就容易造成麻烦

private:
	T* _ptr;
};

void ScopedPtrTest()
{
	ScopedPtr<int> p(new int);
	ScopedPtr<int> p1(p);
	
	
}