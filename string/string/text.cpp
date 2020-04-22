#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vld.h>
#include "string.hpp"



int main()
{
	//int[] arr = new arr[10];
	my_string str("hello world");
	char ch = str[10];
	//cout << ch << endl;
	//cout << str << endl;
	my_string src(" i am fine");
	str += src;
	//str.append("hahahhah");
	str.insert(0, 'A');
	cout << str.size() << endl;
	char* ret = "123456789";
	cout << strlen(ret) << endl;
	str.insert(str.size() - 2, ret);
	cout << str << endl;
	cout << str.size() << endl;
	for (int i = str.size()-1; i >= 0; i--)
	{
		cout << i <<' '<< str[i] << endl;
	}
	str.erase(str.size() - 9, 5);
	cout << str << endl;
	cout << str.size() << endl;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		cout << i << ' ' << str[i] << endl;
	}
	str.p();
	my_string cnt;
	cin >> cnt;
	/*cnt.clear();
	cin >> cnt;*/
	cnt += " world";
	for (int i = cnt.size() - 1; i >= 0; i--)
	{
		cout << i << ' ' << cnt[i] << endl;
	}
	cout << cnt;
	cout << cnt.find("wold", 0) << endl;
	cout << cnt.substr(2, 6) << endl;
	return 0;
}

