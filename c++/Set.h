#pragma once
#include<iostream>
using namespace std;
namespace zjy
{
	template<class K,class V>
	struct Iterator
	{
		typedef RBTreeNode<K, V> Node;
		Iterator(const Node& node)
			:_node(node)
		{}
		Node* _node = nullptr;
	};
	//封装
	template<class K,class V>
	class Set
	{
	public:
		bool Insert(const V& val)
		{
			return _t.Insert(make_pair(val, val));
		}

	private:
		RBTree<K, V> _t;
	};

	//底层红黑树
	enum Colour
	{
		RED,
		BLACK
	};
	template<class K, class V>
	struct RBTreeNode
	{
		pair<K, V> _kv;
		RBTreeNode* _left;//左节点
		RBTreeNode* _right;//右节点
		RBTreeNode* _parent;//父节点
		Colour _col;
		RBTreeNode(const pair<K, V>& kv)
			:_kv(kv)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(RED)
		{}
	};

	template<class K, class V>
	class RBTree
	{
		typedef  RBTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			//找到新增kv的插入位置
			while (cur)
			{
				if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			//插入kv
			cur = new Node(kv);
			if (kv.first > parent->_kv.first)
			{
				parent->_right = cur;
				//cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				//cur->_parent = parent;
			}
			cur->_parent = parent;
			while (parent && parent->_col == RED)
			{
				Node* grandparent = parent->_parent;
				if (grandparent->_left == parent)
				{
					Node* uncle = grandparent->_right;
					if (uncle && parent->_col == RED && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//    g
						//  p
						//c
						if (parent && parent->_left == cur)
						{
							RotateR(grandparent);
						}
						//    g
						//  p
						//    c
						else
						{
							RotateLR(grandparent);
						}
						cur = grandparent;
						parent = cur->_parent;
					}
				}
				else
				{
					Node* uncle = grandparent->_left;
					if (uncle && parent->_col == RED && uncle->_col == RED)
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						// g
						//   p
						//     c
						if (parent && parent->_right == cur)
						{
							RotateL(grandparent);
						}
						// g
						//   p
						// c
						else
						{
							RotateRL(grandparent);
						}
						cur = grandparent;
						parent = cur->_parent;
					}
				}


			}
			_root->_col = BLACK;
			return true;

		}
		//左单旋
		void RotateL(Node* parent)
		{
			//旋转
			Node* cur = parent->_right;
			Node* curleft = cur->_left;
			parent->_right = curleft;
			if (curleft)
			{
				curleft->_parent = parent;
			}
			cur->_left = parent;
			Node* ppNode = parent->_parent;
			parent->_parent = cur;
			//变色
			parent->_col = RED;
			cur->_col = BLACK;
			//将节点对接
			if (ppNode == NULL)
			{
				_root = cur;
			}
			else if (ppNode->_left == parent)
			{
				ppNode->_left = cur;
			}
			else if (ppNode->_right == parent)
			{
				ppNode->_right = cur;
			}
			else
			{
				assert(false);
			}
			cur->_parent = ppNode;
		}
		//右单旋
		void RotateR(Node* parent)
		{
			//旋转
			Node* cur = parent->_left;
			Node* curright = cur->_right;
			parent->_left = curright;
			if (curright)
			{
				curright->_parent = parent;
			}
			cur->_right = parent;
			Node* ppNode = parent->_parent;
			parent->_parent = cur;
			//变色
			parent->_col = RED;
			cur->_col = BLACK;
			//将节点对接
			if (ppNode == NULL)
			{
				_root = cur;
			}
			else if (ppNode->_left == parent)
			{
				ppNode->_left = cur;
			}
			else if (ppNode->_right == parent)
			{
				ppNode->_right = cur;
			}
			else
			{
				assert(false);
			}
			cur->_parent = ppNode;
		}
		//右左旋
		void RotateRL(Node* parent)
		{
			Node* cur = parent->_right;
			Node* curleft = cur->_left;
			RotateR(cur);
			RotateL(parent);
			curleft->_col = BLACK;
			cur->_col = RED;
			parent->_col = RED;
		}
		//左右旋
		void RotateLR(Node* parent)
		{
			Node* cur = parent->_left;
			Node* curright = cur->_right;
			RotateL(cur);
			RotateR(parent);
			curright->_col = BLACK;
			cur->_col = RED;
			parent->_col = RED;

		}
		
	private:
		Node* _root = nullptr;
	};
}