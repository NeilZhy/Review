#include<iostream>
using namespace std;

#include<list>

template<class T>
struct _ListNode
{
	_ListNode<T>* _next;
	_ListNode<T>* _prev;
	T _data;
	_ListNode(T d = 0)
		:_data(d)
		, _next(NULL)
		, _prev(NULL)
	{}
};


//这个T标记的是维护的数据类型,Ref是引用，这个引用是对数据的引用，就是这里面data的引用
//Ptr是指针，这个指针也是指向数据data的指针这两个模板类型我们可以在
//List这个类里面使用，因为在编写List_Iterator的时候，会经常使用Ref和Ptr
template<class T, class Ref, class Ptr>
class List_Iterator
{
	typedef _ListNode<T> Node;
	typedef List_Iterator<T, Ref, Ptr> Self;   //这个地方写的 有点失误了，就是把List_Iterator的单词写错了
public:
	List_Iterator(Node* it)
		:_it(it)
	{}

	List_Iterator(const List_Iterator& it)
	{
		_it = it._it;
	}

	//List_Iterator& operator++()
	Self& operator++()
	{
		_it = _it->_next;
		return *this;
	}

	Self operator++(int)    //注意前置++返回的是引用，而后置++返回的是Self
	{
		Node* tmp = _it;
		_it = _it->_next;
		return tmp;
	}

	//T& operator*()
	Ref operator*()
	{
		return _it->_data;
	}

	bool operator!=(const Self& it)
	{
		return _it != it._it;    //一开始写这个！=运算符重载的时候也出现了错误，就是我一开始是拿this和&it比
								//这显然是不对的，两个迭代器不可能是相等的，所以这个时候应该是拿
								//这两个迭代器所指向的内容来比较，就是那他们的成员变量来 进行比较才正确
	}

private:
	Node* _it;
};


//这里我们需要做一个修改就是，我们需要把这个链表定义成一个双向的有头的循环链表
//这个工作就是要在构造函数的时候去做了
//所以这里_tail就不需要了



//有头结点，_head维护了一个头结点，但是这个节点不放置任何的数据，因为这样在后面的增删查改的时候使用的时候会非常的方便
template<class T>
class _List
{
	typedef _ListNode<T> Node;

public:
	typedef List_Iterator<T, T&, T*> Iterator;
	//const迭代器
	typedef List_Iterator<T, const T&, const T*> Const_Iterator;
	//这里为什么传递的是const T&和const T*呢，如果我们这样传递的话，在实现iterator的时候，里面有个函数是
	//Ref operator*()
	//{
	//	return _it->_data;
	//}
	//这个时候因为我们传递的是const的，所以这个时候的Ref就成了const的了，这个时候的iterator所维护的节点
	//里面的数据就不可改变了，这就实现了const的作用了
	//这也是我们为什么设计iterator的时候为什么设计的是三个模板参数了
	//配合着const_iterator我们还需要模拟实现返回时const的end和begin

	_List()
		:_head(new Node)   //这里报了一个错误就是，没有合适的构造函数可以使用，原因是我上面写_ListNode的时候
		//传参了，但是这里没有传参数，所以我上面的额时候把传递的参数默认为d = 0这个时候就算是我不传递参数
		//也没有什么问题了
		//	, _tail(_head)
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	
	//这里开始设计的时候想着返回值是Node*，然后外面使用的时候，可以拿这个Node*构造一个迭代器，调用迭代器
	//的构造函数，就生成了一个迭代器了，但是问题在于，这样做的话，是不是会引起我们的某些时候的一些误解呢
	//我们可以直接返回的就是一个迭代器
	//但是如果我们这里设计的返回值是一个迭代器的话，我们需要在这个函数里面定义一个迭代器，然后返回的时候
	//生成一个临时的对象，返回给外层的迭代器，这个时候调用了一次拷贝构造函数，返回给外层的迭代器的时候
	//又调用了一次拷贝构造函数，这样会不会太复杂了呢

	
	//Iterator begin()
	//{
	//	if (_head->_next == _head)   //这里做了一个判断就是当我们的链表是空的时候，就不能直接返回next
	//	{
	//		return Iterator(NULL);
	//	}
	//	return Iterator(_head->_next);
	//}


	//在使用Const_Iterator的时候出现了问题就是，为什么我下面的普通的begin函数不注释 的时候，就编译不过呢
	Const_Iterator begin() const   //返回值是Const_iterator为了和上面的匹配，然后后面 的一个const为为了
									//this指针所指向的内容
	{
		if (_head->_next == _head)   //这里做了一个判断就是当我们的链表是空的时候，就不能直接返回next
		{
			return Const_Iterator(NULL);
		}
		return Const_Iterator(_head->_next);
	}


	//Node* begin() const
	//{
	//	if (_head->_next == _head)   //这里做了一个判断就是当我们的链表是空的时候，就不能直接返回next
	//	{
	//		return NULL;
	//	}
	//	return _head->_next;
	//}



	/*Iterator end()
	{
		if (_head->_next == _head)
		{
			return Iterator(NULL);
		}
		return Iterator(_head);
	}*/

	Const_Iterator end() const
	{
		if (_head->_next == _head)
		{
			return Const_Iterator(NULL);
		}
		return Const_Iterator(_head);
	}


	void Pushback(const T& data)
	{
		Node* cur = new Node(data);
		cur->_prev = _head->_prev;
		_head->_prev = cur;
		cur->_next = _head;
		cur->_prev->_next = cur;

	}

	//void Print()
	//{
	//	Const_Iterator it = begin();   //这个原因是，我们的begin不是 const的，但是我们的const_ietator是const的
	//	while (it != end())
	//	{
	//		cout << *it << endl;
	//		it++;
	//	}
	//}
private:
	Node* _head;
//	Node* _tail;
};

void TestList()
{
	_List<int> l;
	l.Pushback(0);   //一开始的时候，我这里设置的这个参数是引用，这个时候是辩不过的，因为我们的0是在常量区的
	l.Pushback(1);
	l.Pushback(2);

	_List<int>::Const_Iterator it = l.begin();

	/*_List<int>::Ierator it = l.begin();
	cout << *it << endl;
	++it;
	cout << *it << endl;
	++it;
	cout << *it << endl;*/
//	_List<int>::Iterator it = l.begin();
	//*it = 5;
	//l.Print();





	/*list<int> l;
	l.push_back(0);
	l.push_back(1);

	list<int>::const_iterator it = l.begin();*/





}




