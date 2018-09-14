#include <bits/stdc++.h>
using namespace std;
typedef map<char,int> mp;
typedef pair<char,int> pp;
vector<mp> v;
vector<string> st;
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
            st.push_back(s);
            for (int j=0;j<n;j++)   {
                v[j][s[j]]++;
            }
        }
//        for (int i=0;i<n;i++)   {
//            mp::iterator it2=v[i].begin();
//            cout<<i<<endl;
//            for (;it2!=v[i].end();it2++)
//                cout<<(*it2).first<<' '<<(*it2).second<<' ';
//            cout<<endl;
//        }
        string ans="";
        //变量定义域没搞明白弄出的bug，两个这种bug
        int mx=-1;
        for (int i=0;i<n;i++)   {
            char c;
            mp::iterator it1=v[i].begin();
            for (;it1!=v[i].end();it1++)    {
                if ((*it1).second>mx)    {
                    mx=(*it1).second;
                    c=(*it1).first;
                }
                else if ((*it1).second==mx)
                    c=min(c,(*it1).first);
            }
            ans+=c;
            mx=-1;
        }
        int res=0;
        for (int i=0;i<(int)st.size();i++) {
            for (int j=0;j<(int)st[i].size();j++)
                if (st[i][j]!=ans[j])   res++;
        }
        cout<<ans<<'\n'<<res<<endl;
        v.clear();
        st.clear();
    }
    return 0;
}
