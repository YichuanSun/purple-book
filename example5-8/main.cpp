#include <bits/stdc++.h>
#define N 105
using namespace std;
const int maxcol=60;
vector<string> vs;
string s;
bool cmp(string a,string b) {return a<b;}
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("output.txt","wa",stdout);
    int n;
    while (cin>>n)  {
        int mxlen=0;
        for (int i=0;i<n;i++)   {
            cin>>s;
            vs.push_back(s);
            mxlen=max(mxlen,(int)s.size());
        }
        sort(vs.begin(),vs.end(),cmp);
        int col=(maxcol-mxlen)/(mxlen+2)+1;
        int row=(n-1)/col+1;
        int tot=row-(row*col-n);
        cout<<"------------------------------------------------------------"<<endl;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                int pos=i+j*row;
                if (pos>=n) continue;
                cout<<vs[pos];
                int bk=mxlen-vs[pos].size();
                while (bk--)    cout<<' ';
                if (j!=col-1)   cout<<"  ";
            }
            cout<<endl;
        }
        vs.clear();
    }
    return 0;
}
