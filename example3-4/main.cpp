#include <bits/stdc++.h>
#define N 1005
using namespace std;
int scf[N],ori[N];
bool right[N],pres[N];
int main()  {
    int n,times=1;
    while (scanf("%d",&n)&&n)   {
        fill(right,right+n,false);
        fill(pres,pres+n,false);
        for (int i=0;i<n;i++)   scanf("%d",ori+i);
        printf("Game %d:\n",times++);
        while (true)    {
            int A=0,B=0;
            for (int i=0;i<n;i++)   {
                scanf("%d",scf+i);
                if (!scf[i])    cnt++;
                //if (afind(ori,scf[i]))  pres[i]=true;
            }
            if (cnt==n) break;
            for (int i=0;i<n;i++)
                if (ori[i]==scf[i]) right[ori[i]]=true;
            printf("\t(%d,%d)\n",A,B);
        }
    }
    return 0;
}
