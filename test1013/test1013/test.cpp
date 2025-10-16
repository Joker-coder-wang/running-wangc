#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"list.h"

namespace wh
{
	//可修改it指向的内容
	void test_list1()
	{
		wh::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
	}

	//不修改it指向内容
	void print(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
	}
}
int main()
{
	return 0;
}