#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];//�õ���ǰ�³���2.29���������

		//�������2��29��
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}

		return day;
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
		return *this;
	}
	// ��������
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	// ����+=����
	Date& operator+=(int day)
	{
		//��������Ǹ���
		if (day < 0)
		{
			*this -= -day;
			return *this;
		}

		_day += day;
		int maxDay = GetMonthDay(_year, _month);//��ȡ��ǰ�µ��������
		while (maxDay < _day)
		{
			_day -= maxDay;//������ǰ�µ�����
			_month++;//��+1
			//����³��ˣ���+1���±��1��
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			maxDay = GetMonthDay(_year, _month);
		}
		return *this;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		//���Ҫ���������Ǹ���
		if (day < 0)
		{
			*this += -day;
			return *this;
		}
		while (_day <= day)
		{
			_month--;//��ǰ�·�-1
			//���û�ü���������һ��
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			int maxDay = GetMonthDay(_year, _month);
			_day += maxDay;
		}

		_day -= day;
		return *this;
	}
	// ����+����
	Date operator+(int day)
	{
		Date tmp(*this);
		//tmp.operator+=(day);
		tmp += day;
		return tmp;
	}
	// ����-����
	Date operator-(int day)
	{
		Date tmp(*this);
		//tmp.operator-=(day);
		tmp -= day;
		return tmp;
	}
	
	// ǰ��++ , ++i
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	// ����++ ,Ϊ������ǰ��++����һ������ i++
	Date operator++(int)//Date operator++(int i) //Ҳ��������
	{
		Date tmp(*this);//����++֮ǰ��ֵ
		*this += 1;
		return tmp;
	}
	// ����-- i--
	Date operator--(int)
	{
		Date tmp(*this);//����++֮ǰ��ֵ
		*this -= 1;
		return tmp;
	}
	// ǰ��--  --i
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		////������ֱ�ӱ�
		//if (_year > d._year)
		//	return true;
		////����ȱ���
		//if (_year == d._year && _month > d._month)
		//	return true;
		////������ȱ���
		//if (_year == d._year && _month == d._month && _day > d._day)
		//	return true;

		if ((_year > d._year) || \
			(_year == d._year && _month > d._month) || \
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		return false;

	}
	// ==���������
	bool operator==(const Date& d)
	{
		return _day == d._day &&\
			_month == d._month &&\
			_year == d._year;
	}
	// >=���������
	inline bool operator >= (const Date& d)
	{
		//����С�� С��Ϊ��
		return !(*this < d);
	}

	// <���������
	bool operator < (const Date& d)
	{
		//������ڣ��ʹ��ڣ���Ϊ��
		if (*this == d || *this>d)
			return false;
		return true;
	}
	// <=���������
	bool operator <= (const Date& d)
	{
		//�������ڣ�����Ϊ��
		return  !(*this > d);
	}
	// !=���������
	bool operator != (const Date& d)
	{
		//������Ϊ��
		return !(*this == d);
	}
	bool LeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;

		return false;
	}
	// ����-���� ��������
	int operator-(const Date& d)
	{
		Date small;
		Date big;
		if (*this > d)
		{
			big = *this;
			small = d;
		}
		else
		{
			big = d;
			small = *this;
		}
		//�ۼӷ�
		int numDay = 0;
		while (small!=big)
		{
			small++;
			numDay++;
		}
		return numDay;
	}

	void Printf()
	{
		cout << _year << "-" << _month << "-" << _day;
	}
private:
	int _year;
	int _month;
	int _day;
};

//+=,-=
void Text1()
{
	//+=
	Date d1(2020, 3, 19);
	d1.Printf();
	Date d2 = d1 += 100;
	cout << "  +=  " << 100 << "  =  ";
	d2.Printf();
	cout << endl;

	//-=
	Date d3(2020, 6, 27);
	d3.Printf();
	Date d4 = d1 -= -27;
	cout << "  -=  " << 27 << "  =  ";
	d4.Printf();
	cout << endl;
}
//+,-
void Text2()
{
	//+=
	Date d1(2020, 3, 19);
	d1.Printf();
	Date d2 = d1 += 100;
	cout << "  +  " << 100 << "  =  ";
	d2.Printf();
	cout << endl;

	//-=
	Date d3(2020, 6, 27);
	d3.Printf();
	Date d4 = d1 -= 58;
	cout << "  -  " << 59 << "  =  ";
	d4.Printf();
	cout << endl;
}

//++,--
void Text3()
{
	//i++
	Date d1(2020, 3, 31);
	d1.Printf();
	Date d2 = d1++;
	cout << "++" << " = ";
	d2.Printf();
	cout << ' ';
	d1.Printf();
	cout << endl;

	//++i
	Date d3(2020, 3, 31);
	cout << "++(" ;
	d3.Printf();
	Date d4 = ++d3;
	cout<< ") = ";
	d4.Printf();
	cout << endl;

	//i--
	Date d5(2020, 3, 1);
	d5.Printf();
	Date d6 = d5--;
	cout << "--" << " = ";
	d6.Printf();
	cout << ' ';
	d5.Printf();
	cout << endl;

	//--i
	Date d7(2020, 3, 1);
	cout << "--(";
	d7.Printf();
	Date d8 = --d7;
	cout << ") = ";
	d8.Printf();
	cout << endl;
}
//> < == <= >= !=
void Text4()
{
	Date d1(2020, 3, 19);
	Date d2(2020, 3, 20);
	//d1++;
	//>
	d1.Printf();
	cout << " > ";
	d2.Printf();
	cout << ' ' << (d1 > d2) << endl;

	//<
	d1.Printf();
	cout << " < ";
	d2.Printf();
	cout << ' ' << (d1 < d2) << endl;

	//==
	d1.Printf();
	cout << " == ";
	d2.Printf();
	cout << ' ' << (d1 == d2) << endl;

	//>=
	d1.Printf();
	cout << " >= ";
	d2.Printf();
	cout << ' ' << (d1 >= d2) << endl;

	//<=
	d1.Printf();
	cout << " <= ";
	d2.Printf();
	cout << ' ' << (d1 <= d2) << endl;

	//!=
	d1.Printf();
	cout << " != ";
	d2.Printf();
	cout << ' ' << (d1 != d2) << endl;
}
int main()
{
	Text1();
	Text2();
	Text3();
	Text4();
	//�������
	Date d2(2020, 3, 19);
	Date d1(2020, 6, 27);
	d1.Printf();
	cout << " - ";
	d2.Printf();
	cout <<" = "<< (d1 - d2) << endl;
	return 0;
}