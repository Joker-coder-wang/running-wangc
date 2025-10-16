#pragma once

namespace wh
{
	template<class T>
	//定义结点
	struct list_node//使用struct：默认所有成员均是公有
	{
		T _date;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_date(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template<class T>
	struct __list_iterator//内部使用的类
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}


		//__list_iterator<T>& operator++()
		//{
		//	node = node->next;
		//	return *this;
		//}

		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		__list_iterator<T>& operator++(int)
		{
			__list_iterator<T> tmp(*this);//拷贝构造
			_node = _node->_next;
			return tmp;
		}

		__list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		__list_iterator<T>& operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}
		bool operator==(const __list_iterator<T>& it)
		{
			return _node == it._node;
		}
		T& operator*()
		{
			return _node->_date;
		}

		//__list_iterator<T>& operator++()
		//{
		//	_node = _node->_next;
		//	return *this;
		//}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//void push_back(const T& x)
		//{
		//	Node* newnode = new Node(x);
		//	Node* tail = _head->_prev;
		//	//插入
		//	tail->next= newnode;
		//	newnode->_prev = tail
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}

		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			//插入
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head->_prev;
		}

	private:
		//设计哨兵位头结点
		Node* _head;
	};
}
