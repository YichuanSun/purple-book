#include <bits/stdc++.h>
#define N 20
using namespace std;
char C[N][N];
int v[3][N];
int n,tot;
void Search(int row);
int main()  {
    int a,b;
    fill(C[0],C[0]+N*N,'.');
    scanf("%d",&n);
    for (int i=0;i<n;i++)   {
        scanf("%d%d",&a,&b);
        C[a][b]='Q';
        v[0][b]=v[1][a+b]=v[2][a-b+n]=1;
    }
    Search(0);
    for (int i=0;i<8;i++)   {
        for (int j=0;j<8;j++)
            printf("%c",C[i][j]);
        printf("\n");
    }
    printf("%d\n",tot);
    return 0;
}

void Search(int row)    {
    if (row==8) {
        tot++;
        return;
    }
    int f=0;
    for (int i=0;i<8;i++)   {
        if (f)  break;
        if (C[row][i]=='Q')
            f++,Search(row+1);
    }
    if (f)  return;
    for (int i=0;i<8;i++)   {
        int ff=0;
        if (C[row][i]=='Q') ff=1;
        if (!v[0][i]&&!v[1][row+i]&&!v[2][row-i+n]) {
            C[row][i]='Q';
            v[0][i]=v[1][row+i]=v[2][row-i+n]=1;
            Search(row+1);
            if (!ff)    C[row][i]='.'
            v[0][i]=v[1][row+i]=v[2][row-i+n]=0;
        }
    }
}





