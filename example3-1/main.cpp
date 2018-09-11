#include <bits/stdc++.h>
using namespace std;

int main()  {
    string s;
    bool p=true;
    while (getline(cin,s))  {
        for (unsigned i=0;i<s.size();i++) {
            if (s[i]=='"'){
                if (p)  cout<<"``";
                else    cout<<"''";
                p=!p;
            }
            else    cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
