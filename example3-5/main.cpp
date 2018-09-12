#include <bits/stdc++.h>
#define N 100005
using namespace std;
int ans[100005];
int main()  {
    int n,p;
    scanf("%d",&n);
    for (int i=1;i<=100000;i++) {
        int sum=i,t=i;
        while (t!=0)    {
            sum+=t%10;
            t/=10;
        }
        if (ans[sum]==0||ans[sum]>i)
            ans[sum]=i;
    }
    while (n--) {
        scanf("%d",&p);
        printf("%d\n",ans[p]);
    }
    return 0;
}
