#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"list.h"

namespace wh
{
	struct Pos
	{
		int _row;
		int _col;

		Pos(int row=0,int col=0)
			:_row(row)
			,_col(col)
		{}
	};

	void test_list03()
	{
		wh::list<Pos> lt1;
		lt1.push_back({ 1,1 });
		lt1.push_back({ 2,2 });
		lt1.push_back({ 3,3 });
		lt1.push_back({ 4,4 });

		auto it = lt1.begin();
		while (it != lt1.end())
		{
			std::cout << it->_row <<':'<< it->_col << std::endl;
			++it;
		}
		std::cout << std::endl;
	}
	template<class T>
	void print(const list<T>& lt)
	{
		//模板参数，由于类模板没有实例化，没有具体东西，所以编译器不敢去找
		//编译器分不清const_iterator是嵌套内类，还是静态成员变量
		// typename告诉编译器，我确认过了这里是类型
		// list<T>::const_iterator it = lt.begin();
		//typename list<T>::const_iterator it = lt.begin();
		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void test_list04()
	{
		wh::list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		lt1.push_front(10);
		lt1.push_front(20);
		print(lt1);

		lt1.pop_back();
		lt1.pop_back();
		print(lt1);

		lt1.pop_front();
		lt1.pop_front();
		print(lt1);
	}
	void test_list05()
	{
		wh::list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		wh::list<int> lt2 = lt1;
		print(lt2);
	}
}

int main()
{
	wh::test_list03();
	return 0;
}