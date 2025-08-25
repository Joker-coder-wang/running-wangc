#define  _CRT_SECURE_NO_WARNINGS 1

#include"string.h"

namespace wh
{
	//string::string()
	//	:_str(new char[1]{'\0'})
	//	,_size(0)//0个有效字符
	//	,_capacity(0)
	//{ }
	string::string(const char* str = "")//将无参构造省略，写成全缺省，简化代码
		:_size(strlen(str))
	{
		_capacity = _size; 
		//这里注意，sizeof()在编译时运算，strlen()在运行时计算， 
		_str = new char[_size + 1];
		//str被const修饰，常量区（堆）的内容不可被修改，故不可使用swap()
		memcpy(_str, str, _size+1);
	}
	string::string(const string& str)
	{
		_str = new char[str._capacity + 1];
		memcpy(_str, str._str, str._size + 1);
		_size = str._size;
		_capacity = str._capacity;
	}
	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	//string::string(string& str)//现代写法
	//{
	//	string tmp(str._str);
	//	swap(tmp);
	//}
	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	//s1 = s2;
	//string& string::operator=(const string& s)
	//{
		//if(this!=&s)//防止自己给自己赋值
		//{
		//	char* tmp = new char[s._capacity + 1];
		//	memcpy(tmp, s._str, s._size + 1);
		//	delete[] _str;//释放s1的旧空间
		//	_str = tmp;
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		//return *this;
	//	if(this!=&s)//防止自己给自己赋值
	//	{
	//		string tmp(s);
	//		swap(tmp);//出了作用域，tmp会自动销毁
	//	}
	//	return *this;
	//}
	string& string::operator=(string tmp)//代码更加优化传值传参-》调用拷贝构造
	{
		swap(tmp);
		return *this;
	}
	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::iterator string::begin() const
	{
		return _str;
	}
	string::iterator string::end() const
	{
		return _str + _size;
	}

	const char* string::c_str() const
	{
		return _str;
	}

	size_t string::size() const 
	{
		return _size;
	}
	char& string::operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}
	const char& string::operator[](size_t i) const
	{
		assert(i < _size);
		return _str[i];

	}
	void string::reserve(size_t n)//重置空间大小（扩容）
	{
		if (n > _capacity)//由于reserve不仅用来扩容，有时给的n值可能还会小于_capacity,故进行判断
		{
			//开辟并指向新空间，拷贝旧数据，释放旧空间
			char* str = new char[n + 1];//n+1,包含'\0'
			//new之后，出问题会进行抛异常，不需要进行断言
			//strcpy(str, _str);这里进行strcpy可能会导致'\0'作为有效字符时提前截止
			memcpy(str, _str, _size+1);
			delete[] _str;
			_str = str;
			_capacity = n;

		}
	}

	void string::push_back(char ch)
	{
		//首先考虑扩容问题
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);//假设使用空串进行初始化，会导致扩容失败，故舍弃这种方法
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		//首先考虑扩容问题，扩容2倍不一定够用
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > (_size + len) ? 2 * _capacity :(_size+len) ;
			//新容量要么是当前容量的两倍，要么是刚好能容纳现有元素加新增元素的大小，取这两个值中较大的那个
			reserve(newcapacity);
		}
		memcpy(_str+_size, str, len + 1);
		_size += len;

	}
	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	//void string::insert(size_t pos, char ch)
	//{
	//	assert(pos <= _size);//越界

	//	if (_size >= _capacity)
	//	{
	//		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
	//		reserve(newcapacity);
	//	}
		//挪动数据，此时end >= pos（坑）
		//size_t end = _size;
		//while (end >= pos)//当pos为0，end为-1时，停止挪动，但end为size_t无符号整型，-1=（约）42亿9千万仍>0,故无限
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		//_str[pos] = ch;
		//_size++;
		
		//优化（此处进行类型强转）
		//int end = _size;
		//while (end >= (int)pos)//当pos为0，end为-1时，停止挪动，但end为size_t无符号整型，-1=（约）42亿9千万仍>0,故无限
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		//_str[pos] = ch;
		//_size++;

		//优化（此处不需要类型转换）
	//	size_t end = _size + 1;
	//	while (end > pos)
	//	{
	//		_str[end] = _str[end - 1];
	//		--end;
	//	}
	//	_str[pos] = ch;
	//	_size++;

	//}

	//完整操作
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size > _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
			//思考：_capacity = newcapacity;这里会造成代码冗余，reserve操作已经进行该步骤了
		}
		size_t end = _size + 1;
		while (pos < end)
		{
			_str[end] = _str[end-1];
			--end;
		}
		_str[pos] = ch;
		++_size;

	}
	//void string::insert(size_t pos, const char* str)
	//{
	//	assert(pos <= _size);
	//	size_t len = strlen(str);
	//	if (_size + len > _capacity)
	//	{
	//		size_t newcapacity = 2 * _capacity > (_size + len) ? 2 * _capacity : (_size + len);
	//		reserve(newcapacity);
	//	}
	//	int end = _size;
	//	while ((int)pos < end)
	//	{
	//		_str[end + len] = _str[end];
	//		--end;
	//	}
	//	for (size_t i = 0;i < len;i++)\
	//	{
	//		_str[pos + i] = str[i];
	//	}
	//	_size += len;
	//}
	void string::insert(size_t pos, const char* str)//有坑的码
	{
		assert(pos >= _size);
		size_t len = _size + strlen(str);
		if (_size+len > _capacity)
		{
			size_t newcapacity = _capacity * 2 > (_size + len) ? _capacity * 2 : (_size + len);
			reserve(newcapacity);
		}
		size_t end = _size + len;
		while (end > pos+len-1)//条件成立的最后一个时刻为end=pos+len;
		{
			_str[end] = str[end-len];
			--end;
		}
		for (size_t i = 0;i < len;i++)\
		{
			_str[pos + i] = str[i];
		}
		_size += len;
	}

	const size_t string::npos = -1;

	void string::erase(size_t pos,size_t len = npos)
	{
		assert(pos <= _size);
		if ((len == npos) || (len>=(_size-pos)))//要删除数据大于后面的字符，左闭右开
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else//删除部分字符
		{
			size_t i = pos + len;
			memmove(_str + pos, _str + i, _size + 1 - i);
			_size -= len;//删除len个字符
		}
	}
	void string::pop_back()
	{
		assert(_size>0);
		_str[_size - 1] = '\0';
		--_size;
	}

	//find字符
	size_t string::find(char ch, size_t pos = 0)
	{
		//从pos位置开始找
		for (size_t i = pos;i < _size;i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos = 0)
	{
		//kmp
		const char* p1 = strstr(_str + pos, str);
		if(p1 == nullptr)
		{
			return npos;
		}
		else {
			return p1 - _str;//指针减指针 = 字符个数
		}
	}
	string string::substr(size_t pos, size_t len) const
	{
		if (len == npos || len >= _size - pos)
		{
			len = _size - pos;
		}
		string ret;
		ret.reserve(len);
		for (size_t i = pos; i < len; i++)
		{
			ret += _str[pos + i];//追加字符
		}
		return ret;//传值返回返回临时对象，调用默认拷贝构造，浅拷贝，出了作用域就会调用析构
	}
	bool string::operator<(const string& str) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < str._size)
		{
			if (_str[i1] < str[i2])
			{
				return true;
			}
			else if (_str[i1] > str[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		return i2 < str._size;
	}
	bool string::operator<=(const string& str) const
	{
		return (*this < str) || (*this == str);
	}
	bool string::operator>(const string& str) const
	{
		return !(*this <= str);
	}
	bool string::operator>=(const string& str) const
	{
		return !(*this < str);
	}
	//bool string::operator==(const string& str) const
	//{
	//	size_t i1 = 0, i2 = 0;
	//	while (i1 < _size && i2 < str._size)
	//	{
	//		if (_str[i1] != str[i2])
	//		{
	//			return false;
	//		}
	//		else
	//		{
	//			++i1;
	//			++i2;
	//		}
	//	}
	//	return i1 ==_size && i2 ==str._size;
	//}
	bool string::operator==(const string& str) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < str._size)
		{
			if (_str[i1] != str._str[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}				
		return (i1 == _size) && (i2 == str._size);
	}
	bool string::operator!=(const string& str) const
	{
		return !(*this == str);
	}

	void string::clear()//此时不需要释放空间
	{
		_str[0] = '\0';
		_size = 0;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		//这种写法会影响读取结果，遇到'\0'就截止，特殊情况下'\0'也会作为有效字符存在于字符串中
		//out << s.c_str();
		//return out;
		for (auto ch : s)
		{
			out << ch << ' ';
		}
		return out;
	}
	//istream& operator>>(istream& in, string& s)
	//{
	//	//s.clear();
	//	////空格或换行默认是多个值间的分割，这里就要用到get()
	//	//char ch = in.get();
	//	//while (ch != ' ' && ch != '\n')
	//	//{
	//	//	s += ch;
	//	//	ch = in.get();//单个字符逐渐提取
	//	//}
	//	//return in;
	//	s.clear();
	//	char buff[128];
	//	int i = 0;
	//	char ch = in.get();
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		buff[i++] = ch;
	//		if (i == 127)
	//		{
	//			buff[i] = '\0';
	//			s += buff;
	//			i = 0;
	//		}
	//		ch = in.get();
	//	}
	//	if (i > 0)
	//	{
	//		buff[i] = '\0';
	//		s += buff;
	//	}
	//	return in;
	//}
	istream& operator<<(istream& in, string& str)
	{
		str.clear();
		char ch = in.get();
		char buff[128];//空间换时间
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}
		return in;
	}
	istream& getline(istream& in, string& str,char delim)
	{
		str.clear();
		char ch = in.get();
		char buff[128];//空间换时间
		int i = 0;
		while (ch != delim)
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}
		return in;
	}
} 