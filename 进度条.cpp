#include<stdio.h>
#include<unistd.h>

int main()
{
	int i=0;
	char arr[51]={0};
	char* brr="|/-\\"; 
	for(i=0;i<50;i++)
	{
		arr[i]='#';
		printf("[%-50s][%d%%][%c]\r",arr,(i+1)*2,brr[i%4]);
		usleep(50000);
	}
}
