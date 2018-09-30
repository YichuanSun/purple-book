#include <bits/stdc++.h>
#define N 11
using namespace std;
int si[N];
int main()  {
    int n,cnt=0;
    while (scanf("%d",&n)&&n)   {
        if (cnt++)  printf("\n");
        bool flag=false;
        for (int i=1234;i<=98765;i++)    {
            bool f=true;
            int t=i;
            if (t*n>99999||t*n<10000) continue;
            int m=t*n;
            while (m)   {
                si[m%10]++;
                m/=10;
            }
            if (i<10000) si[0]++;
            while (t)   {
                si[t%10]++;
                t/=10;
            }
            for (int i=0;i<10;i++)
                if (si[i]>1)    {f=false;break;}
            if (f)  {printf("%05d / %05d = %d\n",i*n,i,n);flag=true;}
            fill(si,si+10,0);
        }
        if (!flag)  printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
