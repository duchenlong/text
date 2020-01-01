#include<stdio.h>

int main()
{
	int v1,v2,l,t=0,s=0;
	scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&l);
	
	int time=0;
	int gui=0,tu=0;
	
	while(gui<l && tu<l)
	{
		tu+=v1;
		gui+=v2;
		time++;
		if(tu==l || gui==l) break;
		if(tu-gui>=t) tu-=v1*s;
		printf("%d %d %d\n",tu,gui,time);
	}
	
	if(gui==tu)
	{
		printf("D\n");
	}
	else if(tu>=l)
	{
		printf("R\n");
	}
	else
	{
		printf("T\n");
	}
	printf("%d\n",time);
	
	return 0;
}
