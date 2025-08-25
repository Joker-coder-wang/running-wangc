#define  _CRT_SECURE_NO_WARNINGS 1

#include"string.h"

namespace wh
{
	//string::string()
	//	:_str(new char[1]{'\0'})
	//	,_size(0)//0����Ч�ַ�
	//	,_capacity(0)
	//{ }
	string::string(const char* str = "")//���޲ι���ʡ�ԣ�д��ȫȱʡ���򻯴���
		:_size(strlen(str))
	{
		_capacity = _size; 
		//����ע�⣬sizeof()�ڱ���ʱ���㣬strlen()������ʱ���㣬 
		_str = new char[_size + 1];
		//str��const���Σ����������ѣ������ݲ��ɱ��޸ģ��ʲ���ʹ��swap()
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

	//string::string(string& str)//�ִ�д��
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
		//if(this!=&s)//��ֹ�Լ����Լ���ֵ
		//{
		//	char* tmp = new char[s._capacity + 1];
		//	memcpy(tmp, s._str, s._size + 1);
		//	delete[] _str;//�ͷ�s1�ľɿռ�
		//	_str = tmp;
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		//return *this;
	//	if(this!=&s)//��ֹ�Լ����Լ���ֵ
	//	{
	//		string tmp(s);
	//		swap(tmp);//����������tmp���Զ�����
	//	}
	//	return *this;
	//}
	string& string::operator=(string tmp)//��������Ż���ֵ����-�����ÿ�������
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
	void string::reserve(size_t n)//���ÿռ��С�����ݣ�
	{
		if (n > _capacity)//����reserve�����������ݣ���ʱ����nֵ���ܻ���С��_capacity,�ʽ����ж�
		{
			//���ٲ�ָ���¿ռ䣬���������ݣ��ͷžɿռ�
			char* str = new char[n + 1];//n+1,����'\0'
			//new֮�󣬳������������쳣������Ҫ���ж���
			//strcpy(str, _str);�������strcpy���ܻᵼ��'\0'��Ϊ��Ч�ַ�ʱ��ǰ��ֹ
			memcpy(str, _str, _size+1);
			delete[] _str;
			_str = str;
			_capacity = n;

		}
	}

	void string::push_back(char ch)
	{
		//���ȿ�����������
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);//����ʹ�ÿմ����г�ʼ�����ᵼ������ʧ�ܣ����������ַ���
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		//���ȿ����������⣬����2����һ������
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > (_size + len) ? 2 * _capacity :(_size+len) ;
			//������Ҫô�ǵ�ǰ������������Ҫô�Ǹպ�����������Ԫ�ؼ�����Ԫ�صĴ�С��ȡ������ֵ�нϴ���Ǹ�
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
	//	assert(pos <= _size);//Խ��

	//	if (_size >= _capacity)
	//	{
	//		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
	//		reserve(newcapacity);
	//	}
		//Ų�����ݣ���ʱend >= pos���ӣ�
		//size_t end = _size;
		//while (end >= pos)//��posΪ0��endΪ-1ʱ��ֹͣŲ������endΪsize_t�޷������ͣ�-1=��Լ��42��9ǧ����>0,������
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		//_str[pos] = ch;
		//_size++;
		
		//�Ż����˴���������ǿת��
		//int end = _size;
		//while (end >= (int)pos)//��posΪ0��endΪ-1ʱ��ֹͣŲ������endΪsize_t�޷������ͣ�-1=��Լ��42��9ǧ����>0,������
		//{
		//	_str[end + 1] = _str[end];
		//	--end;
		//}
		//_str[pos] = ch;
		//_size++;

		//�Ż����˴�����Ҫ����ת����
	//	size_t end = _size + 1;
	//	while (end > pos)
	//	{
	//		_str[end] = _str[end - 1];
	//		--end;
	//	}
	//	_str[pos] = ch;
	//	_size++;

	//}

	//��������
	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size > _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
			//˼����_capacity = newcapacity;�������ɴ������࣬reserve�����Ѿ����иò�����
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
	void string::insert(size_t pos, const char* str)//�пӵ���
	{
		assert(pos >= _size);
		size_t len = _size + strlen(str);
		if (_size+len > _capacity)
		{
			size_t newcapacity = _capacity * 2 > (_size + len) ? _capacity * 2 : (_size + len);
			reserve(newcapacity);
		}
		size_t end = _size + len;
		while (end > pos+len-1)//�������������һ��ʱ��Ϊend=pos+len;
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
		if ((len == npos) || (len>=(_size-pos)))//Ҫɾ�����ݴ��ں�����ַ�������ҿ�
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else//ɾ�������ַ�
		{
			size_t i = pos + len;
			memmove(_str + pos, _str + i, _size + 1 - i);
			_size -= len;//ɾ��len���ַ�
		}
	}
	void string::pop_back()
	{
		assert(_size>0);
		_str[_size - 1] = '\0';
		--_size;
	}

	//find�ַ�
	size_t string::find(char ch, size_t pos = 0)
	{
		//��posλ�ÿ�ʼ��
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
			return p1 - _str;//ָ���ָ�� = �ַ�����
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
			ret += _str[pos + i];//׷���ַ�
		}
		return ret;//��ֵ���ط�����ʱ���󣬵���Ĭ�Ͽ������죬ǳ����������������ͻ��������
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

	void string::clear()//��ʱ����Ҫ�ͷſռ�
	{
		_str[0] = '\0';
		_size = 0;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		//����д����Ӱ���ȡ���������'\0'�ͽ�ֹ�����������'\0'Ҳ����Ϊ��Ч�ַ��������ַ�����
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
	//	////�ո����Ĭ���Ƕ��ֵ��ķָ�����Ҫ�õ�get()
	//	//char ch = in.get();
	//	//while (ch != ' ' && ch != '\n')
	//	//{
	//	//	s += ch;
	//	//	ch = in.get();//�����ַ�����ȡ
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
		char buff[128];//�ռ任ʱ��
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
		char buff[128];//�ռ任ʱ��
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