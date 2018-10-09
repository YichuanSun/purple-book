#include <iostream>
#include <algorithm>
#define N 5000
#define M 13000
using namespace std;
int n,m,w[N],d[N],dp[N][M],dpp[M];
void solve();
void deal();
void prf();
int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>w[i]>>d[i];
//    solve();      //这个方法还是超时，不知为何
//    cout<<dp[n][m]<<endl;
    deal();
    cout<<dpp[m]<<endl;
    return 0;
}

void prf()  {
    system("pause");
    for (int i=0;i<=m;i++){
        cout.width(3);
        cout.fill(' ');
        cout<<dpp[i];
    }
    cout<<"\n\n";
}

void solve()    {
    for (int i=0;i<n;i++)   {
        for (int j=0;j<=m;j++)   {
            if (j<w[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+d[i]);
        }
    }
}

void deal() {
    for (int i=0;i<n;i++)   {
        for (int j=m;j>=w[i];j--)   {
            dpp[j]=max(dpp[j],dpp[j-w[i]]+d[i]);
            //prf();
        }
    }
}




