#include <bits/stdc++.h>
using namespace std;
const char *m="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *pf[]={"not a palindrome.","a regular palindrome.","a mirrored string.","a mirrored palindrome."};
char ex(char c)   {
    if (isalpha(c)) return m[c-'A'];
    else    return m[c-'0'+25]; //注意是c-'0'+25,而不是c+25，因为c是个char型
}
int main()  {
    char s[1005];
    while (scanf("%s",s)==1)  {
        int pali=1,mirr=1;
        int len=strlen(s);
        for (int i=0;i<(len+1)/2;i++)   {
            if (s[i]!=s[len-1-i])   pali=0;
            if (ex(s[i])!=s[len-1-i])   mirr=0;
        }
        printf("%s -- is %s\n\n",s,pf[pali+2*mirr]);
    }
    return 0;
}
