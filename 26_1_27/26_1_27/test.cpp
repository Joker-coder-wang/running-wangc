#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Person
{
public:
	virtual void BuyTicket()//虚函数覆盖
	{
		cout << "全价票" << endl;
	}
};

class Student:public Person
{
public:
	virtual void BuyTicket()//虚函数覆盖
	{
		cout << "半价票" << endl;
	}
};

void func(Person& ptr) //实现多态效果第一必须是基类的指针或引用，因为只有基类的指针或引用才能既指向基类对象又指向派生类对象
{
	ptr.BuyTicket();//由ptr指向的对象来调控谁来使用BuyTicket()函数
}

int main()
{
	Person p;
	Student s;

	//p.BuyTicket();
	//s.BuyTicket();

	func(p);
	func(s);

	return 0;
}