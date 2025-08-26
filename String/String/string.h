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

		iterator begin() const;//�����ڱ�const���εĶ���
		iterator end() const;
		void swap(string& s);
		//string();
		string(const char* str);	
		string(const string& str);
		string(string& str);
		const char* c_str() const;//��һԭ���Ǵ�ӡ�ַ�����ֱ���ҵ�'\0'
		~string();

		string& operator=(string tmp);

		size_t size() const;
		char& operator[](size_t i);
		const char& operator[](size_t i) const;

		void reserve(size_t n);//���ÿռ��С
		void push_back(char ch);
		void append(const char* str);
		//string.h�е�strcatΪ׷���ַ����ĺ��������������������Ϊ������ѭ�������ҵ�β��

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

	ostream& operator<<(ostream& out, const string& s);//��Ϊ��Ԫ�𣿷������˽����
	istream& operator>>(istream& in, string& s);
	void swap(string& x, string& y);
}