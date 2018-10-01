#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > pii;
int main()  {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=n+1;i<=n*2;i++)  {
            int x=(n*i)/(i-n);
            if ((n*i)%(i-n)==0)
                pii.push_back(make_pair(x,i));
        }
        printf("%d\n",(int)pii.size());
        for (int i=0;i<(int)pii.size();i++)
            printf("1/%d = 1/%d + 1/%d\n",n,pii[i].first,pii[i].second);
        pii.clear();
    }
    return 0;
}
