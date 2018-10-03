#include <bits/stdc++.h>
#define N 200
using namespace std;
int a[N];

void motion(int pos)   {
    int v;
    cin>>v;
    if (v==-1)  return;
    a[pos]+=v;
    motion(pos-1);
    motion(pos+1);
}

bool init() {
    int root;
    cin>>root;
    if (root==-1)   return false;
    fill(a,a+N,0);
    int pos=N/2;
    a[pos]=root;
    motion(pos-1);
    motion(pos+1);
}

int main()  {
    //freopen("out.txt","wa",stdout);
    int kase=1;
    while (init())    {
        int p=0;
        while (a[p]==0) p++;
        cout<<"Case "<<kase++<<':'<<'\n'<<a[p++];
        while (a[p]!=0)   {
            cout<<' '<<a[p];
            p++;
        }
        cout<<"\n\n";
    }
    return 0;
}
