#include <bits/stdc++.h>
#define N 1000
using namespace std;
int ch[13]={6,2,5,5,4,5,6,3,7,6};
int r[N];
int ex(int c);
void reprocess();
int main()  {
    int n;
    cin>>n;
    int nw=n-4,cnt=0;
    reprocess();
    if (nw<=0)  {cout<<0<<endl;return 0;}
    for (int i=0;i<=800;i++)   {
        if (r[i]>=nw)   continue;
        int left1=nw-r[i];
        for (int j=0;j<=800;j++)    {
            if (r[j]>=left1)    continue;
            int left2=left1-r[j];
            for (int k=0;k<=800;k++)    {
                if (r[k]>left2)    continue;
                if (r[k]==left2&&i+j==k)    {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

int ex(int c)   {
    if (r[c])   return r[c];
    if (c==0)   return ch[0];
    int sum=0;
    while (c)   {
        sum+=ch[c%10];
        c/=10;
    }
    return sum;
}

void reprocess()    {
    for (int i=0;i<N;i++)
        if (r[i]==0)    r[i]=ex(i);
}

