//又没找出bug来。。。看着和标程一样啊
#include <bits/stdc++.h>
#define N 1000000
using namespace std;
typedef int State[9];
State st[N],goal;
int mox[]={-1,1,0,0},moy[]={0,0,-1,1};
int fact[9]={1},vis[N],dist[N];
int bfs();
int main()  {
    for (int i=0;i<9;i++)   scanf("%d",&st[1][i]);
    for (int i=0;i<9;i++)   scanf("%d",&goal[i]);
    int ans=bfs();
    if (ans>0)  printf("%d\n",dist[ans]);
    else    printf("-1\n");
    return 0;
}

void init_table()   {
    for (int i=1;i<9;i++)   fact[i]=fact[i-1]*i;
}
int can_insert(int r)   {
    int code=0;
    for (int i=0;i<9;i++)   {
        int cnt=0;
        for (int j=i+1;j<9;j++)
            if (st[r][j]<st[r][i])  cnt++;
        code+=fact[8-i]*cnt;
    }
    if (vis[code])  return 0;
    return vis[code]=1;
}

int bfs()  {
    init_table();
    int frt=1,rear=2;
    while (frt<rear)  {
        State& ts=st[frt];
        if (memcpy(goal,ts,sizeof(ts))==0)  return frt;
        int z;
        for (z=0;z<9;z++)  if (!ts[z]) break;
        int x=z/3,y=z%3;
        for (int d=0;d<4;d++)   {
            int nx=x+mox[d];
            int ny=y+moy[d];
            int nz=nx*3+ny;
            if (nx>=0&&nx<3&&ny>=0&&ny<3) {
                State& te=st[rear];
                memcpy(&te,&ts,sizeof(ts));
                te[nz]=ts[z];
                te[z]=ts[nz];
                dist[rear]=dist[frt]+1;
                if (can_insert(rear)) rear++;
            }
        }
        frt++;
    }
    return 0;
}


