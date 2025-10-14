#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"list.h"

namespace wh
{
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
			
			++it;
		}
	
	}
}
int main()
{
	return 0;
}