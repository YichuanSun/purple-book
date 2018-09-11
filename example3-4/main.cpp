#include <bits/stdc++.h>
#define N 1005
using namespace std;
int scf[N],ori[N];
bool rit[N],pres[N];
int main()  {
    int n,times=1;
    while (scanf("%d",&n)&&n)   {
        fill(pres,pres+n,false);
        for (int i=0;i<n;i++)   {
            scanf("%d",ori+i);
            pres[ori[i]]=true;
        }
        printf("Game %d:\n",times++);
        while (true)    {
            int cnt=0;
            fill(rit,rit+20,false);
            int A=0,B=0;
            for (int i=0;i<n;i++)   {
                scanf("%d",scf+i);
                if (!scf[i])    cnt++;
            }
            if (cnt==n) break;
            for (int i=0;i<n;i++)   {
                if (ori[i]==scf[i]) {
                    A++;
                    rit[scf[i]]=true;
                }
            }
            for (int i=0;i<n;i++)
                if (!rit[scf[i]]&&pres[scf[i]]) {
                    B++;
                    rit[scf[i]]=true;
                }
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
