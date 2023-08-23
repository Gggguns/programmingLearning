#pragma once
#include<iostream>
#include<stdbool.h>
#include<time.h>
using namespace std;

namespace Key
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
		BinarySearchTree(const BinarySearchTree& BST)
		{
			_root = copy(BST._root);
		}
		~BinarySearchTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		//赋值重载
		BinarySearchTree& operator=(BinarySearchTree BST)
		{
			swap(BST._root, _root);
			return *this;
		}
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
		//递归插入
		bool InsertR(const K&key)
		{
			return _InsertR(_root, key);
		}
		//中序遍历
		void Inorder()
		{
			_Inorder(_root);
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
		//递归删除
		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
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
		//递归查找
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
	private:
		//拷贝二叉搜索树
		BSTreeNode* copy(BSTreeNode* root)
		{
			if (root == nullptr)
				return nullptr;
			BSTreeNode* copyroot = new BSTreeNode(root->_key);
			copyroot->_left = copy(root->_left);
			copyroot->_right = copy(root->_right);
			return copyroot;
		}
		//析构的子函数
		void Destroy(BSTreeNode* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		//递归删除的子函数
		bool _eraseR(BSTreeNode*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key > key)
			{
				_eraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_eraseR(root->_right, key);
			}
			else
			{
				
				if (root->_left == nullptr)
					root = root->_right;
				else if (root->_right == nullptr)
					root = root->_left;
				else
				{
					BSTreeNode* leftMax = root->_left;
					while(leftMax->_right)
					{
						leftMax = leftMax->_right;
					}
					swap(root->_key, leftMax->_key);
					_eraseR(root->_left, key);
					delete leftMax;
				}
				
			}
		}
		//递归查找的子函数
		bool _FindR(BSTreeNode* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key > key)
			{
				_FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}
		//递归插入的子函数
		bool _InsertR(BSTreeNode*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new BSTreeNode(key);
				return true;
			}
			if (root->_key > key)
				_InsertR(root->_left, key);
			else if (root->_key < key)
			{
				_InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		//中序遍历子函数
		void _Inorder(BSTreeNode* root)
		{
			if (root == NULL)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << ' ';
			_Inorder(root->_right);
		}
		BSTreeNode* _root;

	};
}

namespace Key_value
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
		BinarySearchTree(const BSTreeNode& root)
		{
			_root = copy(root);
		}
		~BinarySearchTree()
		{
			Destroy(_root);
			_root = nullptr;
		}
		
		//递归插入
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		//中序遍历
		void Inorder()
		{
			_Inorder(_root);
		}
				
		//递归删除
		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
		}

		//递归查找
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
	private:
		//拷贝二叉搜索树
		BSTreeNode* copy(BSTreeNode* root)
		{
			if (root == nullptr)
				return nullptr;
			BSTreeNode* copyroot = new BSTreeNode(root->_key);
			copyroot->_left = copy(root->_left);
			copyroot->_right = copy(root->_right);
			return copyroot;
		}
		//析构的子函数
		void Destroy(BSTreeNode* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		//递归删除的子函数
		bool _eraseR(BSTreeNode*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key > key)
			{
				_eraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_eraseR(root->_right, key);
			}
			else
			{

				if (root->_left == nullptr)
					root = root->_right;
				else if (root->_right == nullptr)
					root = root->_left;
				else
				{
					BSTreeNode* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}
					swap(root->_key, leftMax->_key);
					_eraseR(root->_left, key);
					delete leftMax;
				}

			}
		}
		//递归查找的子函数
		bool _FindR(BSTreeNode* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key > key)
			{
				_FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}
		//递归插入的子函数
		bool _InsertR(BSTreeNode*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new BSTreeNode(key);
				return true;
			}
			if (root->_key > key)
				_InsertR(root->_left, key);
			else if (root->_key < key)
			{
				_InsertR(root->_right, key);
			}
			else
			{
				return false;
			}
		}
		//中序遍历子函数
		void _Inorder(BSTreeNode* root)
		{
			if (root == NULL)
			{
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << ' ';
			_Inorder(root->_right);
		}
		BSTreeNode* _root;

	};
}