#include<cstdio>
#include<cstring>
const int maxn=100;
char a[maxn+1],b[maxn+1];
int n1,n2;
int min(const int &i,const int &j){
    return i<j?i:j;
}
int minLen(char *s1,char *s2,int &n){// nΪs1�ĳ���
    int sumLen=n1+n2,minn=min(n1,n2),len=sumLen;
    for(int i=0;i<n;i++){
        int ok=1,fix=min(n-i,minn);//fix�ļ�����һ���ѵ�
        for(int j=0;j<fix;j++)if(s1[i+j]=='2'&&s2[j]=='2'){
            ok=0;break;
        }
        if(ok&&len>sumLen-fix)len=sumLen-fix;
    }
    return len;
}
int main(){
    while(scanf("%s%s",&a,&b)==2){
        n1=strlen(a),n2=strlen(b);//�������õ��˶��������
        printf("%d\n",min(minLen(a,b,n1),minLen(b,a,n2)));//��min����ȡ���ν������Сֵ
    }
}
