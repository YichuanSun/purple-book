#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    char c;
    scanf("%d",&n);
    getchar();
    while (n--) {
        int f=0,sum=0;
        while ((c=getchar())&&c!='\n')  {
            if (c=='O') {
                f++;
                sum+=f;
            }
            else    f=0;
        }
        printf("%d\n",sum);
    }
    return 0;
}
