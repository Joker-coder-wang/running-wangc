#pragma once
#include <initializer_list>
#include <algorithm>

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
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator//内部使用的类
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T,Ref,Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_date;
		}
		Ptr operator->()
		{
			return &_node->_date;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self& operator++(int)
		{
			Self tmp(*this);//拷贝构造
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
		//这里不能实现，由于这里必须要调用const_iterator 但此方式走不通
		// const __list_iterator对象不能调用++
		//const T& operator*() const
		//{
		//	return _node->_date;
		//}
	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		//同一个类模板实例化出的两个不同类型
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_const_iterator<T,const T&,const T*> const_iterator;

		//const迭代 器->const修饰迭代器本身，导致const无法++，故不可实现
		//typedef const __list_iterator<T> const_iterator;

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		////lt2(lt) = lt1(this)
		//list(const list<T>& lt)
		//{
		//	//构造list
		//	_head = new Node;
		//	_head->_next = _head;
		//	_head->_prev = _head;

		//	//将lt1中数据依次插入lt2中
		//	for (const list<T>& e : lt)
		//	{
		//		push_back(e);
		//	}
		//}

		void empty_initial()
		{
			//构造list
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list(const list<T>& lt)
		{
			//优化
			empty_initial();
			//将lt1中数据依次插入lt2中
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}
		list(initializer_list<T> il)
		{
			empty_initial();
			for (const auto& e : il)
			{
				push_back(e);
			}
		}
		//lt1 = lt3
		list<T>& operator=(const list<T>& lt3)
		{
			if (this != &lt3)//判断是否是自己给自己赋值
			{
				clear();
				for (const auto& e : lt3)
				{
					push_back(e);
				}
			}
			return *this;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		list<T>& operator=(const list<T> lt3)
		{
			swap(lt3); 
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void clear()
		{
			it = begin();
			while (it != end())
			{
				it = erase(it);
			}
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

		void push_back(const T& val)
		{
			//插到pos的前一个位置
			insert(end(), val);
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(val);

			//prev newnode cur
			prev->_next = newnode;
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;

			++_size;//计数

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			//prev cur next
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			//不存在迭代器失效问题
			//构造匿名对象
			//return iterator(next);
			//or 单参数构造函数的隐式类型转换
			return next；
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		//指向的内容不可以修改，iterator自身可修改
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		size_t size() const
		{
			/*size_t _size = 0;
			for (auto& e : *this)
			{
				size++;
			}*/
			return _size;
		}

	private:
		//设计哨兵位头结点
		Node* _head;
		size_t _size = 0;
	};
}

