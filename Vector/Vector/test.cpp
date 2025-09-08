#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 (5, 22);
	vector<int> v(v1.begin()+3,v1.end());
	vector<int>::iterator It = v1.begin();
	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;
	while (It != v1.end())
	{
		cout << *It << ' ';
		It++;
	}
	cout << endl;
	size_t old = v.capacity();
	for(size_t i=0;i<100;i++)
	{
		v.push_back(i);

		if (old != v.capacity())
		{
			cout << v.capacity()<<endl; 
				old = v.capacity();
		}
	}
	v.insert(v.begin(), 44);
	for (auto e : v)
	{
		cout << e << endl;
	}
	int x;
	cin >> x;
	It = find(v.begin(),v.end(),x);
	if(It != v.end())
	{
		v.erase(It);//É¾³ýÒ»¸öorÒ»¶Î
	}
	for (auto e : v)
	{
		cout << e << ' ';
	}
	return 0;
}