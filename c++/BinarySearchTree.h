#pragma once
#include<iostream>
#include<stdbool.h>
#include<time.h>
using namespace std;

namespace zjh
{
	template<class K>
	struct BinarySearchTreeNode
	{
		K _key;
		BinarySearchTreeNode* _left;
		BinarySearchTreeNode* _right;
		BinarySearchTreeNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};
	template<class K>
	class BinarySearchTree
	{
		typedef BinarySearchTreeNode<K> BSTreeNode;
	public:
		BinarySearchTree()
			:_root(nullptr)
		{}

		//插入
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new BSTreeNode(key);
				return true;
			}
			BSTreeNode* cur;
			BSTreeNode* parent;
			cur = _root;
			parent = nullptr;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;
				}
			}
			cur = new BSTreeNode(key);
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
			
		}
		//中序遍历
		void Inorder()
		{
			_Inorder(_root);
		}
		void _Inorder(BSTreeNode* root)
		{
			if (root==NULL)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << ' ';
			_Inorder(root->_right);
		}
		//删除
		bool erase(const K& key)
		{
			BSTreeNode* cur = _root;
			BSTreeNode* parent = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					if (cur->_right == nullptr)
					{
						//根节点删除
						if (cur == _root)
						{
							_root = cur->_left;
						}
						if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
					else if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						if (parent->_right == cur)
						{
							parent->_right = cur->_right;
						}
						else
						{
							parent->_left = cur->_right;
						}
					}
					else
					{

						BSTreeNode* leftMax = cur->_left;
						parent = cur;
						while (leftMax->_right)
						{
							parent = leftMax;
							leftMax = leftMax->_right;
						}
						swap(leftMax->_key, cur->_key);
						if (parent->_right == leftMax)
							parent->_right = leftMax->_left;
						else
							parent->_left = leftMax->_left;
						cur=leftMax;
						
					}
					delete cur;
					return true;
				}
			}
			return false;
		}
		//查找
		bool Find(const K& key)
		{
			BSTreeNode* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
	private:
		BSTreeNode* _root;
	};
}

