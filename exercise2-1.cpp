#include <stdio.h>

int main()
{
	int i,h,y,o,sum;
	for (i=100;i<1000;i++)
	{
		h=i/100;
		y=i/10-h*10;
		o=i-h*100-y*10;
		sum=h*h*h+y*y*y+o*o*o;
		if (sum==i)
			printf("%d\n",i);
	}
	return 0;
}
