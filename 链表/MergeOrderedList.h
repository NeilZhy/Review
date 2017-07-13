#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(T data = 0)   //1.1 �����Ҹ���һ��Ĭ��ֵ
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
		:_head(new Node())   //1.2 ����ֱ��ʹ��Ĭ�Ϲ��캯���ͺ�����
		, _tail(_head)
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
	}

	void PushBack(T data)
	{
		Node* insert = new Node(data);
		_tail->_next = insert;
		_tail = insert;
	}


	//void MergeOrderedList(List& l)
	//{
	//	Node* newHead = NULL;
	//	while (_head->_next && !l.empty())
	//	{
	//		if (_head->_data < l._head->_data)  //�������ǿ���ʹ��һ�������ָ��õ����ڲ���һ��������
	//		{
	//			newHead   //�����������ڣ��������ֱ���õ����������ÿ���ڵ㣬������ֱ��ʹ��һ��ָ����޷��õ���������
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


	Node* PopFrontNode()  //һ�η��ص���һ���ڵ��ָ�룬������ڵ������������
	{
		Node* pop = _head->_next;
		_head->_next = pop->_next;
		return pop;
	}

	void PushBackNode(Node* insert)   //һ�β������һ���ڵ�
	{
		_tail->_next = insert;
		_tail = insert;
	}

	

public:
	Node* _head;   //��ͷ������
	Node* _tail;
};

template<class T>
void MergeOrderedList(List<T>& l1,List<T>& l2)
{
	List<T> l;
	while (!l1.empty() && !l2.empty())
	{
		if (l1._head->_next->_data < l2._head->_next->_data)
		{
			l.PushBackNode(l1.PopFrontNode());
		}
		else
		{
			l.PushBackNode(l2.PopFrontNode());
		}
	}
	if (l1.empty())
	{
		l.PushBackNode(l2._head->_next);
		l2._head->_next = l2._tail = NULL;
		l.Show();
		return;
	}
	if (l2.empty())
	{
		l.PushBackNode(l1._head->_next);
		l1._head->_next = l1._tail = NULL;
		l.Show();
		return;
	}
}

void MergeOrderedlistTest()
{
	List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
	l.PushFront(6);
	l.PushFront(5);
	l.PushFront(2);
	List<int> l2;
	l2.PushFront(4);
	l2.PushFront(3);
	l2.PushFront(1);
	l.Show();
	l2.Show();
	MergeOrderedList(l,l2);
}