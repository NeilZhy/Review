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


//���T��ǵ���ά������������,Ref�����ã���������Ƕ����ݵ����ã�����������data������
//Ptr��ָ�룬���ָ��Ҳ��ָ������data��ָ��������ģ���������ǿ�����
//List���������ʹ�ã���Ϊ�ڱ�дList_Iterator��ʱ�򣬻ᾭ��ʹ��Ref��Ptr
template<class T, class Ref, class Ptr>
class List_Iterator
{
	typedef _ListNode<T> Node;
	typedef List_Iterator<T, Ref, Ptr> Self;   //����ط�д�� �е�ʧ���ˣ����ǰ�List_Iterator�ĵ���д����
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

	Self operator++(int)    //ע��ǰ��++���ص������ã�������++���ص���Self
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
		return _it != it._it;    //һ��ʼд�����=��������ص�ʱ��Ҳ�����˴��󣬾�����һ��ʼ����this��&it��
								//����Ȼ�ǲ��Եģ���������������������ȵģ��������ʱ��Ӧ������
								//��������������ָ����������Ƚϣ����������ǵĳ�Ա������ ���бȽϲ���ȷ
	}

private:
	Node* _it;
};


//����������Ҫ��һ���޸ľ��ǣ�������Ҫ������������һ��˫�����ͷ��ѭ������
//�����������Ҫ�ڹ��캯����ʱ��ȥ����
//��������_tail�Ͳ���Ҫ��



//��ͷ��㣬_headά����һ��ͷ��㣬��������ڵ㲻�����κε����ݣ���Ϊ�����ں������ɾ��ĵ�ʱ��ʹ�õ�ʱ���ǳ��ķ���
template<class T>
class _List
{
	typedef _ListNode<T> Node;

public:
	typedef List_Iterator<T, T&, T*> Iterator;
	//const������
	typedef List_Iterator<T, const T&, const T*> Const_Iterator;
	//����Ϊʲô���ݵ���const T&��const T*�أ���������������ݵĻ�����ʵ��iterator��ʱ�������и�������
	//Ref operator*()
	//{
	//	return _it->_data;
	//}
	//���ʱ����Ϊ���Ǵ��ݵ���const�ģ��������ʱ���Ref�ͳ���const���ˣ����ʱ���iterator��ά���Ľڵ�
	//��������ݾͲ��ɸı��ˣ����ʵ����const��������
	//��Ҳ������Ϊʲô���iterator��ʱ��Ϊʲô��Ƶ�������ģ�������
	//�����const_iterator���ǻ���Ҫģ��ʵ�ַ���ʱconst��end��begin

	_List()
		:_head(new Node)   //���ﱨ��һ��������ǣ�û�к��ʵĹ��캯������ʹ�ã�ԭ����������д_ListNode��ʱ��
		//�����ˣ���������û�д�����������������Ķ�ʱ��Ѵ��ݵĲ���Ĭ��Ϊd = 0���ʱ��������Ҳ����ݲ���
		//Ҳû��ʲô������
		//	, _tail(_head)
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	
	//���￪ʼ��Ƶ�ʱ�����ŷ���ֵ��Node*��Ȼ������ʹ�õ�ʱ�򣬿��������Node*����һ�������������õ�����
	//�Ĺ��캯������������һ���������ˣ������������ڣ��������Ļ����ǲ��ǻ��������ǵ�ĳЩʱ���һЩ�����
	//���ǿ���ֱ�ӷ��صľ���һ��������
	//�����������������Ƶķ���ֵ��һ���������Ļ���������Ҫ������������涨��һ����������Ȼ�󷵻ص�ʱ��
	//����һ����ʱ�Ķ��󣬷��ظ����ĵ����������ʱ�������һ�ο������캯�������ظ����ĵ�������ʱ��
	//�ֵ�����һ�ο������캯���������᲻��̫��������

	
	//Iterator begin()
	//{
	//	if (_head->_next == _head)   //��������һ���жϾ��ǵ����ǵ������ǿյ�ʱ�򣬾Ͳ���ֱ�ӷ���next
	//	{
	//		return Iterator(NULL);
	//	}
	//	return Iterator(_head->_next);
	//}


	//��ʹ��Const_Iterator��ʱ�������������ǣ�Ϊʲô���������ͨ��begin������ע�� ��ʱ�򣬾ͱ��벻����
	Const_Iterator begin() const   //����ֵ��Const_iteratorΪ�˺������ƥ�䣬Ȼ����� ��һ��constΪΪ��
									//thisָ����ָ�������
	{
		if (_head->_next == _head)   //��������һ���жϾ��ǵ����ǵ������ǿյ�ʱ�򣬾Ͳ���ֱ�ӷ���next
		{
			return Const_Iterator(NULL);
		}
		return Const_Iterator(_head->_next);
	}


	//Node* begin() const
	//{
	//	if (_head->_next == _head)   //��������һ���жϾ��ǵ����ǵ������ǿյ�ʱ�򣬾Ͳ���ֱ�ӷ���next
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
	//	Const_Iterator it = begin();   //���ԭ���ǣ����ǵ�begin���� const�ģ��������ǵ�const_ietator��const��
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
	l.Pushback(0);   //һ��ʼ��ʱ�����������õ�������������ã����ʱ���Ǳ粻���ģ���Ϊ���ǵ�0���ڳ�������
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




