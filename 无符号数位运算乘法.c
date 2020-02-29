#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int i = 0;
	int ans = 0;
	for(i = 0; i < 32; i++)
	{
		if(m & 1)
			ans += n;
		
		n = n << 1;
		m = m >> 1;
	}
	
	printf("%d\n",ans);
	return 0;
}
