#include <bits/stdc++.h>
#define SIZE 1005
using namespace std;
int w[SIZE],v[SIZE],dp[SIZE][SIZE];
int N,V;
int rec(int i,int j);
int main()  {
    int n;
    cin>>n;
    fill(dp[0],dp[0]+SIZE*SIZE,-1);
    for (int i=0;i<n;i++)   {
        cin>>N>>V;
        for (int j=0;j<N;j++)   cin>>v[j];
        for (int j=0;j<N;j++)   cin>>w[j];
        memset(dp,-1,sizeof(dp));
        cout<<rec(0,V)<<endl;
    }
    return 0;
}

int rec(int i,int j) {
    if (dp[i][j]>=0)   return dp[i][j];
    int res;
    if (i==N)   {res=0;}
    else if (j<w[i])    {res=rec(i+1,j);}
    else {res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);}
    return dp[i][j]=res;
}
