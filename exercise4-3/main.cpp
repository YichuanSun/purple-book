#include <bits/stdc++.h>
#define N 10
using namespace std;
char cb[N][N];
void cbl(char nw,char nx);
void cbm(char nw,char nx);
void cbq();
bool check(int i,int j);
vector<pair<int,int> > pp;
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--) {
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
               cin>>cb[i][j];
        char ch='v',nw,nx;
        cin>>nw;
        if (nw=='W')    nx='B';
        else if (nw=='B')   nx='W';
        cout<<nw<<' '<<nx<<endl;
        cin>>ch;
        while (ch!='Q') {
            switch(ch)  {
                case 'L':   cbl(nw,nx);break;
                case 'M':   cbm(nw,nx);break;
            }
            cin>>ch;
        }
        if (ch=='Q')    cbq();
    }
    return 0;
}

void cbl(char nw,char nx)   {
    for (int i=1;i<=8;i++)  {
        for (int j=1;j<=8;j++)  {
            check(i,j);
        }
    }
    if (pp.empty()) {cout<<"No legal move."<<endl;return;}
    cout<<'('<<pp[0].first<<','<<pp[0].second<<')';
    for (int i=1;i<(int)pp.size();i++)  cout<<" ("<<pp[i].first<<','<<pp[i].second<<')';
    cout<<endl;
    pp.clear();
}

void cbm(char& w,char& x)   {
    cin>>num;
    if (!check(w,x))  {
        cbm(x,w);
    }
    else {

        swap(w,x);
    }
}
void cbq()  {

}

bool check(int i,int j)
{
    if (cb[i][j]!='-')
        return 0;
    int it=i-1,jt;
    while (it>=1&&cb[it][j]==nx)
        it--;
    if (it!=i-1&&it>=1&&cb[it][j]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1;
    while (it<=8&&cb[it][j]==nx)
        it++;
    if (it!=i+1&&it<=8&&cb[it][j]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    jt=j-1;
    while (jt>=1&&cb[i][jt]==nx)
        jt--;
    if (jt!=j-1&&jt>=1&&cb[i][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    jt=j+1;
    while (jt<=8&&cb[i][jt]==nx)
        jt++;
    if (jt!=j+1&&jt<=8&&cb[i][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i-1,jt=j-1;
    while (it>=1&&jt>=1&&cb[it][jt]==nx)
        it--,jt--;
    if (it!=i-1&&jt!=j-1&&it>=1&&jt>=1&&cb[it][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i-1,jt=j+1;
    while (it>=1&&jt<=8&&cb[it][jt]==nx)
        it--,jt++;
    if (it!=i-1&&jt!=j+1&&it>=1&&jt<=8&&cb[it][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1,jt=j-1;
    while (it<=8&&jt>=1&&cb[it][jt]==nx)
        it++,jt--;
    if (it!=i+1&&jt!=j-1&&it<=8&&jt>=1&&cb[it][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1,jt=j+1;
    while (it<=8&&jt<=8&&cb[it][jt]==nx)
        it++,jt++;
    if (it!=i+1&&jt!=j+1&&it<=8&&jt<=8&&cb[it][jt]==nw)
    {
        pp.push_back(make_pair(i,j));
        return 1;
    }
}
