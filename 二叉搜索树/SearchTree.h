#include<iostream>
using namespace std;

template<class K,class V>
struct SearchTreeNode
{
	K _key;
	V _value;
	SearchTreeNode<K, V>* _left;
	SearchTreeNode<K, V>* _right;
	SearchTreeNode<K, V>* _parent;

	SearchTreeNode(K key = 0,V value = 0)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{
	}
};

template<class K,class V>
class SearchTree
{
	typedef SearchTreeNode<K, V> Node;
public:
	SearchTree()
		:_root(NULL)
	{}

	bool Insert(K key,V value)
	{
		if (_root == NULL)
		{
			_root = new Node(key,value);
			return true;
		}
		Node* cur = _root;
		Node* prev = cur;
		while (cur)
		{
			if (key < cur->_key)
			{
				prev = cur;
				cur = cur->_left;
			}
			else if (key>cur->_key)
			{
				prev = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		if (key > prev->_key)
		{
			prev->_right = new Node(key,value);
			prev->_right->_parent = prev;
		}
		else
		{
			prev->_left = new Node(key,value);
			prev->_left->_parent = prev;
		}
		return true;
	}

	bool InsertR(const K key,const V value)
	{
		return _Insert(key,value,_root);
	}

	bool Search(const K key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
			{
				return true;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return false;
	}

	bool SearchR(const K key)
	{
		return _Search(key, _root);
	}

private:
	bool _Search(const K key,Node* root)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->_key == key)
		{
			return true;
		}
		if (key > root->_key)
		{
			return _Search(key,root->_right);
		}
		else
		{
			return _Search(key,root->_left);
		}
	}

	bool _Insert(const K key,const V value,Node* &root)
	{
		if (root == NULL)
		{
			root = new Node(key,value);
			return true;
		}
		if (key < root->_key)
		{
			return _Insert(key,value,root->_left);
		}
		else
		{
			return _Insert(key,value,root->_right);
		}
	}

private:
	Node* _root;
};

void test()
{
	SearchTree<int, int> tree;
	tree.InsertR(5, 1);
	tree.InsertR(3, 1);
	tree.InsertR(8, 1);
	tree.InsertR(9, 1);
	tree.InsertR(6, 1);
	tree.InsertR(2, 1);
	tree.InsertR(0, 1);

	cout<<tree.Search(2)<<endl;
	cout << tree.SearchR(2)<<endl;


}