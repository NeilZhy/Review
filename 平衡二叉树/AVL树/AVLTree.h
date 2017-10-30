#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(K key = 0,V value = 0)
	:_left(NULL)
	, _right(NULL)
	, _parent(NULL)
	, _bf(0)
	, _key(key)
	, _value(value)
	{
	}

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	K _key;
	V _value;

};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(K key, V value)
	{
		if (!_root)
		{
			_root = new Node(key,value);
			return true;
		}

		//找位置插入
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
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key < prev->_key)
		{
			
			prev->_left = cur;
			cur->_parent = prev;
		}
		else
		{
			prev->_right = cur;
			cur->_parent = prev;
		}

		//调整平衡因子并旋转
		Node* parent = cur->_parent;
		while (parent) //思考一下这里的判断是否有问题
		{
			if (parent->_left == cur)
			{
				--(parent->_bf);
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						Rxun(parent);
					}
					if (cur->_bf == 1)
					{
						LRxun(parent);
					}
					break;
				}
				if (parent->_bf == 0)
				{
					break;
				}
			}
			else
			{
				++(parent->_bf);
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						Lxun(parent);
					}
					if (cur->_bf == -1)
					{
						RLxun(parent);
					}
					break;
				}
				if (parent->_bf == 0)
				{
					break;
				}
			}
			cur = parent;
			parent = parent->_parent;
			
		}
		return true;
	}

	bool IsAVL()
	{
		int num = 0;
		return _IsAVL(_root,num);
	}

private:
	bool _IsAVL(Node* root, int& hight)  //根据高度来判断,这里想从最后往上走，来查找每个树的高度，
		//所以这里是后序遍历思想,时间复杂度是O(n)
	{
		if (root == NULL)
		{
			return true;
		}

		int lefthight = hight;
		if (_IsAVL(root->_left, lefthight) == false)
		{
			return false;
		}
		
		int righthight = hight;
		if(_IsAVL(root->_right, righthight) == false)
		{
			return false;
		}
		

		if (abs(lefthight - righthight) < 2)
		{
			lefthight > righthight ? (hight = lefthight + 1) : (hight = righthight + 1);
			return true;
		}
		return false;
	}

	void Rxun(Node* parent)
	{
		Node* pprent = parent->_parent;
		Node* left = parent->_left;
		Node* leftright = left->_right;
		parent->_left = leftright;
		if (leftright)
		{
			leftright->_parent = parent;
		}
		left->_right = parent;
		parent->_parent = left;
		if (pprent)
		{
			left->_parent = pprent;
			if (pprent->_left == parent)
			{
				pprent->_left = left;
			}
			else
			{
				pprent->_right = left;
			}
		}
		else
		{
			left->_parent = NULL;
			_root = left;
		}
		parent->_bf = 0;
		left->_bf = 0;
	}

	void RLxun(Node* parent)
	{
		Node* p = parent;
		Node* sub = p->_right;
		int num = sub->_left->_bf;
		Rxun(parent->_right);
		Lxun(parent);
		if (num == 1)
		{
			p->_bf = -1;
		}
		else
		{
			sub->_bf = 1;
		}
		
	}

	void Lxun(Node* parent)
	{
		Node* pprent = parent->_parent;
		Node* right = parent->_right;
		Node* rightleft = right->_left;
		parent->_right = rightleft;
		if (rightleft)
		{
			rightleft->_parent = parent;
		}
		right->_left = parent;
		parent->_parent = right;
		if (pprent)
		{
			right->_parent = pprent;
			if (pprent->_right == parent)
			{
				pprent->_right = right;
			}
			else
			{
				pprent->_left = right;
			}
		}
		else
		{
			right->_parent = NULL;
			_root = right;
		}
		parent->_bf = 0;
		right->_bf = 0;
	}
	void LRxun(Node* parent)
	{
		Node* p = parent;
		Node* sub = p->_left;
		int num = sub->_right->_bf;
		Lxun(parent->_left);
		Rxun(parent);
		if (num == 1)
		{
			p->_bf = -1;
		}
		else
		{
			sub->_bf = 1;
		}
	}
private:
	Node* _root;
};

void test()
{
	AVLTree<int, int> tree;
	tree.Insert(16,1);
	tree.Insert(3, 1);
	tree.Insert(7, 1);
	tree.Insert(11, 1);
	tree.Insert(9, 1);
	tree.Insert(26, 1);
	tree.Insert(18, 1);
	tree.Insert(14, 1);
	tree.Insert(15, 1);


	cout << tree.IsAVL()<<endl;


	AVLTree<int, int> tre;
	tre.Insert(4, 1);
	tre.Insert(2, 1);
	tre.Insert(7, 1);
	tre.Insert(1, 1);
	tre.Insert(3, 1);
	tre.Insert(6, 1);
	tre.Insert(15, 1);
	tre.Insert(8, 1);
	tre.Insert(16, 1);
	tre.Insert(14, 1);
	tre.Insert(5, 1);

	cout << tre.IsAVL() << endl;


	AVLTree<int, int> tre1;
	
	tre1.Insert(7, 1);
	
	tre1.Insert(6, 1);
	tre1.Insert(15, 1);
	tre1.Insert(5, 1);
	tre1.Insert(14, 1);
	tre1.Insert(16, 1);
	tre1.Insert(4, 1);


	cout << tre1.IsAVL() << endl;

	AVLTree<int, int> t;
	t.Insert(3, 1);
	t.Insert(1, 1);
	t.Insert(6, 1);
	t.Insert(0, 1);
	t.Insert(2, 1);
	t.Insert(5, 1);
	t.Insert(15, 1);
	t.Insert(7, 1);
	t.Insert(16, 1);
	t.Insert(14, 1);
	t.Insert(-1, 1);
	t.Insert(4, 1);

	cout << t.IsAVL() << endl;

}