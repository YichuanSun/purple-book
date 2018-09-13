#include <bits/stdc++.h>
#define N 105
using namespace std;
typedef pair<int,string> node;
char st[N][N];
int num[N][N];
bool used[N][N];
vector<node> acr,dow;
bool cmp(node a,node b) {
    return a.first<b.first;
}
int main()  {
//    freopen("input.txt","ra",stdin);
//    freopen("output.txt","wa",stdout);
    int x,y,ct=0;
    bool first=false;
    while (scanf("%d",&x)&&x)   {
        getchar();
        int cnt=0;
        scanf("%d",&y);
        getchar();
        if (first&&y)   printf("\n");
        first=true;
        fill(num[0],num[0]+N*N,0);
        for (int i=0;i<x;i++)   {
            for (int j=0;j<y;j++)   {
                scanf("%c",&st[i][j]);
                if (st[i][j]=='*')  continue;
                if ((i-1<0||j-1<0))num[i][j]=++cnt;
                else if (st[i-1][j]=='*'||st[i][j-1]=='*')
                    num[i][j]=++cnt;
            }
            getchar();
        }
        fill(used[0],used[0]+N*N,false);
        for (int i=0;i<x;i++)   {
            int j=0;
            while (j<y) {
                if (used[i][j]||num[i][j]==0)   {j++;continue;}
                string a="";
                int be=j;
                while (j<y&&st[i][j]!='*')   {
                    a+=st[i][j];
                    used[i][j]=true;
                    j++;
                }
                acr.push_back(make_pair(num[i][be],a));
            }
        }
        fill(used[0],used[0]+N*N,false);
        for (int j=0;j<y;j++)   {
            int i=0;
            while (i<x) {
                if (used[i][j]||num[i][j]==0)   {i++;continue;}
                string a="";
                int be=i;
                while (i<x&&st[i][j]!='*')  {
                    a+=st[i][j];
                    used[i][j]=true;
                    i++;
                }
                dow.push_back(make_pair(num[be][j],a));
            }
        }
        sort(dow.begin(),dow.end(),cmp);
        printf("puzzle #%d:\n",++ct);
        printf("Across\n");
        for (int i=0;i<(int)acr.size();i++)
            printf("%3d.%s\n",acr[i].first,acr[i].second.c_str());
        printf("Down\n");
        for (int i=0;i<(int)dow.size();i++)
            printf("%3d.%s\n",dow[i].first,dow[i].second.c_str());
        dow.clear(),acr.clear();
    }
    return 0;
}
