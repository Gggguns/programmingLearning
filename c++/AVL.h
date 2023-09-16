#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace zjh
{
	template<class K,class V>
	struct AVLTreeNode
	{
		pair<K, V> _kv;
		AVLTreeNode* _left;//左节点
		AVLTreeNode* _right;//右节点
		AVLTreeNode* _parent;//父节点
		int _bf;//平衡因子 blance factor
		AVLTreeNode(const pair<K, V>& kv)
			:_kv(kv)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_bf(0)
		{}
	};

	template<class K, class V>
	class AVL
	{
		typedef  AVLTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
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
		
			while (parent)
			{
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else/* if (parent->_right == cur)*/
				{
					parent->_bf++;
				}
				
			
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = cur->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_right && parent->_right->_bf == 1 && parent->_bf == 2)
					{
						RotateL(parent);
					}
					else if (parent->_left && parent->_left->_bf == -1 && parent->_bf == -2)
					{
						RotateR(parent);
					}
					else if (parent->_left && parent->_left->_bf == 1 && parent->_bf == -2)
					{
						RotateLR(parent);
					}
					else if (parent->_right && parent->_right->_bf == -1 && parent->_bf == 2)
					{
						RotateRL(parent);
					}
					else
					{
						assert(false);
					}
				}
				else
				{
					assert(false);
				}
			}
			return true;
		}
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
			//平衡因子置零
			parent->_bf = 0;
			cur->_bf = 0;
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
			//平衡因子置零
			parent->_bf = 0;
			cur->_bf = 0;
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
		void RotateRL(Node* parent)
		{
			Node* cur = parent->_right;
			Node* curleft = cur->_left;
			int bf = curleft->_bf;
			RotateR(cur);
			RotateL(parent);
			if (bf == 0)
			{
				curleft->_bf = 0;
				cur->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				curleft->_bf = 0;
				cur->_bf = 0;
				parent->_bf = 1;
			}
			else if (bf == 1)
			{
				curleft->_bf = 0;
				cur->_bf = -1;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		void RotateLR(Node* parent)
		{
			Node* cur = parent->_left;
			Node* curright = cur->_right;
			int bf = curright->_bf;
			RotateL(cur);
			RotateR(parent);
			if (bf == 0)
			{
				curright->_bf = 0;
				cur->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == -1)
			{
				curright->_bf = 0;
				cur->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == 1)
			{
				curright->_bf = 0;
				cur->_bf = 1;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
	private:
		Node* _root = nullptr;
	};
}