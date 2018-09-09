#include <stdio.h>
#include <iostream>
#include <memory.h>
#define N 27

int sum(bool a[N]) 		//计算布尔数组中的真值个数 
{
	int sum=0;
	for (int i=0;i<N;i++)
		if (a[i])
			sum++;
	return sum;
}

int blen(char a[N])		//计算字符数组中的字母种类 
{
	bool sp[N]={false};
	int sum=0;
	for (int i=0;a[i]!='\0';i++)
		sp[a[i]-'a']=true;
	for (int i=0;i<N;i++)
		if (sp[i])
			sum++;
	return sum;
}

int main()
{
	int i,n;
	bool spot[27],flag[27];
	char a[N],b[N];
	while (scanf("%d",&n),n!=-1)
	{
		int key=0;
		printf("Round %d\n",n);
		memset(spot,false,27);
		memset(flag,false,27);
		getchar();
		gets(a);
		gets(b);
		for (i=0;b[i]!='\0';i++)
		{
			if (key==7)				
				break;
			int p=0;
			if (flag[b[i]-'a'])				//判断是否已猜过这个字符
			{
				key++;
				continue;
			}
			else
				flag[b[i]-'a']=true;
			for (int j=0;a[j]!='\0';j++)
			{
				if (spot[a[j]-'a'])
					continue;
				if (b[i]==a[j])
				{
					spot[a[j]-'a']=true;
					p=1;
				}
			}
			if (!p)
				key++;
			if (blen(a)==sum(spot))
			{
				printf("You win.\n");
				goto end;
			}
		}
		if (b[i]||key==7)
		{
			printf("You lose.\n");
			continue;
		}
		if (b[i]=='\0'&&(sum(spot)<blen(a)))
			printf("You chickened out.\n");
		end:;
	}
	return 0;
}
