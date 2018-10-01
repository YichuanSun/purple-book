#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
void formation1(int n,int a[],int cur);
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>a[i];
    formation1(n,a,0);
    return 0;
}

void formation1(int n,int a[],int cur)  {
    for (int i=0;i<cur;i++) cout<<a[i]<<' ';
    cout<<endl;
    int s=cur?a[cur-1]+1:0;
    for (int i=s;i<n;i++)   {
        a[cur]=i;
        formation1(n,a,cur+1);
    }
}
