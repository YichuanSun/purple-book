#include <iostream>
#include <algorithm>
#define N 1005
using namespace std;
string s1,s2;
int dp[N][N];
void solve(string s1,string s2);
int main()  {
    while (cin>>s1>>s2) {
        fill(dp[0],dp[0]+N*N,0);
        solve(s1,s2);
        cout<<dp[(int)s1.size()][(int)s2.size()]<<endl;
    }
    return 0;
}

void solve(string s1,string s2) {
    for (int i=0;i<(int)s1.size();i++)  {
        for (int j=0;j<(int)s2.size();j++)  {
            if (s1[i]==s2[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
}
