//#include <bits/stdc++.h>
//using namespace std;
//vector<string> v;
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    string ori;
//    int n;
//    cin>>n;
//    while (n--) {
//        string ts="";
//        cin>>ori;
//        int len=ori.size();
//        for (int i=0;i<len;i++)   {
//            int j=i,cnt=0;
//            while (cnt<len) {
//                ts+=ori[j%len];
//                j++,cnt++;
//            }
//            v.push_back(ts);
//            ts="";
//        }
//        string ans(len,'Z');
//        for (unsigned i=0;i<v.size();i++)
//            if (ans>v[i])   ans=v[i];
//        cout<<ans<<endl;
//        v.clear();
//    }
//    return 0;
//}


#include <bits/stdc++.h>
#define N 105
using namespace std;

bool Less(const char *s,int p,int q)    {
    int n=strlen(s);
    for (int i=0;i<n;i++)   {
        if (s[(p+i)%n]!=s[(q+i)%n])
            return s[(p+i)%n]<s[(q+i)%n];
    }
    return 0;
}

int main()  {
    int n;
    char s[N];
    scanf("%d",&n);
    while (n--) {
        scanf("%s",s);
        int ans=0,len=strlen(s);
        for (int i=1;i<len;i++)
            if (Less(s,i,ans))  ans=i;
        for (int i=0;i<len;i++)
            printf("%c",s[(ans+i)%len]);
        printf("\n");
    }
    return 0;
}




