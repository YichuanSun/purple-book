#include <stdio.h>

int main()
{
	int n,k=0,a[100],i;
	while (scanf("%d",&n))
		a[k++]=n;
	for (i=k-1;i>=1;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[0]);
	return 0;
}
