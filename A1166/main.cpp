#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
bool isPrime(int d) {
    if (d==0||d==1) return false;
    for (int i=2;i*i<=d;i++)
        if (d%i==0) return false;
    return true;
}
int main()  {
    string s;
    cin>>s;
    for (int i=0;i<(int)s.size();i++)   {
        mp[s[i]]++;
    }
    int mx=-1,mn=100000;
    map<char,int>::iterator it1=mp.begin();
    for (;it1!=mp.end();it1++)  {
        if ((*it1).second>mx)   mx=(*it1).second;
        if ((*it1).second<mn)   mn=(*it1).second;
    }
    int dif=mx-mn;
    if (isPrime(dif))   cout<<"Lucky Word"<<'\n'<<dif<<endl;
    else    cout<<"No Answer"<<'\n'<<0<<endl;
    return 0;
}
