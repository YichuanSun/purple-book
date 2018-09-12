#include <bits/stdc++.h>
#define N 1005
using namespace std;
int ori[N],nw[N];
int main()  {
    int n,num=0;
    while (scanf("%d",&n)&&n)   {
        for (int i=0;i<n;i++)   scanf("%d",&ori[i]);
        printf("Game %d:\n",++num);
        while (true)    {
            int a=0,b=0;
            for (int i=0;i<n;i++)   scanf("%d",&nw[i]);
            if (nw[0]==0)   break;
            for (int i=0;i<n;i++)
                if (ori[i]==nw[i])  a++;
            for (int i=1;i<=10;i++) {
                int cnta=0,cntb=0;
                for (int j=0;j<n;j++)   {
                    if (ori[j]==i)   cnta++;
                    if (nw[j]==i)   cntb++;
                }
                b+=min(cnta,cntb);
            }
            printf("    (%d,%d)\n",a,b-a);
        }
    }
    return 0;
}


//#include <bits/stdc++.h>
//#define N 1005
//using namespace std;
//int scf[N],ori[N];
//bool rit[N],pres[N];
//int main()  {
//    int n,times=1;
//    while (scanf("%d",&n)&&n)   {
//        fill(pres,pres+n,false);
//        for (int i=0;i<n;i++)   {
//            scanf("%d",ori+i);
//            pres[ori[i]]=true;
//        }
//        printf("Game %d:\n",times++);
//        while (true)    {
//            int cnt=0;
//            fill(rit,rit+20,false);
//            int A=0,B=0;
//            for (int i=0;i<n;i++)   {
//                scanf("%d",scf+i);
//                if (!scf[i])    cnt++;
//            }
//            if (cnt==n) break;
//            for (int i=0;i<n;i++)   {
//                if (ori[i]==scf[i]) {
//                    A++;
//                    rit[scf[i]]=true;
//                }
//            }
//            for (int i=0;i<n;i++)
//                if (!rit[scf[i]]&&pres[scf[i]]) {
//                    B++;
//                    rit[scf[i]]=true;
//                }
//            printf("    (%d,%d)\n",A,B);
//        }
//    }
//    return 0;
//}
