#include <iostream>
#include <algorithm>
#define N 5000
#define M 13000
using namespace std;
int n,m,w[N],d[N],dp[N][M];
void solve();
int main()  {
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>w[i]>>d[i];
    solve();
    cout<<dp[n][m]<<endl;
    for (int i=0;i<n;i++)   {
        for (int j=0;j<=m;j++)  {
            cout.width(3);
            cout.fill(' ');
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

void solve()    {
    for (int i=1;i<=n;i++)   {
        for (int j=0;j<=m;j++)   {
            if (j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+d[i]);
        }
    }
}
