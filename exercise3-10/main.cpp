#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
pii plain[10];

bool cmp(pii a,pii b) {
    if (a.first==b.first)   return a.second<b.second;
    return a.first<b.first;
}
bool eq(pii a,pii b)    {
    if (a.first==b.first&&a.second==b.second)   return true;
    else if (a.first==b.second&&a.second==b.first)  return true;
    else return false;
}
int main()  {
    int cnt=0;
    pii tp;
    while (scanf("%d %d",&tp.first,&tp.second)!=EOF)    {
        if (tp.first>tp.second) swap(tp.first,tp.second);
        plain[cnt%6]=tp;
        cnt++;
        if (cnt%6==0)   {
            int cc=0;
            bool flag=false;
            pii lst;
            sort(plain,plain+6,cmp);
//            for (int i=0;i<6;i++)
//                printf("%d: %d %d\n",i,plain[i].first,plain[i].second);
            for (int i=0;i<6;i+=2)
                if (eq(plain[i],plain[i+1]))    cc++;
            if (cc==3)  {
                int a=plain[0].first,b=plain[2].first;
                int c=plain[0].second,d=plain[2].second;
                if (a==b)   lst=make_pair(c,d);
                else if (a==d)  lst=make_pair(b,c);
                if (eq(lst,plain[4]))   flag=true;
            }
            if (flag)   printf("POSSIBLE\n");
            else    printf("IMPOSSIBLE\n");
            fill(plain,plain+10,make_pair(0,0));
        }
    }
    return 0;
}
