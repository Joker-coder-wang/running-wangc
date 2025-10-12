#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

namespace wh
{
	template<class T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	void swap(int a, int b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
}

int main()
{
	int a = 3, b = 8;
	double c = 3.4, d = 8.0;
	wh::swap(a, b);
	wh::swap((int)c, (int)d);
	return 0;
}