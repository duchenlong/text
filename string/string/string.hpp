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
	//���캯��
	my_string(const char* str = "")
		:_size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_capacity + 1];//Ԥ��'\0'��λ��
		strcpy(_str, str);
	}
	//��������
	~my_string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	//��������
	my_string(const my_string& s)
	{
		/*
		//ǳ����
		_str = s._str;
		_size = s._size;
		_capacity = s._size;
		*/

		//���
		_str = new char[s._size + 1];//�࿪һ��
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._size;
	}
	//��ֵ���������
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
	//[]���������
	char& operator[](size_t pos)
	{
		assert(pos < _size);//����Խ��
		return _str[pos];
	}

	//�޸���
	//+=���������
	my_string& operator+=(const my_string& s)
	{
		//����ռ䲻����������
		reserve(_size + s._size);
		strncpy(_str + _size, s._str, s._size + 1);//��Ҫ��ĩβ��'\0'Ҳһ�𿽱�����
		_size += s._size;
		return *this;
	}
	my_string& operator+=(const char* str)
	{
		size_t len = strlen(str);
		reserve(_size + len);
		strncpy(_str + _size, str, len + 1);//��Ҫ��ĩβ��'\0'Ҳһ�𿽱�����
		_size += len;
		return *this;
	}
	my_string& operator+=(const char s)
	{
		
		//����ռ䲻����������
		reserve(_size + 1);
		_str[_size++] = s;
		_str[_size] = '\0';
		return *this;
	}
	//�Ƚ����������
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
		reserve(_size + 1);//�ж��Ƿ�����
		_str[_size++] = c;
		_str[_size] = '\0';//�ǵý�β��'\0'
	}
	//append׷��
	my_string& append(const my_string& s)//׷��һ����
	{
		*this += s;
		return *this;
	}
	my_string& append(const char* c)//׷��һ���ַ���
	{
		my_string s(c);
		*this += s;
		return *this;
	}
	my_string& append(const char c)//׷��һ���ַ�
	{
		this->append(c);
		return *this;
	}
	//insert
	void insert(size_t pos, char c)//����һ���ַ�
	{
		assert(pos < _size);
		reserve(_size + 1);
		memmove(_str + pos + 1, _str + pos, _size - pos);
		_str[pos] = c;
		_size++;
		_str[_size] = '\0';
	}
	void insert(size_t pos, const char* str)//�����ַ���
	{
		assert(pos < _size);
		int len = strlen(str);
		reserve(pos + _size);
		memmove(_str + pos + len, _str + pos, _size - pos);
		strncpy(_str + pos, str, len);//������strcpy����ֹ��'\0'�������м�λ��
		_size += len;
		_str[_size] = '\0';
	}
	//erase����
	void erase(size_t pos, size_t len = npos)
	{
		assert(pos < _size);

		if (_size - pos < len)//����pos���������ַ�
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else//���������ַ�
		{
			memmove(_str + pos, _str + pos + len, _size - (pos + len));
			_size -= len;
			_str[_size] = '\0';
		}
	}

	//capacity��
	//�����ַ����Ĵ�С
	size_t size()
	{
		return _size;
	}
	//�����ַ���������
	size_t capacity()
	{
		return _capacity;
	}
	//���ݵ�ָ����С
	void reserve(size_t n)
	{
		//���nС�������������κθı�
		if (n > _capacity)
		{
			char* newstr = new char[n + 1];//Ԥ��'\0'�Ŀռ�
			strcpy(newstr, _str);
			delete[] _str;
			_str = newstr;
			_capacity = n;
		}
	}
	void resize(size_t n, char c = '\0')
	{
		//nС�ڵ�ǰ�ֶγ��ȣ�����ɾ��
		if (n < _size)
		{
			_size = n;
			_str[_size] = '\0';
		}
		else //���ڵ�ǰ�ֶγ��ȣ����в���
		{
			if (n > _capacity)//�ռ��Ƿ��㹻
				reserve(n);
			//����
			for (size_t i = _size; i < n; i++)
				_str[i] = c;
			_size = n;
			_str[_size] = '\0';
		}
	}
	//������
	void clear()
	{
		_size = 0;
	}
	//�п�
	bool empty()const
	{
		return _size ? true : false;
		/*if (_size)
			return true;
			return false;*/
	}

	//Iterators:������
	typedef char* iterators;
	iterators begin()
	{
		return _str;
	}
	//���ص�ĩβλ����'\0'��λ��
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
	char* _str;			//����ַ���
	size_t _size;		//��ǰ��Ч�ַ���������
	size_t _capacity;	//�����洢����Ч�ַ���������������'\0'

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
	//���ܼ򵥵�ʹ��cin����Ϊ��ʱ_str�Ŀռ䲻��new���ٳ����ģ���������ʱ���������
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

	//����Ϊ�ַ������͵Ĺ���
	my_string(const char* str = "")
		:_str(new char[strlen(str) + 1])//Ϊ \0 ��һ���ռ�
	{
		strcpy(_str, str);
	}
	//����Ϊstring�� ���͵Ĺ���
	my_string(const my_string& s)
		:_str(new char[strlen(s._str) + 1])//Ϊ \0 ��һ���ռ�
	{
		strcpy(_str, s._str);
	}

	//��string�ַ����Ĵ�С
	size_t size()const
	{
		return strlen(_str);
	}

	//operator = ��ֵ����
	my_string& operator=(const my_string& s)
	{
		//�����Լ����Լ���ֵ
		if (this != &s)
		{
			delete[] _str; //_str�� ���ȴ��� s��  ��ֱ�ӿ���������ڴ�й©
			_str = new char[s.size() + 1];

			strcpy(_str, s._str);
			return *this;
		}
	}

	//operator [] ����
	char& operator[](const size_t count)
	{
		if (count >= this->size())
		{
			perror("Խ�����");
			_exit(0);
		}
			
		return _str[count];
	}

	//�����������ͷſռ�
	~my_string()
	{
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};

//operator << �������
ostream& operator<<(ostream& out, const my_string& s)
{
	cout << s._str << endl;
	return out;
}*/