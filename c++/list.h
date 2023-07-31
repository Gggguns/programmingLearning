#pragma once
#include<iostream>
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
	template<class T>
	struct list_iterator
	{
		list_node* node;
	};
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		list()
		{
			_head = new Node;
			_head->next = _head;
			_head->prve = _head;
		}
		~list()
		{
			;
		}
	private:
		Node* _head;
	};
	
}
