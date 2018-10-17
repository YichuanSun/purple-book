//题目不难，但是我一直没看懂题意，写了个差不多的
//就是这个，但是提交用的网上的标程
#include <bits/stdc++.h>
#define INF 10000005
#define N 105
using namespace std;
int bny1[N];
void biToInt(int bi[],int& a,int& b,int& c,int& d);
void intToBi(int bi[],int a,int b,int c,int d);
int main()  {
    int n,a,b,c,d;
    int ma=INF,mb=INF,mc=INF,md=INF;
    int ra=0,rb=0,rc=0,rd=0;
    char ch;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        ma=min(a,ma),mb=min(b,mb),mc=min(c,mc),md=min(d,md);
    }
    intToBi(bny1,ma,mb,mc,md);
    for (int i=31;i>=0;i--)
        if (bny1[i]==1) {bny1[i]=0;break;}
    biToInt(bny1,ra,rb,rc,rd);
    cout<<ra<<'.'<<rb<<'.'<<rc<<'.'<<rd<<endl;
    ra=rb=rc=rd=0;
    int sp=31;
    for (;bny1[sp]==0;sp--);
    for (int i=0;i<=sp;i++) bny1[i]=1;
    biToInt(bny1,ra,rb,rc,rd);
    cout<<ra<<'.'<<rb<<'.'<<rc<<'.'<<rd<<endl;
    return 0;
}
//将二进制数组转化为对应的四个数
void biToInt(int bi[],int& a,int& b,int& c,int& d)    {
    int k=1;
    for (int i=7;i>=0;i--)  {a+=k*bi[i];k<<=1;}k=1;
    for (int i=15;i>=8;i--) {b+=k*bi[i];k<<=1;}k=1;
    for (int i=23;i>=16;i--)    {c+=k*bi[i];k<<=1;}k=1;
    for (int i=31;i>=24;i--)    {d+=k*bi[i];k<<=1;}
}
//将四个数转化为对应的二进制数组
void intToBi(int bi[],int a,int b,int c,int d)    {
    int cnt=0;
    if (a==0)   for (int i=0;i<8;i++)   {bi[cnt++]=0;}
    while (a)   {bi[cnt++]=a&1;a>>=1;}
    while (cnt%8)   bi[cnt++]=0;
    reverse(bi,bi+8);
    if (b==0)   for (int i=0;i<8;i++)   {bi[cnt++]=0;}
    while (b)   {bi[cnt++]=b&1;b>>=1;}
    while (cnt%8)   bi[cnt++]=0;
    reverse(bi+8,bi+16);
    if (c==0)   for (int i=0;i<8;i++)   {bi[cnt++]=0;}
    while (c)   {bi[cnt++]=c&1;c>>=1;}
    while (cnt%8)   bi[cnt++]=0;
    reverse(bi+16,bi+24);
    if (d==0)   for (int i=0;i<8;i++)   {bi[cnt++]=0;}
    while (d)   {bi[cnt++]=d&1;d>>=1;}
    while (cnt%8)   bi[cnt++]=0;
    reverse(bi+24,bi+32);
}



