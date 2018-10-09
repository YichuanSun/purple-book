#include <iostream>
#include <algorithm>
#define N 5000
#define M 13000
using namespace std;
int n,m,w[N],d[N],dp[N][M],dpp[M];
//void solve();
void deal();
int main()  {
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>w[i]>>d[i];
//    solve();
//    cout<<dp[n][m]<<endl;
    deal();
    cout<<dpp[m]<<endl;
    return 0;
}

//void solve()    {
//    for (int i=0;i<n;i++)   {
//        for (int j=0;j<=m;j++)   {
//            if (j<w[i]) dp[i+1][j]=dp[i][j];
//            else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+d[i]);
//        }
//    }
//}

void deal() {
    for (int i=0;i<n;i++)   {
        for (int j=m;j>=w[i];j--)
            dpp[j]=max(dpp[j],dpp[j-w[i]]+d[i]);
    }
}




