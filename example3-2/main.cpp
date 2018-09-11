#include <bits/stdc++.h>
using namespace std;
char mp[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()  {
    int i,c;
    while ((c=getchar())!=EOF)  {
        for (i=1;mp[i]&&mp[i]!=c;i++);
        if (mp[i])  printf("%c",mp[i-1]);
        else    printf("%c",c);
    }
    return 0;
}







//自己写的，WA了，可能是因为输入里面有换行符
//#include <bits/stdc++.h>
//#define N 100005
//using namespace std;
//char a[N];
//char mp[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
//int main()  {
//    gets(a);
//    int len=strlen(a);
//    for (int i=0;i<len;i++) {
//        if (a[i]==' ')  {
//            printf(" ");
//            continue;
//        }
//        char *ss=strchr(mp,a[i]);
//        int suffix=ss-mp;
//        printf("%c",mp[suffix-1]);
//    }
//    printf("\n");
//    return 0;
//}
