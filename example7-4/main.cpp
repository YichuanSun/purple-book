#include <bits/stdc++.h>
#define N 20
using namespace std;
//bool used[N];
int isp[N*N]= {0,0,1},n;  //0Ϊδ����1Ϊ������2Ϊ����
//vector<int> ans;
//void sech(int now,int rmn);
void preope()
{
    for (int i=1; i<N; i++)
    {
        for (int j=1; j<N; j++)
        {
            if (isp[i+j]==0)
            {
                int sum=i+j;
                for (int t=2; t*t<=sum; t++)
                    if (sum%t==0)
                        isp[sum]=2;
                if (isp[sum]==0)
                    isp[sum]=1;
            }
        }
    }
}
//���������Լ�д���㷨
//int main()  {
//    int cnt=0;
//    preope();
//    while (scanf("%d",&n)!=EOF){
//        if (cnt++)  printf("\n");
//        printf("Case %d:\n",cnt);
//        ans.push_back(1);
//        used[1]=true;
//        sech(1,n-1);
//        fill(used,used+n,false);
//        ans.clear();
//    }
//    return 0;
//}
//
//void sech(int now,int rmn)  {
//    if (rmn==0) {
//        if (isp[ans.back()+ans[0]]==1)  {
//            printf("%d",ans[0]);
//            for (int i=1;i<(int)ans.size();i++)
//                printf(" %d",ans[i]);
//            printf("\n");
//        }
//        return;
//    }
//    for (int i=2;i<=n;i++)  {
//        if (!used[i]&&isp[i+now]==1) {
//            ans.push_back(i);
//            used[i]=true;
//            sech(i,rmn-1);
//            ans.pop_back();
//            used[i]=false;
//        }
//    }
//}

//������ֱ������ȫ��������ö���жϵ��㷨
//int A[N];
//int main()  {
//    preope();
//    int n;
//    while (scanf("%d",&n)!=EOF) {
//        for (int i=0;i<n;i++)   A[i]=i+1;
//        do {
//            int e=1;
//            for (int i=1;i<n;i++)
//                if (isp[A[i]+A[i-1]]!=1)    {e=0;break;}
//            if (isp[A[0]+A[n-1]]!=1)    e=0;
//            if (e)  {
//                for (int i=0;i<n;i++)
//                    printf("%d ",A[i]);
//                printf("\n");
//            }
//        }while (next_permutation(A+1,A+n));
//    }
//    return 0;
//}

//��������Ѵ��е�dfs�㷨
int A[N],vis[N];
void dfs(int cur)
{
    if(cur == n && isp[A[0]+A[n-1]]==1)
    {
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
                printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    }
    else
        for(int i = 2; i <= n; i++)
            if(!vis[i] && isp[i+A[cur-1]]==1)
            {
                A[cur] = i;
                vis[i] = 1;
                dfs(cur+1);
                vis[i] = 0;
            }
}

int main()
{
    preope();
    while (scanf("%d",&n)!=EOF)
    {
        fill(vis,vis+n,false);
        A[0]=1;
        dfs(1);
    }
    return 0;
}





