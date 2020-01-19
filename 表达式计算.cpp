#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

stack<char> ch;
stack<int> num;

void Slove(int num1,int num2,char c)
{
	int count = 0;
	switch(c)
	{
		case '+':
			{
				count = num1 + num2;
				break;
			}
		case '-':
			{
				count = num1 - num2;
				break;
			}
		case '*':
			{
				count = num1 * num2;
				break;
			}
		case '/':
			{
				count = num1 / num2;
				break;
			}
	}
	num.push(count);
}

void calculate1()
{
	while(ch.top() != '(')
	{
		int count1 = num.top();
		num.pop();
		int count2 = num.top();
		num.pop();
		Slove(count2,count1,ch.top());
		ch.pop();
	}
}

void calculate2()
{
	while(ch.top() == '*' || ch.top() == '/')
	{
		int count1 = num.top();
		num.pop();
		int count2 = num.top();
		num.pop();
		Slove(count2,count1,ch.top());
		ch.pop();
	}
}

int ToNum(char* str,int* i)
{
	int count = 0;
	char* src = str;
	while((src[*i]) >= '0' && (src[*i]) <= '9')
	{
		count = count * 10 + src[*i] - '0';
		(*i)++;
	}
	
	return count;
}

int main()
{
	char str[200] = {'\0'};
	str[0] = '(';
	scanf("%s",str+1);
	int len = strlen(str);
	str[len] = ')';
	int i = 0;
	for(i = 0; i <= len; i++)
	{
		switch(str[i])
		{
			case '+':
			case '-':
				{
					calculate1();
					ch.push(str[i]);
					break;
				}
			case '*':
			case '/':
				{
					calculate2();
					ch.push(str[i]);
					break;
				}
			case '(':
				{
					ch.push(str[i]);
					break;
				}
			case ')':
				{
					calculate1();
					ch.pop();
					break;
				}
			default :
				{
					int count = ToNum(str,&i);
					num.push(count);
					i--;
					//cout<<count<<endl;
					break;
				}
				
		}
		
	}

	cout<<num.top()<<endl;
	return 0;
}
