#define  _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

void print(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void test01()
{
	int a[] = { 5,3,9,6,2 };
	int n = sizeof(a) / sizeof(a[0]);
	print(a, n);
	InserSort(a, n);
	print(a, n);
}

int main()
{
	test01();
	return 0;
}