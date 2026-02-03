#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int main()
{
	//Ã°ÅÝÅÅÐò(½µÐò)
	int n;
	cin >> n;
	int a[100] = { 0 };

	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	for (int i = 0;i < n-1;i++)
	{
		for (int j = 1;j < n - i;j++)
		{
			if (a[j - 1] < a[j])
				swap(a[j - 1], a[j]);
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << a[i] << ' ';
	}
	
	return 0;
}
