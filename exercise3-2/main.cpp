//厚颜无耻的自认为比较短，单个字符串复杂度o(n)，逻辑比较清晰。

#include <bits/stdc++.h>
using namespace std;
map<char,double> mp;    //存储分子量映射的值
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    mp.insert(make_pair('C',12.01));
    mp.insert(make_pair('H',1.008));
    mp.insert(make_pair('O',16.00));
    mp.insert(make_pair('N',14.01));
    int n;
    cin>>n;
    while (n--) {
        double sum=0;
        cin>>s;
        for (int i=0;i<(int)s.size()-1;i++)   {     //防止越界，遍历到size-2处
            if (isalpha(s[i]))  {       //如果i元素是字母
                if (isalpha(s[i+1]))    //如果i和i+1都是字母
                    sum+=mp[s[i]];
                else    {               //如果i是字母，i+1是数字
                    int j=i+1,aa=1;
                    double di=0;
                    for (;isdigit(s[j]);j++);   //寻找数字的最长长度
                    for (int k=j-1;k>=i+1;k--)    {     //由于上一循环结束时，j肯定落在字母上，所以k=j-1，回到数字上。
                        di+=(s[k]-'0')*aa;
                        aa*=10;
                    }                           //上面一整段都在转化i号分子的分子个数
                    sum+=mp[s[i]]*di;           //把分子量加上这一部分
                    i=j-1;                      //由于之后会i++，而此时j已经落在分母上，所以i=j不行，会漏掉一个元素，需i=j-1
                }
            }
        }
        int ed=(int)s.size()-1;
        if (isalpha(s[ed])) sum+=mp[s[ed]];         //对最后一个元素处理
        cout.setf(ios::fixed);
        cout<<setprecision(3)<<sum<<endl;           //输出答案
    }
    return 0;
}
