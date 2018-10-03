#include <bits/stdc++.h>
#define N 1005
using namespace std;
int s[N],cnt,n,l;
int dfs(int cur);
int main()  {
    while (scanf("%d%d",&n,&l)&&n)  {
        cnt=0;
        dfs(0);
    }
    return 0;
}

int dfs(int cur)   {
    if (cnt++==n)    {
        for (int i=0;i<cur;i++) {
            if(i%64==0&&i>0) printf("\n");
            else if (i&&i%4==0)  printf(" ");
            printf("%c",'A'+s[i]);
        }
        printf("\n%d\n",cur);
        return 0;
    }
    else for (int i=0;i<l;i++)   {
        s[cur]=i;
        int ok=1;
        for (int j=1;2*j<=cur+1;j++)    {
            int rr=1;
            for (int k=0;k<j;k++)
                if (s[cur-k]!=s[cur-j-k])   {rr=0;break;}
            if (rr) {ok=0;break;}
        }
        if (ok) if (!dfs(cur+1))    return 0;
    }
    return 1;
}






