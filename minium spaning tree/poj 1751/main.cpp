//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 1005
using namespace std;

vector<pair<int,int> > pii;
struct edge{int v1,v2;double cost;};
vector<edge> ve;
int parent[N],n,m;

double len(int a,int b);
bool cmp(edge a,edge b) {return a.cost<b.cost;}
bool cmpp(pair<int,int> a,pair<int,int> b)  {return a.first<b.first;}
void UFset();
void Union(int a,int b);
int Find(int a);
bool same(int a,int b);

int main()  {
    pair<int,int> tpii;
    edge te;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>tpii.first>>tpii.second;
        pii.push_back(tpii);
        //cout<<"OK"<<endl;
    }
    UFset();    //因为之前n还未被初始化，一直为0，而该函数初始化数组需要n，所以这句话在n被定义之前无效
    //cout<<"pii:\t"<<pii.size()<<endl;
    for (int i=0;i<(int)pii.size();i++) {
        for (int j=i;j<(int)pii.size();j++)   {
            te.v1=i,te.v2=j;    //无向图，又忘了，边得输入两次
            if (i==j)   te.cost=0;
            else    te.cost=len(i,j);
            //cout<<te.cost<<endl;
            ve.push_back(te);
            //swap(te.v1,te.v2);
            //ve.push_back(te);
        }
    }
    cin>>m;
    for (int i=0;i<m;i++)   {
        int t1,t2;
        cin>>t1>>t2;
        Union(t1-1,t2-1);
    }
//    for (int i=0;i<n;i++)
//        cout<<parent[i]<<' ';
//    cout<<endl;
    sort(ve.begin(),ve.end(),cmp);
    //cout<<"TABLE\n";
//    for (int i=0;i<(int)ve.size();i++)
//        cout<<ve[i].v1<<' '<<ve[i].v2<<' '<<ve[i].cost<<endl;
    //cout<<"ve:\t"<<ve.size()<<endl;
    for (int i=0;i<(int)ve.size();i++)  {
        if (!same(ve[i].v1,ve[i].v2))   {
            Union(ve[i].v1,ve[i].v2);
            cout<<ve[i].v1+1<<' '<<ve[i].v2+1<<endl;
        }
    }
    return 0;
}

double len(int a,int b) {
    double dx=pii[a].first-pii[b].first;
    double dy=pii[a].second-pii[b].second;
    //cout<<"dxdy:\t"<<dx<<' '<<dy<<endl;
    //cout<<ans<<endl;
    return sqrt(1.0*dx*dx+1.0*dy*dy);
}

void UFset()    {fill(parent,parent+n,-1);}

void Union(int a,int b) {
    int r1=Find(a),r2=Find(b);
    if (r1==r2) return;
    //cout<<"Find is OK"<<endl;
    int R=parent[r1]+parent[r2];
    if (parent[r1]<parent[r2])  {
        parent[r2]=r1;
        parent[r1]=R;
    }
    else    {
        parent[r1]=r2;
        parent[r2]=R;
    }
}

int Find(int a)    {
    int res=a;
    for (;parent[res]>=0;res=parent[res]);
    //cout<<"now res=\t"<<res<<endl;
    while (res!=a)  {
        int tp=parent[a];
        parent[a]=res;
        a=tp;
        //cout<<"a=\t"<<a<<endl;
    }
    return res;
}

bool same(int a,int b)  {
    if (Find(a)==Find(b))   return true;
    return false;
}
