#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<char,pii> mcp;
char c;
pii tp;
string s;
stack<pii> st;
ll sum;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>c>>tp.first>>tp.second;
        mcp[c]=tp;
    }
    while (cin>>s)  {
        int cn1=0,cn2=0,flag=0;
        if ((int)s.size()==1)   {cout<<0<<endl;continue;}
        for (int i=0;i<(int)s.size();i++)   {
            if (s[i]=='(')  cn1++;
            else if (s[i]==')') {
                cn2++;
                if (st.empty()) continue;
                pii tp1=st.top();st.pop();
                if (st.empty()) continue;
                pii tp2=st.top();st.pop();
                if (tp1.first!=tp2.second)  {
                    flag=1;
                    break;
                }
                if (cn2>cn1)    break;
                sum+=tp1.second*tp1.first*tp2.first;
                st.push(make_pair(tp2.first,tp1.second));
            }
            else    st.push(mcp[s[i]]);
        }
        if (flag)   cout<<"error"<<endl;
        else    cout<<sum<<endl;
        while (!st.empty()) st.pop();
        sum=0;
    }
    return 0;
}
