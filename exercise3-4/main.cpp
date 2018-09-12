#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s,t;
    cin>>n;
    while (n--) {
        bool flag=false;
        cin>>s;
        for (int i=1;i<(int)s.size();i++)   {
            t=s.substr(0,i);
            int cc=t.size(),ct=1;
            string ts=t;
            while (t.size()<=s.size())   {
                if (t!=s.substr(0,cc*ct))   break;
                ct++;
                t+=ts;
            }
            if (t==s+ts) {
                v.push_back(i);
                flag=true;
                break;
            }
        }
        if (!flag)  v.push_back((int)s.size());
    }
    int si=v.size();
    for (int i=0;i<si;i++)   {
        if (i!=si-1)    cout<<v[i]<<'\n'<<endl;
        else    cout<<v[i]<<endl;
    }
    return 0;
}
