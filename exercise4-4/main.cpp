#include <bits/stdc++.h>
using namespace std;

string tot1(string ts);
string tot2(string ts);
string tot3(string ts);

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("output.txt","wa",stdout);
    string s;
    while (cin>>s)  {
        string s1=s.substr(0,6);
        string s2=s.substr(6);
        for (int i=0;i<6;i++)   {   //选定其中一个面为顶
            if (s1[i]!=s2[0])   continue;
            string ts,ts1=s1;
            char cc=ts1[5-i];
            ts[0]=ts1[i];
            ts1.erase(5-i);
            ts+=ts1;
            ts+=cc;
            if (s2==ts||s2==tot1(ts)||s2==tot2(ts)||s2==tot3(ts))
                cout<<"TRUE"<<endl;
            else    cout<<"FALSE"<<endl;
            break;
        }
    }
    return 0;
}

string tot1(string ts)  {swap(ts[1],ts[2]),swap(ts[2],ts[4]),swap(ts[3],ts[4]);return ts;}
string tot2(string ts)  {swap(ts[1],ts[4]),swap(ts[2],ts[3]);return ts;}
string tot3(string ts)  {swap(ts[1],ts[3]),swap(ts[2],ts[3]),swap(ts[3],ts[4]);return ts;}
