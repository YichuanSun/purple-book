#include <bits/stdc++.h>
#define INF 10000005
using namespace std;

int main()  {
    int n,a=INF,b,c,d;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>ta>>tb>>tc>>td;
        a=min(ta,a),b=min(tb,b),c=min(tc,c),d=min(td,d);
    }
    string sa=ex(a),sb=ex(b),sc=ex(c);
    return 0;
}

string ex(int x)    {
    string ts;
    if (!x) {ts="0";return ts;}
    while (x)   {
        ts+=(x&1);
        x>>=1;
    }
    return ts;
}
