#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
namespace zjh
{
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
						if (parent&&parent->_left==cur)
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

		//判断是不是红黑树
		bool Is_RBTree()
		{
			//检查头节点的颜色
			if (_root->_col != BLACK)
				return false;
			//选去最左边的路径计算黑色节点数量
			Node* cur = _root;
			int benchmark = 0;
			while (cur)
			{
				if (cur->_col == BLACK)
				{
					++benchmark;
				}
				cur = cur->_left;
			}
			//检查每条路径的黑色节点数量是否相等
			if (CheckColour(_root, 0, benchmark) == false)
				return false;
			int Min = MinHight(_root);
			int Max = MaxHight(_root);
			if ((double)Max / Min > (double)2)
				return false;
			return true;
		}

		//颜色检查
		bool CheckColour(Node* root,int blacknum,int benchmark)
		{
			if (root == nullptr)
			{
				if (blacknum != benchmark)
				{
					cout <<_root->_kv.first<<' ' << "各路径黑色节点不同" << endl;
					return false;
				}
				return true;
			}
			//判断是否有连续得红节点
			if (root->_col == RED && root->_parent && root->_parent->_col == RED)
			{
				cout << _root->_kv.first << _root->_parent->_kv.first << "红色节点连续" << endl;
				return false;
			}
			//计算黑色节点的个数
			if (root->_col == BLACK)
			{
				++blacknum;
			}

			return CheckColour(root->_left, blacknum, benchmark) && CheckColour(root->_right, blacknum, benchmark);

		}
		//bool Is_RBTree(Node* root)
		//{
		//	if (root == NULL)
		//		return true;

		//	if (root->_col == RED && root->_parent->_col == RED)
		//	{
		//		return false;
		//	}
		//	if (MaxHight() / 2 > MinHight())
		//	{
		//		return false;
		//	}
		//	if (BEqual(root) == false)
		//		return false;
		//	return true;
		//}
		////各路径的黑色节点树是否相等
		//bool BEqual(Node*root)
		//{
		//	if (root == nullptr)
		//		return true;
		//	bool BL=BEqual(root->_left);
		//	bool BR=BEqual(root->_right);
		//	int Lsize = Bsize(root->_left);
		//	int Rsize = Bsize(root->_right);
		//	if (Lsize == -1 || Rsize == -1)
		//		return false;
		//	return BL && BR;
		//}
		//int Bsize(Node* root)
		//{
		//	if (root == nullptr)
		//		return 0;
		//	if (root->_col == BLACK)
		//		return 1;
		//	int Bleft = Bsize(root->_left);
		//	int Bright = Bsize(root->_right);
		//	return Bleft == Bright ? Bleft : -1;
		//}
		
		//高度计算
		int MaxHight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int Hleft = MaxHight(root->_left);
			int Hright = MaxHight(root->_right);
			return (Hleft > Hright ? Hleft : Hright) + 1;
		}
		int MinHight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int Hleft = MinHight(root->_left);
			int Hright = MinHight(root->_right);
			return (Hleft < Hright ? Hleft : Hright) + 1;
		}
		void Inorder()
		{
			Inorder(_root);
		}
		void Inorder(Node* root)
		{
			if (root == nullptr)
				return;
			Inorder(root->_left);
			cout << root->_kv.first << ' ';
			Inorder(root->_right);

		}
		private:
			Node* _root=nullptr;
	};
}
