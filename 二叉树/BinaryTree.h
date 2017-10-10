#include<iostream>
using namespace std;
#include<queue>
#include<stack>

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

	void PrevNoROeder()
	{
		stack<Node*> sn;
		Node* cur = _root;
		
		//思路一：直接判断，当cur为NULL的时候，说明左子树已经是空的了，这个时候就让cur指向栈顶的右子树
		/*while (!sn.empty() || cur != NULL)  
		{
			if (cur == NULL)
			{
				cur = (sn.top())->_right;
				sn.pop();
			}
			else
			{
				cout << cur->_data << " ";
				sn.push(cur);
				cur = cur->_left;
			}
			
		}*/

		//思路二:外循环专门判断栈是不是为空的，内循环是当前节点的所有的左子树都入栈
	    //思路二的想法可能是更加的清晰一点的，有利于后面的其他的两种遍历的实现和理解
		while (cur || !sn.empty())
		{
			while (cur)
			{
				cout << cur->_data << " ";
				sn.push(cur);
				cur = cur->_left;
			}
			cur = (sn.top())->_right;
			sn.pop();
		}
		cout << endl;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void InNoROrder()
	{
		stack<Node*> sn;
		Node* cur = _root;
		
		while (cur || !sn.empty())
		{
			while (cur)
			{
				sn.push(cur);
				cur = cur->_left;
			}
			cout << (sn.top())->_data<<" ";
			cur = (sn.top())->_right;
			sn.pop();
		}
		cout << endl;
	}

	void EndOrder()
	{
		_EndOrder(_root);
		cout << endl;
	}

	void EndNoROrder()
	{
		stack<Node*> sn;
		Node* cur = _root;
		Node* prev = _root;
		while (cur || !sn.empty())
		{
			if (cur)		//让所有的左子树入栈
			{
				sn.push(cur);
				cur = cur->_left;
			}
			else		//所有的左子树都入栈了
			{
				if (((sn.top())->_right != NULL) && ((sn.top())->_right != prev))
				{
					cur = (sn.top())->_right;
				}
				else		//所有的左右子树都访问完毕了
				{
					cout << (sn.top())->_data<<" ";
					prev = sn.top();
					sn.pop();
				}
			}
		}
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

	bool IsTree()		//判断是不是完全二叉树
	{
		return _IsTree(_root);
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
			if (ret)
			{
				return ret;
			}
			return NULL;
		}
	}

	bool _IsTree(Node* root)  
	{
		Node* cur;
		queue<Node*> q;
		if (root)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			if (!cur)
			{
				break;
			}
			q.push(cur->_left);
			q.push(cur->_right);
		}
		while (!q.empty())
		{
			if (q.front())
			{
				return false;
			}
			q.pop();
		}
		return true;
	}

	/*bool IsTree2(Node* root)
	{
		queue<Node*> 
		bool NULLNode = false;
		if (root)
		{

		}
	}*/

private:
	Node* _root;
};

void TestTree()
{
	int arr[] = {1,2,3,0,0,4,0,0,5,6};
	BinaryTree<int> tree(arr,0,10);
	tree.PrevOrder();
	tree.PrevNoROeder();
	tree.InOrder();
	tree.InNoROrder();
	tree.EndOrder();
	tree.EndNoROrder();
	tree.LevelOrder();
	/*cout << tree.NodeNum() << endl;
	cout << tree.LeafNum() << endl;*/
	cout << tree.LevelNodeNum(4) << endl;
	cout << tree.High() << endl;
	cout << tree.Find(5)->_data << endl;
	cout << tree.IsTree() << endl;


}