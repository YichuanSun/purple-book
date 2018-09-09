#include <stdio.h>
#include <memory.h>
#define N 11
int amt[N];
int judge(int n)
{
	amt[n/100]++;
	amt[n/10%10]++;
	amt[n%10]++;
	int i;
	for (i=0;i<10;i++)
	{
		if (amt[i]>1||amt[0]!=0)
			return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	for (i=123;i<333;i++)
	{
		if (judge(i)&&judge(2*i)&&judge(3*i))
			printf("%d %d %d\n",i,2*i,3*i);
		for (j=0;j<N;j++)
			amt[j]=0;
	}
	return 0;
} 
