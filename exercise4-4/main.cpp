#include <bits/stdc++.h>
using namespace std;
int sts[6][6]={ {1,2,3,4,5,6},{2,6,3,4,1,5},
{3,2,6,1,5,4},{4,1,5,2,6,3},{5,1,3,4,6,2},{6,2,4,3,5,1} };
bool solve(string s1,string s2);
int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("output.txt","wa",stdout);
    string s;
    while (cin>>s)  {
        string s1=s.substr(0,6),s2=s.substr(6);
        if (solve(s1,s2))    cout<<"TRUE"<<endl;
        else    cout<<"FALSE"<<endl;
    }
    return 0;
}

bool solve(string s1,string s2) {
    for (int i=0;i<6;i++)   {
        string ts(6,'\0');
        for (int j=0;j<6;j++)
            ts[j]=s1[sts[i][j]-1];
        for (int ct=0;ct<4;ct++)    {
            char cc=ts[1];
            ts[1]=ts[2];
            ts[2]=ts[4];
            ts[4]=ts[3];
            ts[3]=cc;
            if (ts==s2) return true;
        }
    }
    return false;
}
























////��֪��������������ˣ���Ӧ���Ȱ���ѡ������ת������ȥ
////����ת��Χ���ĸ��棬��������������³��ȫ��ѹ��������ȥ
////Ҳ����˵������㷨��õĶ�����Χ���ĸ����Ǵ����
//
//#include <bits/stdc++.h>
//using namespace std;
//
//string tot1(string ts)  {swap(ts[1],ts[2]),swap(ts[2],ts[4]),swap(ts[3],ts[4]);return ts;}
//string tot2(string ts)  {swap(ts[1],ts[4]),swap(ts[2],ts[3]);return ts;}
//string tot3(string ts)  {swap(ts[1],ts[3]),swap(ts[2],ts[3]),swap(ts[3],ts[4]);return ts;}
//
//int main()  {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    //freopen("output.txt","wa",stdout);
//    string s;
//    while (cin>>s)  {
//        string s1=s.substr(0,6);
//        string s2=s.substr(6);
//        int fg=0;
//        for (int i=0;i<6;i++)   {   //ѡ������һ����Ϊ��
//            //cout<<"Case: "<<i<<endl;
//            if (s1[i]!=s2[0])   continue;
//            string ts,ts1=s1;
//            //cout<<"ts1=\t"<<ts1<<endl;
//            char cc=ts1[5-i];
//            ts+=ts1[i];
//            //cout<<"ts[0]=\t"<<ts1[i]<<endl;
//            //cout<<"now ts=\t"<<ts<<endl;
//            ts1[5-i]='Z',ts1[i]='Z';        //���ֱ��ѭ��ɾ��erase���а�����ı�Ԫ�ش���Ҳ�ͱ�����ȫ�ˡ�
//            int k=0;
//            while (k<ts1.size())    {
//                if (ts1[k]=='Z')    ts1.erase(k,1);
//                else k++;
//            }
//            ts+=ts1;
//            ts+=cc;
//            //cout<<"cc=\t"<<cc<<endl;
////            cout<<ts<<endl;
////            cout<<tot1(ts)<<endl;
////            cout<<tot2(ts)<<endl;
////            cout<<tot3(ts)<<endl;
//            if (s2==ts||s2==tot1(ts)||s2==tot2(ts)||s2==tot3(ts))   {fg=1;break;}
//        }
//        if (fg) cout<<"TRUE"<<endl;
//        else cout<<"FALSE"<<endl;
//    }
//    return 0;
//}
