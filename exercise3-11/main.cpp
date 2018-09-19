#include <bits/stdc++.h>
#define INF 100100100
using namespace std;
vector<int> v;
int main()  {
    freopen("output.txt","wa",stdout);
    string s,t;
    while (cin>>s&&!s.empty())  {
        cin>>t;
        for (int i=(int)s.size()-1;i>=0;i--)   {
            int j;
            for (j=0;j<(int)t.size();j++)   {
                if (i+j>=s.size())  continue;
                if (s[i+j]=='2'&&t[j]=='2') break;
            }
            if (j==t.size())    v.push_back(i+(int)t.size());
        }
        for (int i=(int)t.size()-1;i>=0;i--)    {
            int j;
            for (j=0;j<(int)s.size()-1;j++) {
                if (i+j>=t.size())  continue;
                if (s[j]=='2'&&t[i+j]=='2') break;
            }
            if (j==s.size())    v.push_back(i+(int)s.size());
        }
        reverse(t.begin(),t.end());
        for (int i=(int)s.size()-1;i>=0;i--)   {
            int j;
            for (j=0;j<(int)t.size();j++)   {
                if (i+j>=s.size())  continue;
                if (s[i+j]=='2'&&t[j]=='2') break;
            }
            if (j==t.size())    v.push_back(i+(int)t.size());
        }
        for (int i=(int)t.size()-1;i>=0;i--)    {
            int j;
            for (j=0;j<(int)s.size()-1;j++) {
                if (i+j>=t.size())  continue;
                if (s[j]=='2'&&t[i+j]=='2') break;
            }
            if (j==s.size())    v.push_back(i+(int)s.size());
        }
        int ans=INF;
        for (int i=0;i<(int)v.size();i++)
            if (v[i]<ans)   ans=v[i];
        if (ans==INF)   cout<<s.size()+t.size()<<endl;
        else if (ans>max(s.size(),t.size()))    cout<<ans<<endl;
        else    cout<<max(s.size(),t.size())<<endl;
        v.clear();
    }
    return 0;
}
