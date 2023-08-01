#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;
namespace zjh
{
	template<class T>
	struct list_node
	{
		list_node* prev;
		list_node* next;
		T value;

		list_node()
			:prev(nullptr)
			,next(nullptr)
			,value(T())
		{}
	};
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		
		typedef list_iterator<T, Ref, Ptr> self;
		list_node<T>* _node;
		//list_iterator的初始化
		list_iterator(list_node<T>& node)
		{
			_node = node;
		}
		list_iterator()
		{}

		//list_iterator的拷贝
		list_iterator(const self& x)
			:_node(x)
		{}
		//重载运算符*
		T&  operator*()
		{
			return _node->value;
		}

		//重载运算符++
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self operator++(int)
		{
			self ret = *this;
			_node = _node->next;
			return ret;
		}
		//重载运算符->
		T* operator->()
		{
			return &(_node->value);
		}
		//重载运算符--
		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}
        self operator--(int)
		{
			self ret = *this;
			_node = _node->prev;
			return ret;
		}
		bool operator!=(const self& l)
		{
			return _node == l._node;
		}
		//        bool operator==(const Self& l);
	};
	template<class T>
	class list
	{
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		typedef list_node<T> Node;
	public:
		void empty_init()
		{
			_head = new Node;
			_head->next = _head;
			_head->prve = _head;
		}
		list()
		{
			empty_init();
		}
		list(int n, const T& value = T())
		{
			empty_init();
			int i = 0;
			for (i = 0;i < n;i++)
			{
				Node* node = new Node(value);
				node->next = _head->next;
				_head->next->prev = node;
				node->prev = _head;
				_head->next = node;
			}
		}
		template <class iterator>
		list(iterator first, iterator last)
		{
			empty_init();
			zjh::list<T>::iterator it = first;
			while (it != last)
			{
				Node* node = new Node;
				*node = *it++;
				node->prev = _head->prev;
				_head->prev->next = node;
				node->next = _head;
				_head->prev = node;
			}
		}
		list(const list<T>& l)
		{
			empty_init();
			zjh::list<T>::iterator it = l.begin();
			while (it != l.end())
			{
				Node* node = new Node;
				*node = *it++;
				node->prev = _head->prev;
				_head->prev->next = node;
				node->next = _head;
				_head->prev = node;
			}
		}
		//list<T>的交换
		void Swap(list<T>& l)
		{
			std::swap(_head, l._head);
		}
		list<T>& operator=(const list<T> l)
		{
			list<T> ret;
			ret.Swap(l);
			return ret;
		}

		iterator begin()
		{
			return _head->next;
		}
		iterator end()
		{
			return _head;
		}
		~list()
		{
			;
		}
	private:
		Node* _head;
	};
	
}
