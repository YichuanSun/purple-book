#include <bits/stdc++.h>
#define N 16
using namespace std;
int tot,n;
int C[N];
void Search(int row);
int main()  {
    cin>>n;
    Search(0);
    cout<<tot<<endl;
    return 0;
}

void Search(int row)    {
    if (row==n) tot++;
    else
        for (int i=0;i<n;i++)   {
            C[row]=i;
            int ok=1;
            for (int j=0;j<row;j++)
                if (C[row]==C[j]||row-C[row]==j-C[j]||row+C[row]==j+C[j])
                    {ok=0;break;}
            if (ok) Search(row+1);
        }
}
