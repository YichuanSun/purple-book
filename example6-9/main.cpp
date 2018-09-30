#include <bits/stdc++.h>
using namespace std;
bool solve(int &W);
int main()  {
    int n,w;
    cin>>n;
    while (n--)     {
        if (solve(w))   cout<<"YES\n";
        else cout<<"NO\n";
        if (n)  cout<<endl;
    }
    return 0;
}

bool solve(int &W)    {
    int w1,d1,w2,d2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    bool l=true,r=true;
    if (!w1)    l=solve(w1);
    if (!w2)    r=solve(w2);
    return l&&r&&(w1*d1==w2*d2);
}
