#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
void formation1(int n,int a[],int cur);
void formation2(int n,int b[],int cur);
int main()  {
    int n;
    cin>>n;
    //for (int i=0;i<n;i++)   cin>>a[i];
    formation2(n,a,0);
    return 0;
}

//下面是增量构造法
void formation1(int n,int a[],int cur)  {
    for (int i=0;i<cur;i++) cout<<a[i]<<' ';
    cout<<endl;
    int s=cur?a[cur-1]+1:0;
    for (int i=s;i<n;i++)   {
        a[cur]=i;
        formation1(n,a,cur+1);
    }
}

//下面是位向量法
bool b[N];
void formation2(int n,int b[],int cur)  {
    if (cur==n) {
        for (int i=0;i<cur;i++)
            if (b[i])   printf("%d ",i);
        printf("\n");
        return;
    }
    b[cur]=1;
    formation2(n,b,cur+1);
    b[cur]=0;
    formation2(n,b,cur+1);
}




