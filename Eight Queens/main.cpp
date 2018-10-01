#include <bits/stdc++.h>
#define N 100
using namespace std;
int tot,n;
int C[N];
bool vis[3][N];
void Search(int row);
int main()  {
    cin>>n;
    Search(0);
    cout<<tot<<endl;
    return 0;
}
//vis数组，提高了搜索效率，确定三个方向上是否有其他皇后
void Search(int row)    {
    if (row>=n) tot++;
    else for (int i=0;i<n;i++)  {
        if (!vis[0][i]&&!vis[1][row+i]&&!vis[2][row-i+n])  {
            C[row]=i;
            vis[0][i]=vis[1][row+i]=vis[2][row-i+n]=1;
            Search(row+1);
            vis[0][i]=vis[1][row+i]=vis[2][row-i+n]=0;
        }
    }
}

//void Search(int row)    {
//    if (row==n) tot++;
//    else
//        for (int i=0;i<n;i++)   {
//            C[row]=i;
//            int ok=1;
//            for (int j=0;j<row;j++)
//                if (C[row]==C[j]||row-C[row]==j-C[j]||row+C[row]==j+C[j])
//                    {ok=0;break;}
//            if (ok) Search(row+1);
//        }
//}
