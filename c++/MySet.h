#pragma once
#include<iostream>
#include<set>
#include<assert.h>
using namespace std;
namespace zjh
{
	//颜色枚举
	enum Colour
	{
		RED,
		BLACK
	};
	template<class T>
	struct RBTreeNode
	{
		T _data;
		RBTreeNode* _left;//左节点
		RBTreeNode* _right;//右节点
		RBTreeNode* _parent;//父节点
		Colour _col;
		RBTreeNode(const T& data)
			:_data(data)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(RED)
		{}
	};

	
	//迭代器
	template<class T, class Ptr, class Ref>
	struct TreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef TreeIterator<T, Ptr, Ref> Self;
		typedef TreeIterator<T, Ptr, Ref> Self;
		typedef TreeIterator<T, T*, T&> iterator;
		TreeIterator(const iterator& it)
			:_node(it._node)
		{}
		TreeIterator(Node* node)
			:_node(node)
		{}
		Node* _node = nullptr;
		Self& operator++()
		{
			//判空
			if (_node == nullptr)
				return *this;
			if (_node->_right)
			{
				//找到最左边那个节点
				_node = _node->_right;
				while (_node->_left)
				{
					_node = _node->_left;
				}
			}
			else
			{
				Node* parent = _node->_parent;
				while (parent&&_node == parent->_right)
				{
					_node = parent;
					parent = _node->_parent;
				}
				_node = parent;
			}
			return *this;
		}
		//解引用
		Ref operator*()
		{
			return _node->_data;
		}
		//箭头
		Ptr operator->()
		{
			return &(_node->_data);
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

	};

	//底层红黑树
	template<class K, class T,class KeyOfT>
	class RBTree
	{
	public:

		typedef  RBTreeNode<T> Node;
		typedef	 TreeIterator<T, T*, T&> Iterator;
		typedef	 TreeIterator<T, const T*, const T&> const_Iterator;
	
		pair<Iterator,bool> Insert(const T& data)
		{
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;
				return make_pair(_root,true);
			}
			Node* cur = _root;
			Node* parent = nullptr;
			KeyOfT kot;
			//找到新增data的插入位置
			while (cur)
			{
				
				if (kot(data) > kot(cur->_data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(data) < kot(cur->_data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(cur,false);
				}
			}
			//插入data
			cur = new Node(data);
			Node* newnode = cur;
			if (kot(data) > kot(parent->_data))
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
			return make_pair(newnode,true);

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
		Iterator begin()
		{
			Node* leftMin = _root;
			while (leftMin&&leftMin->_left)
			{
				leftMin = leftMin->_left;
			}
			return Iterator(leftMin);
		}
		Iterator end()
		{
			return Iterator(nullptr);
		}
		const_Iterator begin()const
		{
			Node* leftMin = _root;
			while (leftMin && leftMin->_left)
			{
				leftMin = leftMin->_left;
			}
			return const_Iterator(leftMin);
		}
		const_Iterator end()const
		{
			return const_Iterator(nullptr);
		}

		Node* Find(const K& Key)
		{
			KeyOfT kot;
			Node* cur = _root;
			while (cur)
			{
				if (Key > kot(cur->_data))
				{
					cur = cur->_right;
				}
				else if (Key < kot(cur->_data))
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;

			
			/*const_Iterator it = begin();
			while(it != end())
			{
				if (kot(it._node->_data) == Key)
					return it;
				++it;
			}
			return const_Iterator(nullptr);*/
		}
	private:
		Node* _root = nullptr;
	};

	
	//封装
	template<class K>
	class Set
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& Key)
			{
				return Key;
			}
		};
		typedef typename RBTree<K, K,SetKeyOfT>::const_Iterator Iterator;
		typedef typename RBTree<K, K,SetKeyOfT>::const_Iterator const_Iterator;
		
		pair<Iterator,bool> Insert(const K& Key)
		{
			pair<RBTree<K, K, SetKeyOfT>::Iterator,bool> ret = _t.Insert(Key);
			return pair<Iterator, bool>(ret.first, ret.second);
			/*return _t.Insert(Key);*/
		}
		Iterator begin()
		{
			return _t.begin();
		}
		Iterator end()
		{
			return _t.end();
		}
		Iterator Find(const K& Key)
		{
			return _t.Find(Key);
		}
		/*const K& operator[](const K& key)
		{
			pair<Iterator, bool> ret = _t.Insert(key);
			return *ret.first;
		}*/
	private:
		RBTree<K, K,SetKeyOfT> _t;
	};

}