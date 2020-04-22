#pragma once

#include <iostream>
#include <vld.h>
#include <assert.h>
using namespace std;


class my_string
{
public:
	friend ostream& operator<<(ostream& out, const my_string& s);
	friend istream& operator>>(istream& in, my_string& s);
	friend istream& getline(istream& in, my_string& s);
	//构造函数
	my_string(const char* str = "")
		:_size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_capacity + 1];//预留'\0'的位置
		strcpy(_str, str);
	}
	//析构函数
	~my_string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	//拷贝构造
	my_string(const my_string& s)
	{
		/*
		//浅拷贝
		_str = s._str;
		_size = s._size;
		_capacity = s._size;
		*/

		//深拷贝
		_str = new char[s._size + 1];//多开一个
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._size;
	}
	//赋值运算符重载
	my_string& operator=(const my_string& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	//[]运算符重载
	char& operator[](size_t pos)
	{
		assert(pos < _size);//不能越界
		return _str[pos];
	}

	//修改器
	//+=运算符重载
	my_string& operator+=(const my_string& s)
	{
		//如果空间不够，就扩容
		reserve(_size + s._size);
		strncpy(_str + _size, s._str, s._size + 1);//得要把末尾的'\0'也一起拷贝过来
		_size += s._size;
		return *this;
	}
	my_string& operator+=(const char* str)
	{
		size_t len = strlen(str);
		reserve(_size + len);
		strncpy(_str + _size, str, len + 1);//得要把末尾的'\0'也一起拷贝过来
		_size += len;
		return *this;
	}
	my_string& operator+=(const char s)
	{
		
		//如果空间不够，就扩容
		reserve(_size + 1);
		_str[_size++] = s;
		_str[_size] = '\0';
		return *this;
	}
	//比较运算符重载
	bool operator<(const my_string& s)
	{
		return strcmp(_str, s._str) < 0;
	}

	bool operator==(const my_string& s)
	{
		return strcmp(_str, s._str) == 0;
	}

	bool operator<=(const my_string& s)
	{
		return *this < s || *this == s;
	}

	bool operator>(const my_string& s)
	{
		return !(*this <= s);
	}

	bool operator>=(const my_string& s)
	{
		return !(*this < s);
	}

	bool operator!=(const my_string& s)
	{
		return !(*this == s);
	}
	//push_back
	void push_back(char c)
	{
		reserve(_size + 1);//判断是否满了
		_str[_size++] = c;
		_str[_size] = '\0';//记得结尾加'\0'
	}
	//append追加
	my_string& append(const my_string& s)//追加一个类
	{
		*this += s;
		return *this;
	}
	my_string& append(const char* c)//追加一个字符串
	{
		my_string s(c);
		*this += s;
		return *this;
	}
	my_string& append(const char c)//追加一个字符
	{
		this->append(c);
		return *this;
	}
	//insert
	void insert(size_t pos, char c)//插入一个字符
	{
		assert(pos < _size);
		reserve(_size + 1);
		memmove(_str + pos + 1, _str + pos, _size - pos);
		_str[pos] = c;
		_size++;
		_str[_size] = '\0';
	}
	void insert(size_t pos, const char* str)//插入字符串
	{
		assert(pos < _size);
		int len = strlen(str);
		reserve(pos + _size);
		memmove(_str + pos + len, _str + pos, _size - pos);
		strncpy(_str + pos, str, len);//不能用strcpy，防止吧'\0'拷贝到中间位置
		_size += len;
		_str[_size] = '\0';
	}
	//erase消除
	void erase(size_t pos, size_t len = npos)
	{
		assert(pos < _size);

		if (_size - pos < len)//消除pos后面所有字符
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else//消除部分字符
		{
			memmove(_str + pos, _str + pos + len, _size - (pos + len));
			_size -= len;
			_str[_size] = '\0';
		}
	}

	//capacity类
	//返回字符串的大小
	size_t size()
	{
		return _size;
	}
	//返回字符串的容量
	size_t capacity()
	{
		return _capacity;
	}
	//扩容到指定大小
	void reserve(size_t n)
	{
		//如果n小于容量，则不做任何改变
		if (n > _capacity)
		{
			char* newstr = new char[n + 1];//预留'\0'的空间
			strcpy(newstr, _str);
			delete[] _str;
			_str = newstr;
			_capacity = n;
		}
	}
	void resize(size_t n, char c = '\0')
	{
		//n小于当前字段长度，进行删除
		if (n < _size)
		{
			_size = n;
			_str[_size] = '\0';
		}
		else //大于当前字段长度，进行插入
		{
			if (n > _capacity)//空间是否足够
				reserve(n);
			//插入
			for (size_t i = _size; i < n; i++)
				_str[i] = c;
			_size = n;
			_str[_size] = '\0';
		}
	}
	//清理函数
	void clear()
	{
		_size = 0;
	}
	//判空
	bool empty()const
	{
		return _size ? true : false;
		/*if (_size)
			return true;
			return false;*/
	}

	//Iterators:迭代器
	typedef char* iterators;
	iterators begin()
	{
		return _str;
	}
	//返回的末尾位置是'\0'的位置
	iterators end()
	{
		return _str + _size;
	}

	void p()
	{
		cout << npos << endl;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		const char* p = strstr(_str + pos, str);
		return (p == nullptr) ? npos : (p - _str);
	}

	size_t find(const my_string& s, size_t pos = 0)
	{
		return find(s._str, pos);
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return npos;
	}

	my_string substr(size_t pos = 0, size_t len = npos)const
	{
		my_string ret("");
		for (size_t i = pos; i < len; i++)
		{
			ret += _str[i];
		}
		cout << ret << endl;
		return ret;
	}
private:
	char* _str;			//存放字符串
	size_t _size;		//当前有效字符串的数量
	size_t _capacity;	//能最大存储的有效字符串数量，不包括'\0'

	static size_t npos;
};
size_t my_string::npos = -1;

istream& getline(istream& in, my_string& s)
{
	while (1)
	{
		char ch = in.get();
		if (ch == '\n')
			break;
		s += ch;
	}
	return in;
}

istream& operator>>(istream& in, my_string& s)
{
	//不能简单的使用cin，因为此时_str的空间不是new开辟出来的，在析构的时候会有问题
	while (1)
	{
		char ch = in.get();
		if (ch == ' ' || ch == '\n')
			break;
		s += ch;
	}
	return in;
}

ostream& operator<<(ostream& out, const my_string& s)
{
	out << s._str << endl;
	return out;
}
/*
class my_string
{
public:
	friend ostream& operator<<(ostream& out, const my_string& s);

	//参数为字符串类型的构造
	my_string(const char* str = "")
		:_str(new char[strlen(str) + 1])//为 \0 留一个空间
	{
		strcpy(_str, str);
	}
	//参数为string类 类型的构造
	my_string(const my_string& s)
		:_str(new char[strlen(s._str) + 1])//为 \0 留一个空间
	{
		strcpy(_str, s._str);
	}

	//求string字符串的大小
	size_t size()const
	{
		return strlen(_str);
	}

	//operator = 赋值操作
	my_string& operator=(const my_string& s)
	{
		//不能自己给自己赋值
		if (this != &s)
		{
			delete[] _str; //_str串 长度大于 s串  ，直接拷贝会出现内存泄漏
			_str = new char[s.size() + 1];

			strcpy(_str, s._str);
			return *this;
		}
	}

	//operator [] 重载
	char& operator[](const size_t count)
	{
		if (count >= this->size())
		{
			perror("越界访问");
			_exit(0);
		}
			
		return _str[count];
	}

	//析构函数，释放空间
	~my_string()
	{
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};

//operator << 输出重载
ostream& operator<<(ostream& out, const my_string& s)
{
	cout << s._str << endl;
	return out;
}*/