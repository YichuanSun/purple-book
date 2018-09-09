#include <stdio.h>

int main()
{
	int n,m,i,j=0;
	double sum=0;
	while (scanf("%d %d",&n,&m)&&n&&m)
	{
		for (i=n;i<=m;i++)
			sum=sum+1.0/i/i;
		printf("Case %d: %.5lf\n",++j,sum);
		sum=0;
	}
	return 0;
}
