#include <bits/stdc++.h>
using namespace std;
string s,t;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin>>s>>t)   {
        int spos=0,tpos=0;
        while (spos!=(int)s.size()&&tpos<(int)t.size())  {
            if (s[spos]==t[tpos])
                spos++,tpos++;
            else    tpos++;
        }
        if (spos==(int)s.size()) cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
    return 0;
}
