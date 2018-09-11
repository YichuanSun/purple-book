#include <bits/stdc++.h>
#define N 100005
using namespace std;
char a[N];
char mp[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()  {
    gets(a);
    int len=strlen(a);
    for (int i=0;i<len;i++) {
        if (a[i]==' ')  {
            printf(" ");
            continue;
        }
        char *ss=strchr(mp,a[i]);
        int suffix=ss-mp;
        printf("%c",mp[suffix-1]);
    }
    printf("\n");
    return 0;
}
