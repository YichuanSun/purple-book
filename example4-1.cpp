#include <stdio.h>
#include <string.h>
#define N 101
int main()
{
	char str1[N],str2[N];
	while (gets(str1))
	{
		gets(str2);
		int len=strlen(str1),i;
		int num1[N],num2[N],jud1[N],jud2[N];
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(jud1,0,sizeof(jud1));
		memset(jud2,0,sizeof(jud2));
		for (i=0;i<len;i++)
		{
			num1[str1[i]-'A'+1]++;
			num2[str2[i]-'A'+1]++;
		}
		for (i=0;i<27;i++)
		{
			jud1[num1[i]]++;
			jud2[num2[i]]++;
		}
		for (i=0;i<27;i++)
			if (jud1[i]!=jud2[i])
				break;
		if (i==27)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
