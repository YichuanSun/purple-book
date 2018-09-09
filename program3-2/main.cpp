//刘汝佳的版本
#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int a[maxn];
int main()  {
    int n,k,first=1;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++)
            if (j%i==0) a[j]=!a[j];
    for (int i=1;i<=n;i++)
        if (a[i])   {
            if (first)  first=0;
            else    printf(" ");
            printf("%d",i);
        }
    return 0;
}



//我的版本
//#include <bits/stdc++.h>
//#define N 1005
//using namespace std;
//bool a[N];
//int main()  {
//    int n,k;
//    cin>>n>>k;
//    for (int i=1;i<=n;i++)  {
//        for (int j=1;j<=k;j++)  {
//            if (i%j==0) a[i]=!a[i];
//        }
//    }
//    int i=1;
//    for (;i<=n;i++)  {
//        if (a[i])   {
//            cout<<i;
//            break;
//        }
//    }
//    for (int j=i+1;j<=n;j++)    {
//        if (a[j])   cout<<' '<<j;
//    }
//    cout<<endl;
//    return 0;
//}
