#include <bits/stdc++.h>
using namespace std;
typedef map<char,int> mp;
typedef pair<char,int> pp;
vector<mp> v;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,w;
    cin>>w;
    while (w--) {
        string s;
        cin>>m>>n;
        for (int i=0;i<n;i++)   {
            mp mm;
            mm['A']=0;
            mm['T']=0;
            mm['C']=0;
            mm['G']=0;
            v.push_back(mm);
        }
        for (int i=0;i<m;i++)   {
            cin>>s;
            for (int j=0;j<n;j++)   {
                v[j][s[j]]++;
            }
        }
        string ans="";
        for (int i=0;i<n;i++)   {
            char c;
            int mx=-1;
            mp::iterator it1=v[i].begin();
            for (;it1!=v[i].end();i++)    {
                if ((*it1).second>mx)    {
                    mx=(*it1).second;
                    c=(*it1).first;
                }
                else if ((*it1).second==mx)
                    c=min(c,(*it1).first);
            }
            ans+=c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
