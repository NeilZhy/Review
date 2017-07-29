#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(T data = 0)   //1.1 这里我给了一个默认值
	:_data(data)
	, _next(NULL)
	{
	}
	T _data;
	ListNode<T>* _next;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
		:_head(new Node())   //1.2 这里直接使用默认构造函数就好来了
		, _tail(_head->_next)
	{

	}
	List(const List& head)
	{
	}

	void PushFront(T data)
	{
		Node* insert = new Node(data);
		insert->_next = _head->_next;
		_head->_next = insert;
		if (insert->_next==NULL)   //更新尾节点
		{
			_tail = insert;
		}
	}

	void PushBack(T data)
	{
		Node* insert = new Node(data);
		_tail->_next = insert;
		_tail = insert;
	}


	void InverseList()    //普通法实现链表逆置
	{
		Node* cur = _head->_next;
		Node* prev = NULL;
		Node* temp = cur;
		_tail = cur;
		if (cur == NULL || cur->_next == NULL)
		{
			return;
		}
		while (cur)
		{
			temp = cur;
			cur = cur->_next;
			temp->_next = prev;
			prev = temp;
		}
		_head->_next = prev;
	}

	void InverseList1()  //逆置;递归实现，无返回值
	{
		_InverseList1(_head->_next,_head->_next);
	}



	

	//void MergeOrderedList(List& l)
	//{
	//	Node* newHead = NULL;
	//	while (_head->_next && !l.empty())
	//	{
	//		if (_head->_data < l._head->_data)  //这里我们可以使用一个对象的指针得到其内部的一个变量的
	//		{
	//			newHead   //这里的问题出在，我想拆了直接拿到两个链表的每个节点，但是我直接使用一个指针的无法拿到，于是我
	//		}
	//	}
	//}



	void Show()
	{
		Node* cur = _head->_next;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	bool empty()
	{
		if (_head->_next == NULL)
		{
			return true;
		}
		return false;
	}


	~List()
	{}


	Node* PopFrontNode()  //一次返回的是一个节点的指针，把这个节点从链表中拿走
	{
		Node* pop = _head->_next;
		_head->_next = pop->_next;
		return pop;
	}

	void PushBackNode(Node* insert)   //一次插入的是一个节点
	{
		_tail->_next = insert;
		_tail = insert;
	}

	void InverseList2()
	{
		Node* tail = _InverseList2(_head->_next,_head->_next);
		tail = NULL;
	}

	void ReciprocalK(size_t k)   //查找单链表倒数第K个节点，只能遍历一次，递归实现
	{
		size_t m = 0;
		
		Node* pnode = NULL;
		_ReciprocalK(k, m, _head->_next,pnode);
		cout << pnode->_data;
		/*size_t m = 0;
		Node* p = _ReciprocalK(k,_head->_next,m);
		cout << p->_data << endl;*/
	}

	Node* ReciprocalKFL(size_t k)
	{
		Node* fast = _head->_next;
		Node* low = _head->_next;
		while (k--)
		{
			fast = fast->_next;
		}
		while (fast)
		{
			fast = fast->_next;
			low = low->_next;
		}
		cout << low->_data << endl;
		return low;
	}


private:
	void _ReciprocalK(size_t k,size_t &m,Node* cur,Node* &pnode)
	{
		if (cur->_next == NULL)
		{
			m++;
			if (k == m)
				pnode = cur;
		}
		else
		{
			_ReciprocalK(k,m,cur->_next,pnode);
			m++;
			if (k == m)
			{
				pnode = cur;
			}
		}
	}


	Node* _InverseList2(Node* cur,Node* &head)
	{
		if (cur->_next == NULL)
		{
			head = cur;
			return cur;
		}
		else
		{
			Node* temp = _InverseList2(cur->_next,head);
			temp->_next = cur;
			cur->_next = NULL;
			return cur;
		}
	}
	void _InverseList1(Node* cur,Node*& head)   //这里注意的参数的时候因为每次都会建立栈帧的，所以这里不能直接传指针，而是要传引用
	{
		if (cur->_next == NULL)   //返回层
		{
			head = cur;
		}

		else   //递归层 -- 先递归还是先处理
		{
			Node* next = cur->_next;
			_InverseList1(cur->_next,head);
			next->_next = cur;   //
			cur->_next = NULL;
		}
	}

	/*Node* _ReciprocalK(size_t& k,Node* l,size_t& m)
	{
		if (l == NULL)
		{
			m = 0;
			return NULL;
		}
		
		if (m == k)
		{
			return l;
		}
		m++;
		return _ReciprocalK(k,l->_next,m);
		
		
		
	}*/

	

private:
	Node* _head;   //有头单链表
	Node* _tail;
};

//template<class T>
//void MergeOrderedList(List<T>& l1,List<T>& l2)
//{
//	List<T> l;
//	while (!l1.empty() && !l2.empty())
//	{
//		if (l1._head->_next->_data < l2._head->_next->_data)
//		{
//			l.PushBackNode(l1.PopFrontNode());
//		}
//		else
//		{
//			l.PushBackNode(l2.PopFrontNode());
//		}
//	}
//	if (l1.empty())
//	{
//		l.PushBackNode(l2._head->_next);
//		l2._head->_next = l2._tail = NULL;
//		l.Show();
//		return;
//	}
//	if (l2.empty())
//	{
//		l.PushBackNode(l1._head->_next);
//		l1._head->_next = l1._tail = NULL;
//		l.Show();
//		return;
//	}
//}

//void MergeOrderedlistTest()
//{
//	List<int> l;   //这里也是直接使用默认 的构造函数
//	l.PushFront(6);
//	l.PushFront(5);
//	l.PushFront(2);
//	List<int> l2;
//	l2.PushFront(4);
//	l2.PushFront(3);
//	l2.PushFront(1);
//	l.Show();
//	l2.Show();
//	MergeOrderedList(l,l2);
//}

void InverseListTest()
{
		List<int> l;   //这里也是直接使用默认 的构造函数
		l.PushFront(6);
		l.PushFront(5);
		l.PushFront(2);
		l.Show();
		l.InverseList();
		l.Show();
		l.ReciprocalK(2);
}

void InverseListTest1()
{
	List<int> l;   //这里也是直接使用默认 的构造函数
	l.PushFront(6);
	l.PushFront(5);
	l.PushFront(2);
	l.Show();
	l.InverseList1();
	l.Show();
	//l.ReciprocalK(2);
}

void InverseListTest2()
{
	List<int> l;   //这里也是直接使用默认 的构造函数
	l.PushFront(6);
	l.PushFront(5);
	l.PushFront(2);
	l.Show();
	l.InverseList2();
	l.Show();
	l.ReciprocalK(2);
}

void ReciprocalKFLTest()
{
	List<int> l;   //这里也是直接使用默认 的构造函数
	l.PushFront(6);
	l.PushFront(5);
	l.PushFront(2);
	l.Show();
	l.InverseList2();
	l.Show();
	l.ReciprocalKFL(1);
}

