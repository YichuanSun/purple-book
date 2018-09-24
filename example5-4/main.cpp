#include <bits/stdc++.h>
using namespace std;
vector<string> words,ans;
map<string,int> mp;

string exc(string ts)   {
    string a=ts;
    for (int i=0;i<(int)a.size();i++)
        if (a[i]>='A'&&a[i]<='Z')
            a[i]=a[i]-'A'+'a';
    sort(a.begin(),a.end());
    return a;
}
int main()  {
    string s;
    while (cin>>s)  {
        if (s=="#") break;
        words.push_back(s);
        string tt=exc(s);
        if (!mp.count(tt))    mp[tt]=0;
        mp[tt]++;
    }
    for (int i=0;i<(int)words.size();i++)
        if (mp[exc(words[i])]==1)   ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for (int i=0;i<(int)ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
