#include<iostream>
using namespace std;

//  {}

template<T>
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
class binaryTree
{

};