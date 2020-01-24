#include <stdio.h>

long plusnum(char* str);
long minusnum(char* str)
{
    long num = 0;
    long count = 2147483648;
    char* src = str;
    while(*src>='0'  && *src<='9')
    {
        num = num * 10 + *src - '0';
        if(num > count)
        {
            return count;
        }
        src++;
    }
    num = 0 - num;
    return num;
}
long plusnum(char* str)
{
    long num = 0;
    int count = 2147483647;
    char* src = str;
    if(*src == '+')
    {
        src++;
    }
    while(*src>='0'  && *src<='9')
    {
        num = num * 10 + *src - '0';
        if(num > count)
        {
            return count;
        }
        src++;
    }
    return num;
}

int myAtoi(char * str){
    long num = 0;
    while(*str == ' ')
    {
        *str++;
    }
    if(str[0] == '+' || (str[0] >= '0' && str[0] <= '9'))
    {
        num = plusnum(str);
    }
    else if(str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
    {
        num = minusnum(str+1);
    }
    return (int)num;
}

int main()
{
	char* str = "-2147483647";
	printf("%d\n",myAtoi(str));
	return 0;	
} 
