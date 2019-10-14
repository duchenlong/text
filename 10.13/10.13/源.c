#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
int main()
{
	void (*p1) ();  //函数指针
	void (*p2[5])();  //函数指针数组
	void ( * (*p3)[5]) ()=&p2;
	//p3是一个指针   指向一个数组 长度为5
	//数组里面放的是 void (*)();  函数指针

	return 0;
}
#if 0
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}

int main()
{
	int input = 1;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*p[5])(int ,int) = {0,add,sub,mul,div};//p-->函数指针数组 数组长度为5
	//  int (*) (int,int);
	while(input) 
	{
		printf("*******************************\n");
		printf("*****1.add********2.sub*******\n");
		printf("*****3.mul********4.dev********\n");
		printf("*********************************\n");
		printf("请输入你的操作：");
		scanf("%d",&input);
		if(input >= 1 && input <= 4)
		{
			printf("请输入两个操作数：");
			scanf("%d%d",&x,&y);
			ret = (*p[input]) (x,y);//调用函数指针
			printf("ret = %d\n",ret);
		}
	}
	return 0;
}

#include<stdio.h>
void text()
{
}
int main()
{
	printf("%p\n", text);
	printf("%p\n", &text);
	return 0;
}

//void printf_p(int p[3][5], int row, int col)
void printf_p(int(*p)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(p + i) + j));// p[i][j]相当于*(*(p + i) + j)
		}
		printf("\n");
	}
}
int main()
{
	int a[3][5] = { 1, 2, 3, 4, 5, 6, 7 };
	printf_p(a, 3, 5);
	//二维数组在传参的时候，数组名表示第一行整个元素的地址
	//可以用数组指针接收，对数组第一行的地址进行解引用
	return 0;
}


int main()
{
	int arr[3] = { 0 };
	printf("%d\n", arr);//数组首元素的地址
	printf("%d\n", &arr);//整个数组的地址
	printf("%d\n", arr + 1);//数组第二个元素的地址
	printf("%d\n", &arr + 1);//表示数组最后一个内存单元+1
	return 0;
}


int main()
{
	int* str1 = "hello word";
	int* str2 = "hello word";
	if (str1 == str2)
	{
		printf("str1 = str2\n");
	}
	else
	{
		printf("str1 != str2\n");
	}
	printf("%c", *str1);
	return 0;
}

int main()
{
	int n = 0x1112;
	char* p1 = (char*)&n;
	int *pi = &n;
	*p1 = 0;
	printf("%d,%p,%d", *p1);
	/*int a = 0;
	int* p=&a;
	printf("%p,%p,%d",&a,p,*p);*/
}

#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	//char *p = "asdfgh";
	printf("%p,%p", &a[0][0],&a[0][1]);
	return 0;
}
#endif