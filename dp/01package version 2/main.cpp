#include <iostream>
#define N 105
#define M 10005
#define INF 1000005
using namespace std;
int w[M],v[M],dp[N][M],n,W;
int main()  {
    fill(dp[0],dp[0]+N*M,INF);
    dp[0][0]=0;
    int n,ans=0;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>w[i];
    for (int i=0;i<n;i++)   cin>>v[i];
    cin>>W;
    for (int i=0;i<n;i++)   {
        for (int j=0;j<M;j++) {
            if (j<v[i]) dp[i+1][j]=dp[i][j];
            else    dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    for (int i=0;i<M;i++)
        if (dp[n][i]<=W)    ans=i;
    cout<<ans<<endl;
    return 0;
}
