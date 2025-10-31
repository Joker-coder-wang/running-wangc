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
			return *this;//引用---返回值 可修改
		}
		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->next;
			return tmp;//仅仅返回一个值
		}

		__list_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		__list_iterator<T> operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const __list_iterator<T>& it) const
		{
			return _node != it._node;
		}

		bool operator==(const __list_iterator<T>& it) const
		{
			return _node == it._node;
		}
	};

	template<class T>
	struct __list_const_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()//主要区别于此
		{
			return _node->_data;
		}

		__list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;//引用---返回值 可修改
		}
		__list_const_iterator<T> operator++(int)
		{
			__list_const_iterator<T> tmp(*this);
			_node = _node->next;
			return tmp;//仅仅返回一个值
		}

		__list_const_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		__list_const_iterator<T> operator--(int)
		{
			__list_const_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const __list_const_iterator<T>& it) const
		{
			return _node != it._node;
		}

		bool operator==(const __list_const_iterator<T>& it) const
		{
			return _node == it._node;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;
		typedef __list_const_iterator<T> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);//有效结点的下一个结点即为尾
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);//有效结点的下一个结点即为尾
		}
		list()
		{
			_head = new Node;
			_head->prev = _head;
			_head->next = _head;
		}
		~list()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase返回it的下一个位置，故要重新给it赋值
			}
			delete _head;
			_head = nullptr;
		}
		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			
			tail->_next = newnode;
			// tail newnode _head
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head;
	};
}