#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii plain[10];
bool spot[10];
int main()  {
    int cnt=0;
    pii tp;
    while (scanf("%d %d",&tp.first,&tp.second)!=EOF)    {
        plain[cnt%6]=tp;
        cnt++;
        if (cnt%6==0)   {
            int combo=0;
            for (int i=0;i<6;i++)   {
                if (spot[i])    continue;
                for (int j=i+1;j<6;j++) {
                    if (spot[i]||spot[j])    continue;      //֮ǰ�������˶�spot���жϡ���Ϊ���������ܴ���spot[i]
                    //�ѱ���Ϊtrue�����������˵��������a��������b��һ����c�����������һ�䣬�����possible����ʵ����impossible
                    if ((plain[i].first==plain[j].first&&plain[i].second==plain[j].second)
                        ||(plain[i].first==plain[j].second&&plain[i].second==plain[j].first))   {
                            spot[i]=spot[j]=true;
                            combo++;
                    }
                }
            }
            if (combo==3)   printf("POSSIBLE\n");
            else    printf("IMPOSSIBLE\n");
            fill(spot,spot+10,false);
            fill(plain,plain+10,make_pair(0,0));
        }
    }
    return 0;
}
