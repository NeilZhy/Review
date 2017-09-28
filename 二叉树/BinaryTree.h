#include<iostream>
using namespace std;
#include<queue>

//  {}

template<class T>
struct TreeNode
{
	T _data;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	
	TreeNode(T data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef TreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(const T* arr,const T& inval,const size_t& n)
	{
		size_t index = 0;
		_root = _CreatTree(arr,n,index,inval);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void EndOrder()
	{
		_EndOrder(_root);
		cout << endl;
	}

	void LevelOrder()
	{
		queue<Node*> que;
		if (_root)
		{
			que.push(_root);
		}
		while (!que.empty())
		{
			Node* cur = que.front();
			que.pop();
			cout << cur->_data << " ";
			if (cur->_left)
			{
				que.push(cur->_left);
			}
			if (cur->_right)
			{
				que.push(cur->_right);
			}
		}
		cout << endl;
	}

	int NodeNum()
	{
		return _NodeNum(_root);
	}

	int LeafNum()
	{
		return _LeafNum(_root);
	}

	//求叶子节点的个数，和下面的配合着中也是正确的
	/*int LeafNum()
	{
		int num = 0;
		_LeafNum(_root,num);
		return num;
	}*/

	int LevelNodeNum(int k)
	{
		return _LevelNodeNum(_root,k);
	}

	int High()
	{
		return _High(_root);
	}

	Node* Find(T data)
	{
		return _Find(_root,data);
	}

private:
	Node* _CreatTree(const T* arr,const size_t& n,size_t& index,const T& inval)
	{
		Node* root = NULL; 
		if (arr[index] != inval && index < n)
		{
			root = new Node(arr[index]);
			root->_left = _CreatTree(arr,n,++index,inval);
			root->_right = _CreatTree(arr,n,++index,inval);
		}
		return root;
	}

	void _PrevOrder(Node* root)
	{
		if (root != NULL)
		{
			cout << root->_data << " ";
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
	}

	void _InOrder(Node* root)
	{
		if (root != NULL)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	void _EndOrder(Node* root)
	{
		if (root != NULL)
		{
			_EndOrder(root->_left);
			_EndOrder(root->_right);
			cout << root->_data << " ";
		}
	}

	int _NodeNum(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return _NodeNum(root->_left) + _NodeNum(root->_right) + 1;
	}

	int _LeafNum(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		if ((root->_left == NULL) && (root->_right == NULL))
		{
			return 1;
		}
		return _LeafNum(root->_left) + _LeafNum(root->_right);
	}

	//求叶子节点的个数，仅供参考，也是正确的
	/*void _LeafNum(Node* root,int& num)
	{
		if ((root->_left == NULL) && (root->_right == NULL))
		{
			++num;
		}
		if (root->_left)
		{
			_LeafNum(root->_left,num);
		}
		if (root->_right)
		{
			_LeafNum(root->_right,num);
		}
	}*/

	int _LevelNodeNum(Node* root,int k)
	{
		if (root == NULL)
			return 0;
		if ((k == 1) && (NULL != root) )
			return 1;
		else
		{
			return _LevelNodeNum(root->_left, k - 1) + _LevelNodeNum(root->_right, k - 1);
		}
	}

	int _High(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int l = _High(root->_left);
		int r = _High(root->_right);

		if (l > r)
			return l + 1;
		else
			return r + 1;
	}

	Node* _Find(Node* root,T data)
	{
		if (NULL == root)
		{
			return NULL;
		}
		else
		{
			if (root->_data == data)
			{
				return root;
			}
			Node* ret = _Find(root->_left,data);
			if (ret)
			{
				return ret;
			}
			ret = _Find(root->_right,data);
		}
	}

private:
	Node* _root;
};

void TestTree()
{
	int arr[] = {1,2,0,3,0,0,4,5,0,6,0,7,0,0,8};
	BinaryTree<int> tree(arr,0,15);
	tree.PrevOrder();
	tree.InOrder();
	tree.EndOrder();
	tree.LevelOrder();
	/*cout << tree.NodeNum() << endl;
	cout << tree.LeafNum() << endl;*/
	cout << tree.LevelNodeNum(4) << endl;
	cout << tree.High() << endl;
	cout << tree.Find(5)->_data << endl;



}