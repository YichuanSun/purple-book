#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1005
using namespace std;
int a[N],n,dp[N],ans;
void solve();
int main()  {
    scanf("%d",&n);
    fill(dp,dp+n,1);
    for (int i=0;i<n;i++)   scanf("%d",&a[i]);
    solve();
    for (int i=0;i<n;i++)   ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}

void solve()    {
    for (int i=0;i<n;i++)   {
        for (int j=i;j<n;j++)   {
            if (a[j]>a[i])
                dp[j]=max(dp[j],dp[i]+1);
        }
    }
}
