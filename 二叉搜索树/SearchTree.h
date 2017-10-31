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
			(prev->_right)->_parent = prev;
		}
		else
		{
			prev->_left = new Node(key,value);
			(prev->_left)->_parent = prev;
		}
		return true;
	}

	bool InsertR(const K key,const V value)
	{
		return _Insert(key,value,_root,NULL);
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

	bool EraseR(const K key)
	{
		//递归实现就不写了，里面还是需要嵌套着非递归的实现
		return _EreaeR(key,_root,NULL);
	}

	bool Erase(const K key)
	{
		//分三种情况讨论
		//叶子节点、单支节点，双支节点
		Node* cur = Find(key,_root);
		if (cur == NULL)
		{
			return false;
		}

		

		//叶子和单支
		if (cur->_left == NULL)//左
		{
			Node* parent = cur->_parent;
			Node* right = cur->_right;
			if (parent == NULL)
			{
				_root = right;
				if (right)
					right->_parent = NULL;
			}
			else if (parent->_left == cur)
			{
				parent->_left = right;
				if (right)
					right->_parent = parent;
			}
			else
			{
				parent->_right = right;
				if(right)
					right->_parent = parent;
			}
			delete cur;
			return true;
		}
		if (cur->_right == NULL)
		{
			Node* parent = cur->_parent;
			Node* left = cur->_left;
			if (parent == NULL)
			{
				_root = left;
				if(left)
					left->_parent = NULL;
			}
			else if (parent->_left == cur)
			{
				parent->_left = left;
				if(left)
					left->_parent = parent;
			}
			else
			{
				parent->_right = left;
				if(left)
					left->_parent = parent;
			}
			delete cur;
			return true;
		}

		//双支
		Node* p = cur->_left;
		Node* prev = p;
		while (p)
		{
			prev = p;
			p = p->_right;
		}
		swap(prev->_key,cur->_key);
		swap(prev->_value,cur->_value);
		Node* parent = prev->_parent;
		if (prev == parent->_left)
		{
			parent->_left = prev->_left;
		}
		else
		{
			parent->_right = prev->_left;
		}
		delete prev;
		return true;
	}

	void Order()
	{
		_Order(_root);
	}


private:
	void _Order(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Order(root->_left);
		cout << root->_key << endl;
		_Order(root->_right);
	}
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

	bool _Insert(const K key,const V value,Node* &root,Node* parent)
	{
		if (root == NULL)
		{
			root = new Node(key,value);
			root->_parent = parent;
			return true;
		}
		if (key < root->_key)
		{
			return _Insert(key,value,root->_left,root);
		}
		else
		{
			return _Insert(key,value,root->_right,root);
		}
	}

	Node* Find(const K key,Node* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_key == key)
		{
			return root;
		}
		if (key < root->_key)
		{
			return Find(key,root->_left);
		}
		else
		{
			return Find(key,root->_right);
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
	tree.InsertR(1, 1);

	tree.Order();

	tree.Erase(2);
	tree.Erase(8);
	tree.Erase(5);
	tree.Erase(3);
	tree.Erase(9);
	tree.Erase(6);
	tree.Erase(0);
	tree.Erase(1);
	

	cout<<tree.Search(2)<<endl;
	cout << tree.SearchR(2)<<endl;


}