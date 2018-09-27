#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n,d,I,t;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>d>>I;
        int te=1;
        for (int i=1;i<d;i++)    {
            if (I&1)    te=2*te;
            else        te=2*te+1;
            I=(I+1)/2;
        }
        cout<<te<<endl;
    }
    cin>>n;
    return 0;
}

//下面这个是强行模拟的超时算法
//bool tree[1<<20+5];
//int dfs(int i);
//int n,d,l,a;
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cin>>n;
//    while (n--) {
//        cin>>d>>l;
//        fill(tree,tree+(1<<d),false);
//        for (int i=1;i<=l;i++)
//            a=dfs(1);
//        cout<<a<<endl;
//    }
//    cin>>n;
//    return 0;
//}
//
//int dfs(int i) {
//    if (i>=(1<<(d-1)))  return i;
//    if (tree[i]==false) {
//        tree[i]=!tree[i];
//        return dfs(2*i);
//    }
//    else    {
//        tree[i]=!tree[i];
//        return dfs(2*i+1);
//    }
//}
