#include <bits/stdc++.h>
using namespace std;
int ans[11];
int main()  {
    int n,num,t;
    cin>>n;
    while (n--) {
        cin>>num;
        for (int i=1;i<=num;i++) {
            t=i;
            while (t)   {
                ans[t%10]++;
                t/=10;
            }
        }
        cout<<ans[0];
        for (int i=1;i<10;i++)  cout<<' '<<ans[i];
        cout<<endl;
        fill(ans,ans+10,0);
    }
    return 0;
}
