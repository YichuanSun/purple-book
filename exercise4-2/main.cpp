#include <bits/stdc++.h>
#define N 15
using namespace std;
int h[N][N],v[N][N];
int main()  {
    int n,m,T=0,t1,t2;
    char c;
    while (scanf("%d%d",&n,&m)!=EOF)    {
        fill(h[0],h[0]+N*N,0);
        fill(v[0],v[0]+N*N,0);
        int flag=0;
        getchar();
        for (int i=0;i<m;i++)   {
            scanf("%c%d%d",&c,&t1,&t2);
            getchar();
            if (c=='H') h[t1][t2]=1;
            else if (c=='V')    v[t1][t2]=1;
        }
        if (T++)    printf("**********************************\n\n");
        printf("Problem #%d\n\n",T);
        for (int len=1;len<=n;len++)    {
            int sum=0;
            for (int i=1;i+len<=n;i++)   {
                for (int j=1;j+len<=n;j++)  {
                    int cnt=1;
                    for (int k=0;k<len;k++)    {
                        if (!h[i][j+k]||!h[i+len][j+k]) {cnt=0;break;}
                        if (!v[i+k][j]||!v[i+k][j+len]) {cnt=0;break;}
                    }
                    sum+=cnt;
                }
            }
            if (sum)    {
                flag=1;
                printf("%d square (s) of size %d\n",sum,len);
            }
        }
        if (!flag)  printf("No completed squares can be found.\n");
    }
    return 0;
}
