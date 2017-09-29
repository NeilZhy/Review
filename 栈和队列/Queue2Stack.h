#include"Queue.h"

template<class T>
class Queue2Stack
{
public:
	Queue2Stack()
	{}
	void Push(const T& data)
	{
		if (_qu1.Empty())
		{
			_qu2.push(data);
		}
		else
		{
			_qu1.push(data);
		}
	}

	void Pop()
	{
		T data;
		if (_qu1.Empty())
		{
			if (!_qu2.Empty())
			{
				data = _qu2.front();
				_qu2.pop();
			}
			
			while (!_qu2.Empty())
			{
				_qu1.push(data);
				data = _qu2.front();
				_qu2.pop();
			}
		}
		else
		{
			if (!_qu1.Empty())
			{
				data = _qu1.front();
				_qu1.pop();
			}
			
			while (!_qu1.Empty())
			{
				_qu2.push(data);
				data = _qu1.front();
				_qu1.pop();
			}
		}
	}

	T Front()
	{
		T data;
		if (_qu1.Empty())
		{
			if (_qu2.Empty())
			{
				return 0;
			}
		
			while (!_qu2.Empty())
			{
				data = _qu2.front();
				_qu1.push(data);
				_qu2.pop();
			}
			return data;
		}
		else
		{
			if (_qu1.Empty())
			{
				return 0;
			}
			while (!_qu1.Empty())
			{
				data = _qu1.front();
				_qu2.push(data);
				_qu1.pop();
			}
			return data;
		}
	}

private:
	Queue<T> _qu1;
	Queue<T> _qu2;
};

void TestQueue2Stack()
{
	Queue2Stack<int> sq;
	sq.Push(1);
	sq.Push(2);
	sq.Push(3);
	sq.Push(4);
	cout << sq.Front() << " ";
	sq.Pop();
	cout << sq.Front() << " ";
	sq.Pop();
	cout << sq.Front() << " ";
	sq.Pop();
	cout << sq.Front() << " ";
	sq.Pop();
}