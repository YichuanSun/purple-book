#include <stdio.h>
#include <string.h>

int code[8][1<<8];
int readchar()
{
	for (;;)
	{
		int ch=getchar();
		if (ch!='\n'&&ch!='\r')	return ch;
	}
}

int readint(int c)		//将二进制C转换为十进制数 
{
	int v=0;
	while (c--)
		v=v*2+readchar()-'0';
	return v;
}

int readcodes()
{
	memset(code,0,sizeof(code));
	code[1][0]=readchar();
	for (int len=2;len<=7;len++)
	{
		for (int i=0;i<(1<<len)-1;i++)
		{
			int ch=getchar();
			if (ch==EOF)	return 0;
			if (ch=='\n'||ch=='\r')	return 1;
			code[len][i]=ch;
		}
	}
	return 1;
}

int main()
{
	while (readcodes())
	{
		for (;;)
		{
			int len=readint(3);
			if (len==0)	break;
			for (;;)
			{
				int v=readint(len);
				if (v==(1<<len)-1)	break;
				putchar(code[len][v]);
			}
		} 
		putchar('\n');
	}
	return 0;
}
