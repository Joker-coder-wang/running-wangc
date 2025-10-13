#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
typedef int DateType;

namespace wh
{
	class stack
	{
		DateType* _a;
		size_t _top;
		size_t _capacity;
	};
}

namespace whh
{
	template<class T>//模板参数
	class stack
	{
	public:
		//stack(int n = 4)
		//{
		//	_a = new T[n];
		//	_top = 0;
		//	_capacity = n;
		//}
		stack(int n = 4)
			:_a(new T[n])
			, _top(0)
			, _capacity(n)
		{}
		~stack()
		{
			delete[] _a;
			_a = nullptr;
			_top = 0;
			_capacity = 0;
		}
		void push(const T& x);
	private:
		T&     _a;
		size_t _top;
		size_t _capacity;
	};

	template<class T>
	void stack<T>::push(const T& x)
	{

	}
}

int main()
{
	wh::stack st1;//试图让它成为int类型栈 无果
	wh::stack st2;//试图让它成为double类型的栈 无果

	whh::stack<int> st3;//类模板显示实例化
	whh::stack<double> st4;//double
	return 0;
}

