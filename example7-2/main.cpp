#include <bits/stdc++.h>
#define N 25
using namespace std;
int a[N],cnt,n;
long long tms[N],ans;
int main()  {
    while (scanf("%d",&n)!=EOF)  {
        if (cnt++)  printf("\n");
        for (int i=0;i<n;i++)   scanf("%d",&a[i]);
        tms[0]=1;
        for (int i=1;i<=n;i++)   tms[i]=tms[i-1]*a[i-1];
        printf("\n");
        for (int i=0;i<=n;i++)   {
            for (int j=i+1;j<=n;j++) {
                long long t=tms[j]/tms[i];
                if (t>ans)  ans=t;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n",cnt,ans);
    }
    return 0;
}
