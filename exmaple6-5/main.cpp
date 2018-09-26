#include <bits/stdc++.h>
#define N 100005
using namespace std;
int Left[N],Right[N];
bool spot;
int n,m,op,cnt=1;
void change(int L,int R)    {
    Left[R]=L,Right[L]=R;
}
void m1();
void m2();
void m3();
int main()  {
    while (scanf("%d%d",&n,&m)!=EOF)    {
        for (int i=1;i<=n;i++)   {
            Right[i]=(i+1)%(n+1);
            Left[i]=i-1;
        }
        Right[0]=1,Left[0]=n;
        for (int i=0;i<m;i++)   {
            scanf("%d",&op);
            if (spot&&(op==1||op==2))   op=3-op;
            switch(op)  {
                case 1: m1();break;
                case 2: m2();break;
                case 3: m3();break;
                case 4: spot=!spot;break;
            }
        }
        long long sum=0;
        int m=0;
        for (int i=1;i<=n;i++)  {       //双向链表的起点我没想到如何找，这个靠0来找真巧妙
            m=Right[m];
            if (i&1)    sum+=m;
        }
        if (spot&&((n&1)==0))   sum=(long long)n*(n+1)/2-sum;
        printf("Case %d: %lld\n",cnt++,sum);
        spot=0;
    }
    return 0;
}

void m1()   {
    int x,y;
    scanf("%d%d",&x,&y);
    if (Left[y]==x) return;
    change(Left[x],Right[x]);
    change(Left[y],x);
    change(x,y);
}

void m2()   {
    int x,y;
    scanf("%d%d",&x,&y);
    if (Right[y]==x)    return;
    change(Left[x],Right[x]);
    change(x,Right[y]);
    change(y,x);
}

void m3()   {
    int x,y;
    scanf("%d%d",&x,&y);
    if (Right[x]==y)    {
        change(Left[x],y);
        change(y,x);
        change(x,Right[y]);
        return;
    }
    change(Left[x],y);
    change(y,Right[x]);
    change(Left[y],x);
    change(x,Right[y]);
}
