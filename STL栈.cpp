#include <cstdio>
#include <cstdlib>
#define N 100 
int cmphl(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
} 
int cmplh(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
} 
int main()
{
	freopen("abc.txt","wa",stdout);
	int a[N],b[N],c[N],n,k,i,j;
	while (scanf("%d",&n)==1&&n)
	{
		j=n;
		while (j==n)
		{
			for (j=0;j<n;j++)
			{
				scanf("%d",&a[j]);
				c[j]=a[j];
				if (a[0]==0)
					break;
			}
			if (j!=n)
			{
				printf("\n");
				continue;
			}
			for (k=n-1,i=0;i<n;i++)		//µ¹ÐòÐòÁÐb 
				b[i]=a[k--];
			qsort(c,n,sizeof(int),cmphl);
			qsort(a,n,sizeof(int),cmplh);
			for (i=0;i<n;i++)
				if (!(c[i]==b[i]||a[i]==b[i]))
					break;
			if (i!=n)
				printf("No\n");
			else
				printf("Yes\n");	
		}
	}
	return 0;
}


