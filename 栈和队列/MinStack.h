#include<iostream>
using namespace std;
#include<vector>


template<class T, class St = vector<T>>
class MinStack
{
public:
	MinStack()
	{}
	void Push(const T& data)
	{
		_s.push_back(data);
		if (_min.empty())
		{
			_min.push_back(data);
		}
		if (data < _min.back())
		{
			_min.push_back(data);
		}
	}

	void Pop()
	{
		if (_s.back() == _min.back())
		{
			_min.pop_back();
		}
		_s.pop_back();
	}

	T Top()
	{
		return _s.back();
	}

	T Min()
	{
		if (_min.empty())
		{
			return 0;
		}
		return _min.back();
	}

private:
	St _s;
	St _min;		//用于维护最小值
};

void TestMinStack()
{
	MinStack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(4);
	s.Push(5);
	s.Push(3);

	cout << s.Min() << endl;
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();

}
