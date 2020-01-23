#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    char* small ,*big;
    
    int min,max;
    if(lena < lenb)
    {
        small = a;
        big = b;
        min = lena;
        max = lenb;
    }
    else
    {
        small = b;
        big = a;
        min = lenb;
        max = lena;
    }
    char* str = (char*)malloc(sizeof(char)*(max+5));
    int i = 0;
    int num = 0;
    int len = 0;
    for(i = min - 1; i >= 0; i--)
    {
        num += small[i] - '0' + big[--max] - '0';
        str[len] = num % 2 + '0';
        num /= 2;
        len++;
    }
    for(i = max- 1; i >= 0; i--)
    {
        num += big[i] - '0';
        str[len] = num % 2 + '0';
        num /= 2;
        len++;
    }
    if(num)
    {
        str[len++] = '1';
    }
    int j = 0;
    for(j = 0; j < len/2; j++)
    {
        char ch = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = ch;
    }
    str[len] = '\0';
    return str;
}

int main()
{
	char* str1 = "1011";
	char* str2 = "1001";
	puts(addBinary(str1,str2));
	return 0;
}
