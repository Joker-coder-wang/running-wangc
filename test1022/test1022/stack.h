#pragma once
#include<vector>
#include<list>
#include<deque>


namespace wh
{
// 适配器/配接器
// 容器适配器 用容器适配转换出我们所需要的栈，具体什么容器，我也不知道
template<class T, class Container = deque<T>>
class stack// vector/list/deque
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	}
	void pop()
	{
		_con.pop_back();//后进先出
	}
	size_t size() const
	{
		return _con.size();
	}
	bool empty() const
	{
		return _con.empty();
	}
	const T& top() const
	{
		return _con.back();
	}
	T& top()
	{
		return _con.back();
	}
		
private:
	Container _con;
	}; 
}