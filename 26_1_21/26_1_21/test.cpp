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

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person(const char* name)"<<endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)"<<endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "	Person& operator=(const Person& p)"<<endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//	static int _count;
//	string _name;
//};
//
//int Person::_count = 1;
//
//class Student :public Person
//{
//public:
//	Student(const char* name,int num)
//		:Person(name)
//		,_num(num)
//	{
//		cout << "student(const char* name,const int num)"<<endl;
//	}
//	Student(const Student& s)
//		:Person(s)
//		,_num(s._num)
//	{
//		cout << "Student(const Student& s)"<<endl;
//	}
//	Student& operator=(const Student& s) 
//	{
//		cout << "Student& operator=(const Student& s) "<<endl;
//		if (this != &s) {
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()//先调用派生类析构函数再自动调用基类析构
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num=99;
//};
//
//int main()
//{
//	Person p;
//	Student s("ww",22);
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	cout << &p._count << endl;
//	cout << &s._count << endl;//派生类可继承基类的静态成员
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//
//	Student s1("www", 44);
//	s1 = s;
//	cout << s1._name<<endl;
//	return 0;
//}


//#include <string>
//
////实现一个不可继承的类，方法1：
//class Base final
//{
//public:
//	void func() { cout << "func()" << endl; }
//protected:
//	int _a = 2;
////C++98的方法2:
//// 	   这里主要体现了private与protected的区别
////private:
////	Base()
////	{
////
////	}
//};
//
////友元关系不能继承，也就是说基类友元不能访问派生类私有和保护成员
//class Student;
////编译器向上查找，所以一定要有类声明
//class Person
//{
//public:
//	friend void Display(const Person& p,const Student& s);
//	Person(const char* name = "Peter")
//		:_name(name)
//	{
//		cout << "Person(const char* name)"<<endl;
//	}
//protected:
//	string _name = "Jett";
//};
//
//class Student :public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//	Student(const Person& p,int num = 222) 
//		:Person(p)
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(){}
//protected:
//	int _num = 333;
//
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._num << endl;
//}
////此处编译报错：将Dispaly也写为Student友元即可
//int main()
//{
//	Person p;
//	Student s;
//
//	Display(p, s);
//	return 0;
//}



//继承和组合的关系：
// Tire(轮胎)和Car(⻋)更符合has-a的关系
class Tire {
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺⼨
};
class Car {
protected:
	string _colour = "白色"; // 颜⾊
	string _num = "陕ABIT00"; // ⻋牌号
	Tire _t1; // 轮胎
	Tire _t2; // 轮胎
	Tire _t3; // 轮胎
	Tire _t4; // 轮胎
};
class BMW : public Car {
public:
	void Drive() { cout << "好开-操控" << endl; }
};
// Car和BMW/Benz更符合is-a的关系
class Benz : public Car {
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};


template<class T>
class vector
{
};
// stack和vector的关系，既符合is-a，也符合has-a
//template<class T>
//class stack:public vector<T>
//{
//};
template<class T>
class stack
{
public:
	vector<T> _v;
};
int main()
{
	return 0;
}