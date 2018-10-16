//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 1005
using namespace std;

vector<pair<int,int> > pii;             //存储每个点的x，y坐标，点集
struct edge{int v1,v2;double cost;};    //定义边的数据结构
vector<edge> ve;                        //边集
int parent[N],n,m;                      //parent是并查集的存储数组，某个点i的父节点为parent[i]

double len(int a,int b);        //计算两点间距
bool cmp(edge a,edge b) {return a.cost<b.cost;}     //对边排序的比较函数
void UFset();                   //并查集的初始化，用数组存并查集，将每个点的父节点都设为-1.根节点的父节点值是个负数，绝对值表示当前集合的元素个数
void Union(int a,int b);        //将两个点加入同一个集合
int Find(int a);                //寻找某个点所在的集合（以这一集合的根节点表示），上三个并查集函数是并查集的核心
bool same(int a,int b);         //判断两点是否在同一个集合内

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
            te.v1=i,te.v2=j;    //无向图，又忘了，边得输入两次，但是在这题不是邻接矩阵，而相当于邻接表，所以只输入一条联通边即可。
            if (i==j)   te.cost=0;
            else    te.cost=len(i,j);
            //cout<<te.cost<<endl;
            ve.push_back(te);
        }
    }
    cin>>m;
    for (int i=0;i<m;i++)   {
        int t1,t2;
        cin>>t1>>t2;
        Union(t1-1,t2-1);       //将已经相连的点连接，因为我是从0开始的，但是输入从1开始，所以此处-1
    }
//    for (int i=0;i<n;i++)
//        cout<<parent[i]<<' ';
//    cout<<endl;
    sort(ve.begin(),ve.end(),cmp);      //对边排序，kruskal算法的要求
    //cout<<"TABLE\n";
//    for (int i=0;i<(int)ve.size();i++)
//        cout<<ve[i].v1<<' '<<ve[i].v2<<' '<<ve[i].cost<<endl;
    //cout<<"ve:\t"<<ve.size()<<endl;
    for (int i=0;i<(int)ve.size();i++)  {
        if (!same(ve[i].v1,ve[i].v2))   {       //如果没在同一个并查集中，说明这两点未相连，就连接他们两个
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
