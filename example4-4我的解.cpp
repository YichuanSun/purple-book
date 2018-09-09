#include <stdio.h>
#include <string.h>

int code[8][1<<8];
int readint(int c);
int readchar();
int readcode();

int main()
{
	while (readcode())
	{
		for (;;)
		{
			int len=readint(3);
			if (len==0)	break;
			for (;;)
			{
				int t=readint(len);
				if (t==(1<<len)-1) break;
				putchar(code[len][t]);
			}
		}
		putchar('\n');
	}
	return 0;
} 

int readint(int c)			//把一个二进制数转换为十进制数 
{
	int v=0;
	while (c--)
		v=v*2+readchar()-'0';
	return v;
}

int readchar()
{
	for (;;)
	{
		int ch=getchar();
		if (ch!='\n'&&ch!='\r')	return ch;	
	}
}

int readcode()
{
	int len;
	memset(code,'\0',sizeof(code));
	code[1][0]=readchar();
	for (len=2;len<7;len++)
	{
		for (int i=0;i<(1<<len)-1;i++)
		{
			int ch=getchar();
			if (ch=='\r'||ch=='\n')	return 1;
			if (ch==EOF)	return 0;
			code[len][i]=ch;
		}
	}
	return 1;
}
