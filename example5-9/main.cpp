#include <bits/stdc++.h>
using namespace std;

const int maxr=10005;
const int maxc=15;
typedef pair<int,int> PII;
int m,n,db[maxr][maxc],cnt;
map<string,int> id;

int ID(string s)    {
    if (!id.count(s))   id[s]=++cnt;
    return id[s];
}

void fd() {
    for (int c1=0;c1<m;c1++)    {
        for (int c2=c1+1;c2<m;c2++)    {
            map<PII,int> d;
            for (int i=0;i<n;i++)   {
                PII tp=make_pair(db[i][c1],db[i][c2]);
                if (d.count(tp))    {
                    cout<<"NO"<<endl;
                    cout<<d[tp]+1<<' '<<i+1<<endl;
                    cout<<c1+1<<' '<<c2+1<<endl;
                    return;
                }
                d[tp]=i;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(getline(cin, s)) {    //最后的bug出在这里，我用加char c的方法消不去，只能用getline，不知为何
        stringstream ss(s);
        if(!(ss >> n >> m)) break;
        cnt=0;
        id.clear();
        for (int i=0;i<n;i++)   {
            getline(cin,s);
            int lastpos=-1;
            for (int j=0;j<m;j++)   {
                int p=s.find(',',lastpos+1);
                if (p==(int)string::npos)   p=s.size();
                db[i][j]=ID(s.substr(lastpos+1,p-lastpos-1));
                lastpos=p;
            }
        }
        fd();
    }
    return 0;
}
