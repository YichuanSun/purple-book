#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define N 105
using namespace std;
int r,c,h[N][N],dp[N][N],ans;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct hill {
    int h;
    int ii,jj;
    hill(int a=0,int b=0,int c=0)  {h=a,ii=b,jj=c;}
};
vector<hill> v;
bool cmp(hill a,hill b) {
    return a.h<b.h;
}
int main()  {
    scanf("%d%d",&r,&c);
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)   {
            scanf("%d",&h[i][j]);
            v.push_back(hill(h[i][j],i,j));
        }
    fill(dp[0],dp[0]+N*N,1);
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<(int)v.size();i++)   {
        int nx=v[i].ii,ny=v[i].jj;
        for (int s=0;s<4;s++)   {
            int tx=nx+dx[s],ty=ny+dy[s];
            if (tx<0||ty<0||tx>=r||ty>=c)   continue;
            if (h[tx][ty]<h[nx][ny])
                dp[nx][ny]=max(dp[nx][ny],dp[tx][ty]+1);
        }
    }
    for (int i=0;i<r;i++)   {
        for (int j=0;j<c;j++){
            //printf("%d ",dp[i][j]);
            ans=max(ans,dp[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}

