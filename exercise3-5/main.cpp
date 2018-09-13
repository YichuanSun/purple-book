#include <bits/stdc++.h>
#define N 7
#define M_N 100005
using namespace std;
char ch[N][N],dic[M_N];
pair<int,int> now;
bool scf(),fg;
int main()  {
    //freopen("input.txt","ra",stdin);
    //freopen("output.txt","wa",stdout);
    int dd=0;
    while (scf())   {
        char c;
        int cnt=0;
        while ((c=getchar())&&c!='0')
            dic[cnt++]=c;
        getchar();
        dic[cnt]='\0';
        bool flag=true;
        int len=strlen(dic);
        for (int i=0;i<len;i++) {
            if (!isalpha(dic[i]))   continue;
            int ti=now.first,tj=now.second;
            switch(dic[i])    {
                case 'A': ti--;break;
                case 'B': ti++;break;
                case 'L': tj--;break;
                case 'R': tj++;break;
                default: {
                    flag=false;
                    goto ed;
                }
            }
            if (ti<0||ti>4||tj<0||tj>4) {
                flag=false;
                break;
            }
            swap(ch[now.first][now.second],ch[ti][tj]);
            now.first=ti,now.second=tj;
        }
        ed:;
        printf("Puzzle #%d:\n",++dd);
        if (flag)   {
            for (int i=0;i<5;i++)   {
                printf("%c",ch[i][0]);
                for (int j=1;j<5;j++)
                    printf(" %c",ch[i][j]);
                printf("\n");
            }
        }
        else    printf("This puzzle has no final configuration.\n");
    }
    return 0;
}

bool scf()  {
    fill(ch[0],ch[0]+N*N,'\0');
    for (int i=0;i<5;i++)   {
        gets(ch[i]);
        if (strlen(ch[i])==1)   return false;
        for (int j=0;j<5;j++)   {
            if (ch[i][j]=='\n') ch[i][j]=' ';
            if (ch[i][j]==' ')
                now.first=i,now.second=j;
        }
        ch[i][5]='\0';
    }
    if (fg)   printf("\n");
    fg=true;
    return true;
}
