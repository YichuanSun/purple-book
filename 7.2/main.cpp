#include <bits/stdc++.h>
#define N 1005
using namespace std;
int a[N],s[N];
void pp(int n,int a[],int cur); //输出对1~n的全排列
void psp(int n,int s[],int a[],int cur);    //输出对集合s所有元素的全排列，s不能包含重复元素
void psp_version2(int n,int s[],int a[],int cur);   //输出对集合s所有元素的全排列，s可以有重复元素，但是输出结果会有重复
void psp_version3(int n,int s[],int a[],int cur);   //最终版本，s的全排列，s可以有重复元素，输出结果无重复
int main()  {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   cin>>s[i];
    //psp(n,s,a,0);
    do  {
        cout<<s[0];
        for (int i=1;i<n;i++)   cout<<' '<<s[i];
        cout<<endl;
    }while (next_permutation(s,s+n));
    return 0;
}

void pp(int n,int a[],int cur)  {
    if (n==cur) {
        cout<<a[0];
        for (int i=1;i<n;i++)   cout<<' '<<a[i];
        cout<<endl;
    }
    else    for (int i=1;i<=n;i++)   {
        int ok=1;
        for (int j=0;j<cur;j++) if (a[j]==i)   ok=0;
        if (ok) {
            a[cur]=i;
            pp(n,a,cur+1);
        }
    }
}

void psp(int n,int s[],int a[],int cur)  {
    if (n==cur) {
        cout<<a[0];
        for (int i=1;i<n;i++)   cout<<' '<<a[i];
        cout<<endl;
    }
    else    for (int i=0;i<n;i++)   {
        int ok=1;
        for (int j=0;j<cur;j++) if (a[j]==s[i])   ok=0;
        if (ok) {
            a[cur]=s[i];
            psp(n,s,a,cur+1);
        }
    }
}

void psp_version2(int n,int s[],int a[],int cur)    {
    if (n==cur) {
        cout<<a[0];
        for (int i=1;i<n;i++)   cout<<' '<<a[i];
        cout<<endl;
    }
    else  for (int i=0;i<n;i++)   {
            int c1=0,c2=0;
            for (int j=0;j<n;j++)   if (s[j]==s[i]) c1++;
            for (int j=0;j<cur;j++) if (a[j]==s[i]) c2++;
            if (c2<c1)  {
                a[cur]=s[i];
                psp_version2(n,s,a,cur+1);
            }
    }
}

void psp_version3(int n,int s[],int a[],int cur)    {
    if (cur==n) {
        cout<<a[0];
        for (int i=1;i<n;i++)   cout<<' '<<a[i];
        cout<<endl;
    }
    else for (int i=0;i<n;i++)
            if (!i||s[i-1]!=s[i])
            {
                int c1=0,c2=0;
                for (int j=0;j<n;j++)   if (s[j]==s[i]) c1++;
                for (int j=0;j<cur;j++) if (a[j]==s[i]) c2++;
                if (c1>c2)  {
                    a[cur]=s[i];
                    psp_version3(n,s,a,cur+1);
                }
            }
}







