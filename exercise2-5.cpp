#include <stdio.h>  //只模拟了结果小于1的情况 
#include <math.h>
#define N 1000
int ar[N];
int e(int n)
{
	int i,f=1;
	for (i=0;i<n;i++)
		f=f*10;
	return f;
}
int main()
{
	int a,b,c,i;
	double d;
	while (scanf("%d %d %d",&a,&b,&c)&&(a||b||c))
	{
		d=1.0*a/b;
		if (d<=1)
		{
			for (i=0;i<c;i++)
				ar[i]=(int)(d*e(i+1))%10;
			printf("0.");
			for (i=0;i<c;i++)
				printf("%d",ar[i]);
		}
	}
	return 0;
}
