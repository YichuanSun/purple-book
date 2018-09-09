#include <bits/stdc++.h>
#define N 1005
using namespace std;
int matrixs[N][N];
int main()  {
    int n,cnt=1,x,y;
    cin>>n;
    matrixs[x=0][y=n-1]=1;
    for (int i=0;i<(n+1)/2;i++) {
        while (x<n-1&&!matrixs[x+1][y]) matrixs[++x][y]=++cnt;
        while (y>0&&!matrixs[x][y-1])   matrixs[x][--y]=++cnt;
        while (x>0&&!matrixs[x-1][y])   matrixs[--x][y]=++cnt;
        while (y<n-1&&!matrixs[x][y+1]) matrixs[x][++y]=++cnt;
    }
    for (int i=0;i<n;i++){
        printf("%3d",matrixs[i][0]);
        for (int j=1;j<n;j++)   {
            printf(" %3d",matrixs[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
