#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Person
//{
//public:
//	void eat() {
//		cout << "ieatfood";
//	}
//protected:
//	string _name = "zhangsan";
//	int _age = 13;
//};
//
//class Student :public Person
//{
//public:
//	void eat(int a) {
//		
//	}
//	void studying() {
//
//	}
//protected:
//	string _stuid = "11111";
//};
//
//int main() 
//{
//	Student s;
//	Person p;
//
//	//s.eat();//编译错误，，这里涉及隐藏知识点
//	s.eat(3);
//	p.eat();
//}

class Person
{
public:
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person(const char* name)"<<endl;
	}
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)"<<endl;
	}
	static int _count;
	string _name;
};

int Person::_count = 1;

class Student :public Person
{
public:
	Student(const char* name,int num)
		:Person(name)
		,_num(num)
	{
		cout << "student(const char* name,const int num)"<<endl;
	}
	Student(const Student& s)
		:Person(s)
		,_num(s._num)
	{
		cout << "Student(const Student& s)"<<endl;
	}
protected:
	int _num=99;
};

int main()
{
	Person p;
	Student s("ww",22);
	cout << &p._name << endl;
	cout << &s._name << endl;

	cout << &p._count << endl;
	cout << &s._count << endl;//派生类可继承基类的静态成员

	cout << Person::_count << endl;
	cout << Student::_count << endl;
	return 0;
}