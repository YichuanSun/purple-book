#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define L 1001000
#define inf 0x3f3f3f3f
using namespace std;
int a,b,n,l,dp[L],Q[L],head,tail,siz;
void in(int n)  {
    while (head<tail&&dp[Q[tail-1]]>=dp[n]) tail--;
    Q[tail++]=n;
    while (n-Q[head]>siz)   head++;
}

int main()  {

    return 0;
}
