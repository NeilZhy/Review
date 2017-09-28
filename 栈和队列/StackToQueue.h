#include"Stack.h"

template<class T>
class Stack2Queue
{
public:
	Stack2Queue()
	{}
	void QPush(const T& data)
	{
		/*while (!_in.Empty())
		{
			_out.Push(_in.Top());
			_in.Pop();
		}*/
		_in.Push(data);
	}

	void QPop()
	{
		if (_out.Empty())
		{
			while (!_in.Empty())
			{
				_out.Push(_in.Top());
				_in.Pop();
			}
		}
		
		if (!_out.Empty())
		{
			_out.Pop();
		}
	}

	T QFront()
	{
		if (_out.Empty())
		{
			while (!_in.Empty())
			{
				_out.Push(_in.Top());
				_in.Pop();
			}
		}
		
		if (!_out.Empty())
		{
			return _out.Top();
		}
		else
		{
			return 0;
		}
	}
private:
	Stack<T> _out;
	Stack<T> _in;
};

void TestStack2Queue()
{
	Stack2Queue<int> qu;
	qu.QPush(1);
	qu.QPush(2);
	qu.QPush(3);
	cout << qu.QFront()<<endl;
	qu.QPop();
	cout << qu.QFront()<<endl;
	qu.QPop();
	qu.QPush(4);
	qu.QPush(5);
	qu.QPush(6);
	qu.QPush(7);
	qu.QPush(8);
	cout << qu.QFront() << endl;
	qu.QPop();
	cout << qu.QFront()<<endl;
	qu.QPop();
	cout << qu.QFront()<<endl;

	qu.QPop();
	qu.QPop();
	cout << qu.QFront() << endl;
	cout << qu.QFront() << endl;
	qu.QPop();
	cout << qu.QFront() << endl;
}