#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace wh
{
	void string_test1()
	{
		string s1 = "hhh";
		std::cout << s1.c_str() << std::endl;//此处空指针解引用
	
		for (size_t i = 0;i < s1.size();i++)
		{
			s1[i]++;
		}
		std::cout << s1.c_str() << std::endl;
		
		for (auto ch : s1)
		{
			std::cout << ch << " ";
		}
		std::cout << std::endl;

		string::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			std::cout << *it1 << " ";
			++it1;
		}


		
	}
	void string_test2()
	{
		const string s2 = "hello world";

		string::const_iterator it1 = s2.begin();
		while (it1 != s2.end())
		{
			//*it1 = 'x';//error.不可修改！
			std::cout << *it1 << " ";
			++it1;
		}
	}

	void string_test3()
	{
		string s3 = "hello world";
		//s3.push_back('9');
		std::cout << s3.c_str() << std::endl;

		s3.append("hello wh");
		std::cout << s3.c_str() << std::endl;
	}
	void string_test4()
	{
		string s4 = "hello world";
		s4 += '\0';
		s4 += '\0';
		s4 += '\0';
		s4 += '!';
		//两种情况有差异
		cout << s4 << endl; //返回 h e l l o w o r l d   !
		cout << s4.c_str() << endl;//返回hello world(c语言的返回方式，一般遇到'\0'就截止)

		s4 += "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";
		cout << s4 << endl;
		cout << s4.c_str() << endl;
	}
	void string_test5()
	{
		string s5 = "hello world";
		s5.insert(3, "hhhhh");
		cout << s5.c_str() << endl;
	}
	void string_test6()
	{
		string s6 = "hello";
		string s7 = "helloo";
		//cout << (s6 > s7) << endl;
		s6 = s7;
		cout << s6 << endl;
		cout << s7 << endl;
	}
	void string_test7()
	{
		string s = "hello";
		string ss = "hhhhh";
		swap(s, ss);//调用全局标准库中的swap,或已有重载函数
		s.swap(ss);//调用成员函数swap
	}
}

int main()
{
	wh::string_test7();

	//int i = 0;
	//cin >> i;
	//std::string s = std::to_string(i);//c++11
	//string str = "hhhhhhh";
	//int j = stoi(str);
	return 0;
}