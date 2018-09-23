//WA了，没找出bug来
#include <bits/stdc++.h>
#define N 10
using namespace std;
char cb[N][N];
void cbl(char nw,char nx);
void cbm();
void cbq();
bool check(int i,int j);
vector<pair<int,int> > pp;
char nw,nx;
string num;
int main()  {
    freopen("output.txt","wa",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--) {
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
               cin>>cb[i][j];
        char ch='v';
        cin>>nw;
        if (nw=='W')    nx='B';
        else if (nw=='B')   nx='W';
        cin>>ch;
        while (ch!='Q') {
            switch(ch)  {
                case 'L':   cbl(nw,nx);break;
                case 'M':   cbm();break;
            }
            cin>>ch;
        }
        if (ch=='Q')    cbq();
        if (n!=0)   cout<<endl;
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

void cbm()   {
    cin>>num;
    int i=num[0]-'0',j=num[1]-'0';
    if (!check(i,j))  swap(nx,nw);
    pp.clear();
    int it=i-1,jt;
    while (it>=1&&cb[it][j]==nx)    it--;
    if (it!=i-1&&it>=1&&cb[it][j]==nw)
        for (int k=it;k<=i;k++)   cb[k][j]=nw;
    it=i+1;
    while (it<=8&&cb[it][j]==nx)    it++;
    if (it!=i+1&&it<=8&&cb[it][j]==nw)
        for (int k=i;k<=it;k++)   cb[k][j]=nw;
    jt=j-1;
    while (jt>=1&&cb[i][jt]==nx)    jt--;
    if (jt!=j-1&&jt>=1&&cb[i][jt]==nw)
        for (int k=jt;k<=j;k++)   cb[i][k]=nw;
    jt=j+1;
    while (jt<=8&&cb[i][jt]==nx)    jt++;
    if (jt!=j+1&&jt<=8&&cb[i][jt]==nw)
        for (int k=j;k<=jt;k++)   cb[i][k]=nw;
    it=i-1,jt=j-1;
    while (it>=1&&jt>=1&&cb[it][jt]==nx)    it--,jt--;
    if (it!=i-1&&jt!=j-1&&it>=1&&jt>=1&&cb[it][jt]==nw)
        for (int ip=it,jp=jt;ip<=i&&jp<=j;ip++,jp++)    cb[ip][jp]=nw;
    it=i-1,jt=j+1;
    while (it>=1&&jt<=8&&cb[it][jt]==nx)    it--,jt++;
    if (it!=i-1&&jt!=j+1&&it>=1&&jt<=8&&cb[it][jt]==nw)
        for (int ip=it,jp=jt;ip<=i&&jp>=j;ip++,jp--)    cb[ip][jp]=nw;
    it=i+1,jt=j-1;
    while (it<=8&&jt>=1&&cb[it][jt]==nx)    it++,jt--;
    if (it!=i+1&&jt!=j-1&&it<=8&&jt>=1&&cb[it][jt]==nw)
        for (int ip=it,jp=jt;ip>=i&&jp<=j;ip--,jp++)    cb[ip][jp]=nw;
    it=i+1,jt=j+1;
    while (it<=8&&jt<=8&&cb[it][jt]==nx)    it++,jt++;
    if (it!=i+1&&jt!=j+1&&it<=8&&jt<=8&&cb[it][jt]==nw)
        for (int ip=it,jp=jt;ip>=i&&jp>=j;ip--,jp--)    cb[ip][jp]=nw;
    int black=0,white=0;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)  {
            if (cb[i][j]=='B')  black++;
            else if (cb[i][j]=='W') white++;
        }
    cout<<"Black - ";
    cout.width(2);
    cout<<black;
    cout<<" White - ";
    cout.width(2);
    cout<<white<<endl;
    swap(nx,nw);
}

void cbq()  {
    for (int i=1;i<=8;i++)  {
        for (int j=1;j<=8;j++)
            cout<<cb[i][j];
        cout<<endl;
    }
}

bool check(int i,int j)
{
    if (cb[i][j]!='-')  return 0;
    int it=i-1,jt;
    while (it>=1&&cb[it][j]==nx)    it--;
    if (it!=i-1&&it>=1&&cb[it][j]==nw){
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1;
    while (it<=8&&cb[it][j]==nx)    it++;
    if (it!=i+1&&it<=8&&cb[it][j]==nw){
        pp.push_back(make_pair(i,j));
        return 1;
    }
    jt=j-1;
    while (jt>=1&&cb[i][jt]==nx)    jt--;
    if (jt!=j-1&&jt>=1&&cb[i][jt]==nw){
        pp.push_back(make_pair(i,j));
        return 1;
    }
    jt=j+1;
    while (jt<=8&&cb[i][jt]==nx)    jt++;
    if (jt!=j+1&&jt<=8&&cb[i][jt]==nw)  {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i-1,jt=j-1;
    while (it>=1&&jt>=1&&cb[it][jt]==nx)    it--,jt--;
    if (it!=i-1&&jt!=j-1&&it>=1&&jt>=1&&cb[it][jt]==nw) {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i-1,jt=j+1;
    while (it>=1&&jt<=8&&cb[it][jt]==nx)    it--,jt++;
    if (it!=i-1&&jt!=j+1&&it>=1&&jt<=8&&cb[it][jt]==nw) {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1,jt=j-1;
    while (it<=8&&jt>=1&&cb[it][jt]==nx)    it++,jt--;
    if (it!=i+1&&jt!=j-1&&it<=8&&jt>=1&&cb[it][jt]==nw) {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    it=i+1,jt=j+1;
    while (it<=8&&jt<=8&&cb[it][jt]==nx)    it++,jt++;
    if (it!=i+1&&jt!=j+1&&it<=8&&jt<=8&&cb[it][jt]==nw) {
        pp.push_back(make_pair(i,j));
        return 1;
    }
    return 0;
}
