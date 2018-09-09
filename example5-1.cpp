#include <cstdio>
#include <algorithm>
using namespace std;				//re了,最后发现是数组开小了，改成10000，过了 
const int N = 10000;
int main()
{
	//freopen("example5-1.txt","wa",stdout);
	int a,b,k=1,ar[N],se;
	while (scanf("%d %d",&a,&b)&&a)
	{
		printf("CASE# %d:\n",k++); 
		for (int i=0;i<a;i++)
			scanf("%d",&ar[i]);
		sort(ar,ar+a);
		while (b--)
		{
			scanf("%d",&se);
			int j=lower_bound(ar,ar+a,se)-ar;
			if (ar[j]==se)
				printf("%d found at %d\n",se,j+1);
			else
				printf("%d not found\n",se);
		}
	}
	return 0;
} 
