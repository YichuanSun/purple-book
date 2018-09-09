#include <stdio.h>

int main()
{
	int a,b,c,i=0,sum=10;
	while (sum>=10&&sum<100)
	{
		scanf("%d %d %d",&a,&b,&c);
		for (sum=10;sum<100;sum++)
			if ((sum-a==(sum-a)/3*3)&&(sum-b==(sum-b)/5*5)&&(sum-c==(sum-c)/7*7))
			{
				printf("Case %d: %d\n",++i,sum);
				break;
			}
				
	}
	if (sum<10||sum>=100)
		printf("Case %d: No answer\n",++i);
	return 0;
}
