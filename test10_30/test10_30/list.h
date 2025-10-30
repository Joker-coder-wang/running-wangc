#pragma once


namespace wh
{
	template<class T>
	struct list_node
	{
		typedef list_node<T> Node;
		T     _data;
		Node* _next;
		Node* _prev;

		list_node(const T& x)
			:_data(x)
			,-next(nullptr)
			,_prev(nullptr)
		{}

	};

	template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()//引用做返回值类型，可修改返回值；同时减少拷贝提高效率
		{
			return _node->_data;
		}

		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		__list_iterator<T> operator++(int)
		{
			__list_iterator<T>* tmp(*this);
			_node = _node->next;
			return tmp;
		}
	};
}