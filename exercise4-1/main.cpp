#include <bits/stdc++.h>
using namespace std;
const int N=15;
char cb[N][N];
bool ok,fobd[N][N];
int main()  {
    int n,xb,yb,tx,ty;
    char pe;
    cin>>n>>xb>>yb;
    for (int i=0;i<n;i++)   {
        cin>>pe>>tx>>ty;
        cb[tx][ty]=pe;
    }
    for (int i=1;i<=10;i++) {
        if (ok) break;
        for (int j=1;j<=9;j++) {
            if (ok) break;
            switch(cb[i][j])    {
                case 'G': opg(i,j);break;
                case 'H': oph(i,j);break;
                case 'C': opc(i,j);break;
                case 'R': opr(i,j);break;
            }
        }
    }
    if (ok) cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
    return 0;
}

void opg(int i,int j)   {
    for (int q=1;q<=9;q++) fobd[i][q]=1;
    for (int q=1;q<=10;q++) fobd[q][j]=1;
}

void oph(int i,int j)   {
    int s=i-1,x=i+1,z=j-1;y=j+1;
    if (s>=1)   {
        if (!cb[s][j]&&s-1>=1)  {
            if (j-1>=1) fobd[s-1][j-1]=1;
            if (j+1<=9)    fobd[s-1][j+1]=1;
        }
    }
    if (x<=10)  {
        if (!cb[x][j]&&x+1<=10) {
            if (j-1>=1) fobd[x+1][j-1]=1;
            if (j+1<=9)    fobd[x+1][j+1]=1;
        }
    }
    if (z>=1)   {
        if (!cb[i][z]&&z-1>=1)  {
            if (i-1>=1) fobd[i-1][z-1]=1;
            if (i+1<=10)    fobd[i+1][z-1]=1;
        }
    }
    if (y<=9)   {
        if (!cb[i][y]&&y+1<=9)  {
            if (i-1>=1) fobd[i-1][y+1]=1;
            if (i+1<=10)    fobd[i+1][y+1]=1;
        }
    }
}

void opc(int i,int j)   {
    for (int q=j-1;q>0;q--)    {
        if (cb[i][q])   {
            int p=q-1;
            while (p>0&&!cb[i][p])  p--;
            for (int b=p+1;b<=q-1;b++)
                fobd[i][b]=1;
        }
    }
    for (int q=j+1;q<=9;q++)    {
        if (cb[i][q])   {
            int p=q+1;
            while (p<=9&&!cb[i][p])  p++;
            for (int b=q+1;b<=p-1;b++)
                fobd[i][b]=1;
        }
    }
    for (int p=i-1;p>0;p--) {
        if (cb[p][j])   {
            int r=p-1;
            while (r>0&&!cb[r][j])  r--;
            for (int b=r+1;b<=p-1;b++)
                fobd[b][j]=1;
        }
    }
    for (int p=i+1;p<=10;p++) {
        if (cb[p][j])   {
            int r=p+1;
            while (r<=10&&!cb[r][j])  r++;
            for (int b=p+1;b<=r-1;b++)
                fobd[b][j]=1;
        }
    }
}

void opg(int i,int j)   {
    for (int q=1;q<=i;q++)  {
        if (cb[q][j])   {
            for (int p=1;p<q;p++)
                fobd[p][j]=1;
            break;
        }
    }
}


