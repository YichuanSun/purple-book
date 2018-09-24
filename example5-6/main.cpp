#include <bits/stdc++.h>
#define N 1005
using namespace std;
map<int,int> qnum;
set<int> sjud;
typedef queue<int> qi;
qi qq;          //标记当前总队列
qi cache[N];    //所有在排队的队伍的队员先后顺序，下标表示队伍号
void enqueue();
void dequeue();
int main()  {
    int n,m,num,cnt=0;
    cin>>n;
    while (n!=0)    {
        cout<<"Scenario #"<<++cnt<<endl;
        for (int i=0;i<n;i++)   {
            cin>>m;
            for (int j=0;j<m;j++) {
                cin>>num;
                qnum[num]=i;
            }
        }
        string opt="";
        cin>>opt;
        while (opt[0]!='S') {
            if (opt[0]=='E')    enqueue();
            else if (opt[0]=='D')   dequeue();
            cin>>opt;
        }
        cout<<endl;
        qnum.clear();
        sjud.clear();
        for (int i=0;i<n;i++)
            while (!cache[i].empty())   cache[i].pop();
        while (!qq.empty()) qq.pop();
        cin>>n;
    }
    return 0;
}

void enqueue()  {
    int nr;
    cin>>nr;
    if (!sjud.count(qnum[nr])){
        qq.push(qnum[nr]);
        sjud.insert(qnum[nr]);
    }
    cache[qnum[nr]].push(nr);
}

void dequeue()  {
    if (qq.empty()) return;
    if (!cache[qq.front()].empty()) {
        cout<<cache[qq.front()].front()<<endl;
        cache[qq.front()].pop();
    }
    if (cache[qq.front()].empty()&&!qq.empty())  {
        sjud.erase(qq.front());
        qq.pop();
    }
}
