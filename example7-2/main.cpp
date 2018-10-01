#include <iostream>
#define N 25
using namespace std;
int main()  {
    int n,cnt=0,a[N];
    while (scanf("%d",&n)!=EOF&&n) {
        long long ans=0;
        for (int i=0;i<n;i++)   scanf("%d",&a[i]);
        for (int i=0;i<n;i++)   {
            long long t=1;
            for (int j=i;j<n;j++)   {
                t*=a[j];
                if (t>ans)  ans=t;
            }
        }
        cout << "Case #" << ++cnt << ": The maximum product is " << ans << ".\n\n";
    }
    return 0;
}
//下面的预处理版本，无法对付输入里面元素含0的情况
//int a[N],cnt,n;
//long long tms[N],ans;
//int main()  {
//    while (cin>>n)  {
//        if (cnt++)  printf("\n");
//        for (int i=0;i<n;i++)   cin>>a[i];
//        tms[0]=1;
//        for (int i=1;i<=n;i++)   tms[i]=tms[i-1]*a[i-1];
//        cout<<endl;
//        for (int i=0;i<=n;i++)   {
//            for (int j=i+1;j<=n;j++) {
//                long long t=tms[j]/tms[i];
//                if (t>ans)  ans=t;
//            }
//        }
//        cout<<"Case #"<<cnt<<": The maximum product is "<<ans<<".\n";
//    }
//    return 0;
//}
