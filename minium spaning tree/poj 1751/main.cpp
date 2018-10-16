#include <bits/stdc++.h>
#define N 1005
using namespace std;

vector<pair<int,int> > pii;
struct edge{int v1,v2;double cost;};
vector<edge> ve;
vector<pair<int,int> > ans;
int parent[N],n,m;

double len(int a,int b);
bool cmp(edge a,edge b) {return a.cost<b.cost;}
bool cmpp(pair<int,int> a,pair<int,int> b)  {return a.first<b.first;}
void UFset();
void Union(int a,int b);
int Find(int a);
bool same(int a,int b);

int main()  {
    UFset();
    cout<<parent[0]<<' '<<parent[1]<<endl;
    pair<int,int> tpii;
    edge te;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>tpii.first>>tpii.second;
        pii.push_back(tpii);
        //cout<<"OK"<<endl;
    }
    cout<<"size:\t"<<(int)pii.size()<<endl;
    for (int i=0;i<(int)pii.size();i++) {
        for (int j=i;j<(int)pii.size();j++)   {
            te.v1=i,te.v2=j;
            if (i==j)   te.cost=0;
            else    te.cost=len(i,j);
            ve.push_back(te);
        }
    }
    cin>>m;
    for (int i=0;i<m;i++)   {
        int t1,t2;
        cin>>t1>>t2;
        Union(t1-1,t2-1);
        //cout<<"OK"<<endl;
    }
    sort(ve.begin(),ve.end(),cmp);
    for (int i=0;i<(int)ve.size();i++)  {
        if (!same(ve[i].v1,ve[i].v2))   {
            Union(ve[i].v1,ve[i].v2);
            ans.push_back(make_pair(ve[i].v1,ve[i].v2));
        }
    }
    sort(ans.begin(),ans.end(),cmpp);
    for (int i=0;i<(int)ans.size();i++)
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;
    return 0;
}

double len(int a,int b) {
    int dx=pii[a].first-pii[b].first;
    int dy=pii[a].second-pii[a].second;
    return sqrt(1.0*dx*dx+1.0*dy*dy);
}

void UFset()    {
    //fill(parent,parent+n,-1);
    for (int i=0;i<n;i++)   parent[i]=-1;
}

void Union(int a,int b) {
    int r1=Find(a),r2=Find(b);  //find»µÁË
    cout<<"Find is OK"<<endl;
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
    cout<<"res=\t"<<res<<endl;
    for (;parent[res]>=0;res=parent[res])
        cout<<"every res=\t"<<res<<endl;
    cout<<"now res=\t"<<res<<endl;
    while (res!=a)  {
        int tp=parent[a];
        parent[a]=res;
        a=tp;
        cout<<"a=\t"<<a<<endl;
    }
    return res;
}

bool same(int a,int b)  {
    if (Find(a)==Find(b))   return true;
    return false;
}
