#include <bits/stdc++.h>
using namespace std;
const int N=15;
char cb[N][N];
bool ok,fobd[N][N];
void oph(int i,int j);
void opc(int i,int j);
void opg(int i,int j);
void opr(int i,int j);
void check(int i,int j);
bool fg();
int n=1,xb=1,yb=1,tx,ty,xr,yr;
int main()  {
    char pe;
    while (n&&xb&&yb)   {
        cin>>n>>xb>>yb;
        if (!n||!xb||!yb)   break;
        for (int i=0;i<n;i++)   {
            cin>>pe>>tx>>ty;
            cb[tx][ty]=pe;
            if (pe=='G')    xr=tx,yr=ty;
        }
//        cout<<"xb="<<xb<<'\t'<<"yb="<<yb<<endl;
//        cout<<"xr="<<xr<<'\t'<<"yr="<<yr<<endl;
        if (fg())   {
            cout<<"No"<<endl;
            continue;
        }
//        for (int i=1;i<=10;i++) {
//            for (int j=1;j<=9;j++)
//                cout<<' '<<cb[i][j];
//            cout<<endl;
//        }
        for (int i=1;i<=10;i++) {
            for (int j=1;j<=9;j++) {
                switch(cb[i][j])    {
                    case 'G': opg(i,j);break;
                    case 'H': oph(i,j);break;
                    case 'C': opc(i,j);break;
                    case 'R': opr(i,j);break;
                }
//                if (cb[i][j])  {
//                    cout<<"time"<<endl;
//                    for (int i=1;i<=10;i++) {
//                        for (int j=1;j<=9;j++)
//                            cout<<' '<<fobd[i][j];
//                        cout<<endl;
//                    }
//                }
            }
        }
        check(xb,yb);
        if (ok) cout<<"NO"<<endl;
        else    cout<<"YES"<<endl;
        fill(cb[0],cb[0]+N*N,'\0');
        fill(fobd[0],fobd[0]+N*N,false);
        ok=false;
    }
    return 0;
}

void oph(int i,int j)   {
    int s=i-1,x=i+1,z=j-1,y=j+1;
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
            while (p>0&&(!cb[i][p]||(xb==i&&yb==p)))  p--;
            for (int b=p+1;b<=q-1;b++)
                fobd[i][b]=1;
            break;
        }
    }
    for (int q=j+1;q<=9;q++)    {
        if (cb[i][q])   {
            int p=q+1;
            while (p<=9&&(!cb[i][p]||(xb==i&&yb==p)))  p++;
            for (int b=q+1;b<=p-1;b++)
                fobd[i][b]=1;
            break;
        }
    }
    for (int p=i-1;p>0;p--) {
        if (cb[p][j])   {
            int r=p-1;
            while (r>0&&(!cb[r][j]||(xb==r&&yb==j)))  r--;
            for (int b=r+1;b<=p-1;b++)
                fobd[b][j]=1;
            break;
        }
    }
    for (int p=i+1;p<=10;p++) {
        if (cb[p][j])   {
            int r=p+1;
            while (r<=10&&(!cb[r][j]||(xb==r&&yb==j)))  r++;
            for (int b=p+1;b<=r-1;b++)
                fobd[b][j]=1;
            break;
        }
    }
}

void opg(int i,int j)   {
    int q=i-1;
    while (q>0) {
        if (cb[q][j])  break;
        q--;
    }
    if (q==0)   q++;
    for (int it=q;it<i;it++)    fobd[it][j]=1;
}

void opr(int i,int j)   {
    int a,b;
    for (a=i-1;a>=1&&(!cb[a][j]||(a==xb&&j==yb));a--) fobd[a][j]=1;
    if (cb[a][j]&&(a!=xb||j!=yb))   fobd[a][j]=1;
    for (a=i+1;a<=10&&(!cb[a][j]||(a==xb&&j==yb));a++) fobd[a][j]=1;
    if (cb[a][j]&&(a!=xb||j!=yb))   fobd[a][j]=1;
    for (b=j-1;b>=1&&(!cb[i][b]||(i==xb&&b==yb));b--) fobd[i][b]=1;
    if (cb[i][b]&&(i!=xb||b!=yb))   fobd[i][b]=1;
    for (b=j+1;b<=9&&(!cb[i][b]||(i==xb&&b==yb));b++) fobd[i][b]=1;
    if (cb[i][b]&&(i!=xb||b!=yb))   fobd[i][b]=1;
}

void check(int i,int j) {
    if (i+1<=3&&!fobd[i+1][j])  {ok=true;return;}
    if (i-1>=1&&!fobd[i-1][j])  {ok=true;return;}
    if (j+1<=6&&!fobd[i][j+1])  {ok=true;return;}
    if (j-1>=4&&!fobd[i][j-1])  {ok=true;return;}
}


bool fg()   {
    int i=0;
    if (yb!=yr) return false;
    for (i=xr-1;i>=xb;i--)
        if (cb[i][yb])  break;
    if (i<xb)   return true;
    else    return false;
}
