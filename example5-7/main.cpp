#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int ge[4]={2,3,5};
priority_queue<ll,vector<ll>,greater<ll> > pq;
set<ll> s;
int main()  {
    pq.push(1);
    for (int i=1;;i++)  {
        ll x=pq.top();pq.pop();
        if (i==1500)    {
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        for (int j=0;j<3;j++)   {
            ll t=x*ge[j];
            if (!s.count(t))    {s.insert(t),pq.push(t);}
        }
    }
    return 0;
}
