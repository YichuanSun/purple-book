#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N],dp[N],q[N],head=1,tail=0;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)   cin>>a[i];
    for (int i=1;i<=n;i++)   {
        while (head<=tail&&dp[i-1]<dp[q[tail]])    tail--;
        q[++tail]=i-1;
        while (head<=tail&&a[q[head]]<i-m)  head++;
        dp[i]=dp[q[head]]+a[i];
    }
    for (int i=0;i<=n;i++)   cout<<dp[i]<<' ';
    cout<<endl;
    return 0;
}
