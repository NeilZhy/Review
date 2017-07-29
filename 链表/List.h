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
		if (insert->_next==NULL)   //����β�ڵ�
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


	void InverseList()    //��ͨ��ʵ����������
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

	void InverseList1()  //����;�ݹ�ʵ�֣��޷���ֵ
	{
		_InverseList1(_head->_next,_head->_next);
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

	void InverseList2()
	{
		Node* tail = _InverseList2(_head->_next,_head->_next);
		tail = NULL;
	}

	void ReciprocalK(size_t k)   //���ҵ���������K���ڵ㣬ֻ�ܱ���һ�Σ��ݹ�ʵ��
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
	void _InverseList1(Node* cur,Node*& head)   //����ע��Ĳ�����ʱ����Ϊÿ�ζ��Ὠ��ջ֡�ģ��������ﲻ��ֱ�Ӵ�ָ�룬����Ҫ������
	{
		if (cur->_next == NULL)   //���ز�
		{
			head = cur;
		}

		else   //�ݹ�� -- �ȵݹ黹���ȴ���
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
	Node* _head;   //��ͷ������
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
//	List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
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
		List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
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
	List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
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
	List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
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
	List<int> l;   //����Ҳ��ֱ��ʹ��Ĭ�� �Ĺ��캯��
	l.PushFront(6);
	l.PushFront(5);
	l.PushFront(2);
	l.Show();
	l.InverseList2();
	l.Show();
	l.ReciprocalKFL(1);
}

