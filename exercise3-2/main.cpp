//�����޳ܵ�����Ϊ�Ƚ϶̣������ַ������Ӷ�o(n)���߼��Ƚ�������

#include <bits/stdc++.h>
using namespace std;
map<char,double> mp;    //�洢������ӳ���ֵ
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
        for (int i=0;i<(int)s.size()-1;i++)   {     //��ֹԽ�磬������size-2��
            if (isalpha(s[i]))  {       //���iԪ������ĸ
                if (isalpha(s[i+1]))    //���i��i+1������ĸ
                    sum+=mp[s[i]];
                else    {               //���i����ĸ��i+1������
                    int j=i+1,aa=1;
                    double di=0;
                    for (;isdigit(s[j]);j++);   //Ѱ�����ֵ������
                    for (int k=j-1;k>=i+1;k--)    {     //������һѭ������ʱ��j�϶�������ĸ�ϣ�����k=j-1���ص������ϡ�
                        di+=(s[k]-'0')*aa;
                        aa*=10;
                    }                           //����һ���ζ���ת��i�ŷ��ӵķ��Ӹ���
                    sum+=mp[s[i]]*di;           //�ѷ�����������һ����
                    i=j-1;                      //����֮���i++������ʱj�Ѿ����ڷ�ĸ�ϣ�����i=j���У���©��һ��Ԫ�أ���i=j-1
                }
            }
        }
        int ed=(int)s.size()-1;
        if (isalpha(s[ed])) sum+=mp[s[ed]];         //�����һ��Ԫ�ش���
        cout.setf(ios::fixed);
        cout<<setprecision(3)<<sum<<endl;           //�����
    }
    return 0;
}
