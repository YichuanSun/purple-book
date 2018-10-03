#include <bits/stdc++.h>
#define N 35
using namespace std;
int g[N][N],spot[N],stv[N];
vector<int> va;
void read_str(string s);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin>>s&&s!="#")  {
        fill(g[0],g[0]+N*N,0);
        fill(spot,spot+N,0);
        fill(stv,stv+N,0);
        read_str(s);
        int ct=0,ans=10000000;
        for (int i=0;i<N;i++)
            if (spot[i])    stv[ct++]=i;
        do  {
            int almx=0;
            for (int i=0;i<ct;i++)  {
                int mx=-1;
                for (int j=0;j<ct;j++)  {
                    if (stv[i]==stv[j]) continue;
                    if (!g[stv[i]][stv[j]]) continue;
                    mx=max(mx,abs(i-j));
                }
                almx=max(almx,mx);
            }
            if (almx<ans) {
                va.clear();
                ans=almx;
                for (int i=0;i<ct;i++)
                    va.push_back(stv[i]);
            }
        }while (next_permutation(stv,stv+ct));
        if (!va.empty())    cout<<(char)(stv[0]+'A');
        for (int i=1;i<(int)va.size();i++)
            cout<<' '<<(char)(va[i]+'A');
        cout<<" -> "<<ans<<endl;
    }
    return 0;
}

void read_str(string s) {
    int st=0;
    while (st<(int)s.size())    {
        int ver=s[st]-'A';
        spot[ver]=1;
        st+=2;
        while (s[st]!=';'&&st<(int)s.size())  {
            int ajc=s[st]-'A';
            spot[ajc]=1;
            g[ver][ajc]=1;
            g[ajc][ver]=1;
            st++;
        }
        st++;
    }
}
