#include <bits/stdc++.h>
#define N 20
using namespace std;
bool used[N];
int isp[N*N]={0,0,1},n;   //0为未处理，1为素数，2为合数
vector<int> ans;
void sech(int now,int rmn);
void preope(){
    for (int i=1;i<N;i++)   {
        for (int j=1;j<N;j++)   {
            if (isp[i+j]==0)    {
                int sum=i+j;
                for (int t=2;t*t<=sum;t++)
                    if (sum%t==0)   isp[sum]=2;
                if (isp[sum]==0)    isp[sum]=1;
            }
        }
    }
}

int main()  {
    int cnt=0;
    preope();
    while (scanf("%d",&n)!=EOF){
        if (cnt++)  printf("\n");
        printf("Case %d:\n",cnt);
        ans.push_back(1);
        used[1]=true;
        sech(1,n-1);
        fill(used,used+n,false);
        ans.clear();
    }
    return 0;
}

void sech(int now,int rmn)  {
    if (rmn==0) {
        if (isp[ans.back()+ans[0]]==1)  {
            printf("%d",ans[0]);
            for (int i=1;i<(int)ans.size();i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
        return;
    }
    for (int i=2;i<=n;i++)  {
        if (!used[i]&&isp[i+now]==1) {
            ans.push_back(i);
            used[i]=true;
            sech(i,rmn-1);
            ans.pop_back();
            used[i]=false;
        }
    }
}
