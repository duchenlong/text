#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];//拿到当前月除了2.29的最大日期

		//如果出现2月29日
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}

		return day;
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
	}

	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
		return *this;
	}
	// 析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	// 日期+=天数
	Date& operator+=(int day)
	{
		//如果日期是负数
		if (day < 0)
		{
			*this -= -day;
			return *this;
		}

		_day += day;
		int maxDay = GetMonthDay(_year, _month);//获取当前月的最大天数
		while (maxDay < _day)
		{
			_day -= maxDay;//减掉当前月的天数
			_month++;//月+1
			//如果月超了，年+1，月变成1月
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			maxDay = GetMonthDay(_year, _month);
		}
		return *this;
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		//如果要减的日期是负数
		if (day < 0)
		{
			*this += -day;
			return *this;
		}
		while (_day <= day)
		{
			_month--;//当前月份-1
			//如果没得减，返回上一年
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
	// 日期+天数
	Date operator+(int day)
	{
		Date tmp(*this);
		//tmp.operator+=(day);
		tmp += day;
		return tmp;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date tmp(*this);
		//tmp.operator-=(day);
		tmp -= day;
		return tmp;
	}
	
	// 前置++ , ++i
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	// 后置++ ,为了区分前置++，加一个参数 i++
	Date operator++(int)//Date operator++(int i) //也可以这样
	{
		Date tmp(*this);//拷贝++之前的值
		*this += 1;
		return tmp;
	}
	// 后置-- i--
	Date operator--(int)
	{
		Date tmp(*this);//拷贝++之前的值
		*this -= 1;
		return tmp;
	}
	// 前置--  --i
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		////根据年直接比
		//if (_year > d._year)
		//	return true;
		////年相等比月
		//if (_year == d._year && _month > d._month)
		//	return true;
		////年月相等比天
		//if (_year == d._year && _month == d._month && _day > d._day)
		//	return true;

		if ((_year > d._year) || \
			(_year == d._year && _month > d._month) || \
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		return false;

	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return _day == d._day &&\
			_month == d._month &&\
			_year == d._year;
	}
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		//即不小于 小于为假
		return !(*this < d);
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		//如果等于，和大于，则为假
		if (*this == d || *this>d)
			return false;
		return true;
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		//即不大于，大于为假
		return  !(*this > d);
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		//即等于为假
		return !(*this == d);
	}
	bool LeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;

		return false;
	}
	// 日期-日期 返回天数
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
		//累加法
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
	//日期相减
	Date d2(2020, 3, 19);
	Date d1(2020, 6, 27);
	d1.Printf();
	cout << " - ";
	d2.Printf();
	cout <<" = "<< (d1 - d2) << endl;
	return 0;
}