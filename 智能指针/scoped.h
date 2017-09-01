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
	ScopedPtr(ScopedPtr &p);   //������õ���ֻ����������ķ�ʽ����ô������������ʹ�õ�ʱ�򣬱����ʱ��ͻ����
	//�������ǻ�Ӧ��ע���һ����ǣ����ǵĿ������캯��Ҫ������private�У���������ڹ����У����ʱ���Ǻ��п��ܱ�����
	//����������ˣ�Ȼ�����д��һ�������������ǵĳ����������ʱ�����������鷳

private:
	T* _ptr;
};

void ScopedPtrTest()
{
	ScopedPtr<int> p(new int);
	ScopedPtr<int> p1(p);
	
	
}