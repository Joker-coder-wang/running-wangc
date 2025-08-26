#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>

using namespace std;

namespace wh{

	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin();
		iterator end();

		iterator begin() const;//适用于被const修饰的对象
		iterator end() const;
		void swap(string& s);
		//string();
		string(const char* str);	
		string(const string& str);
		string(string& str);
		const char* c_str() const;//第一原则是打印字符串，直到找到'\0'
		~string();

		string& operator=(string tmp);

		size_t size() const;
		char& operator[](size_t i);
		const char& operator[](size_t i) const;

		void reserve(size_t n);//重置空间大小
		void push_back(char ch);
		void append(const char* str);
		//string.h中的strcat为追加字符串的函数，但不适用于这里，因为他会先循环遍历找到尾部

		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);

		void  erase(size_t pos,size_t len);
	
		void pop_back();

		size_t find(char ch, size_t pos);
		size_t find(const char* str, size_t pos);

		string substr(size_t pos, size_t len) const;
	    
		bool operator<(const string& str) const;
		bool operator<=(const string& str) const;
		bool operator>(const string& str) const;
		bool operator>=(const string& str) const;
		bool operator==(const string& str) const;
		bool operator!=(const string& str) const;
	
		void clear();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const size_t npos;
	};

	ostream& operator<<(ostream& out, const string& s);//成为友元吗？访问类的私有吗？
	istream& operator>>(istream& in, string& s);
	void swap(string& x, string& y);
}