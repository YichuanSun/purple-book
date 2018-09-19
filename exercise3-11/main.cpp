#include<cstdio>
#include<cstring>
const int maxn=100;
char a[maxn+1],b[maxn+1];
int n1,n2;
int min(const int &i,const int &j){
    return i<j?i:j;
}
int minLen(char *s1,char *s2,int &n){// n为s1的长度
    int sumLen=n1+n2,minn=min(n1,n2),len=sumLen;
    for(int i=0;i<n;i++){
        int ok=1,fix=min(n-i,minn);//fix的计算是一个难点
        for(int j=0;j<fix;j++)if(s1[i+j]=='2'&&s2[j]=='2'){
            ok=0;break;
        }
        if(ok&&len>sumLen-fix)len=sumLen-fix;
    }
    return len;
}
int main(){
    while(scanf("%s%s",&a,&b)==2){
        n1=strlen(a),n2=strlen(b);//无意中用到了逗号运算符
        printf("%d\n",min(minLen(a,b,n1),minLen(b,a,n2)));//用min函数取两次结果的最小值
    }
}
