#include <stdio.h>
#define N 10000
int main()
{
	int i,j=1,k,max=0,min=N,n;
	float sum=0;
	while (scanf("%d",&n)&&n)
	{
		for (i=0;i<n;i++)
		{
			scanf("%d",&k);
			sum+=k;
			if (max<k)
				max=k;
			if (min>k)
				min=k;
		}
		printf("Case %d: %d %d %.2f\n",j++,min,max,sum/n);
		max=0,min=N,sum=0;
	}
	return 0;
}
