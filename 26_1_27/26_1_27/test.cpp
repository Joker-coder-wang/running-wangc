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
	void func1(){}
};

class Student:public Person
{
public:
	virtual void BuyTicket()//虚函数覆盖
	{
		cout << "半价票" << endl;
	}
};
//
//void func(Person& ptr) //实现多态效果第一必须是基类的指针或引用，因为只有基类的指针或引用才能既指向基类对象又指向派生类对象
//{
//	ptr.BuyTicket();//由ptr指向的对象来调控谁来使用BuyTicket()函数
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	//p.BuyTicket();
//	//s.BuyTicket();
//
//	func(p);
//	func(s);
//
//	return 0;
//}


int main() 
{
	int i = 0;
	static int j = 1;
	int* p1 = new int;
	const char* p2 = "xxxxxxxx";
	printf("栈:%p\n", &i);
	printf("静态区:%p\n", &j);
	printf("堆:%p\n", p1);
	printf("常量区:%p\n", p2);


	//检验虚函数所在位置为常量区
	//虚函数表，简称虚表，本质是一个函数指针数组
	Person ps;
	Person* ptr = &ps;//Person对象的前4字节为虚表地址，那么我们可以取Person的地址，并强转为int*类型
	printf("虚表：%p\n", *((int*)ptr));
	Student st;
	printf("虚表：%p\n", *((int*)&st));


	//此处体现虚函数地址与普通函数离得不远
	printf("虚函数地址:%p\n", &Person::BuyTicket);
	printf("普通函数地址:%p\n", &Student::func1);

	return 0;
}