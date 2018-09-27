#include <bits/stdc++.h>
using namespace std;
struct node{
    bool used;
    int val;
    node *left,*right;
    node(bool used=false,int val=0,node* left=NULL,node* right=NULL)  {};
};
node root;
char s[300];
bool read_data();
void buildTree(int num,char* s);
int main()  {
    return 0;
}

bool read_data()    {
    root=new node;
    while (scanf("%s",s))   {
        int num;
        if (!strcmp(s,"()"))    return true;
        sscanf(s+1,"%d",&num);
        buildTree(num,strchr(s,',')+1);
    }
    return false;
}

void buildTree(int num,char* s) {
    int n=strlen(s);
    node* it1=root;
    for (int i=0;i<n;i++) {
        if (s[i]=='L')  {
            if (it1->left==NUll)
                it1->left=new node;
            it1=it1->left;
        }
        else if (s[i]=='R') {
            if (it1->right==NULL)
                it1->right=new node;
            it1=it1->right;
        }
    }
    if (it1->used)  failed=true;
    it1->val=num;
    it1->used=true;
}

















//struct node{
//    int val;
//    node *left,*right;
//};
//string s;
//int main()  {
//    while (cin>>s){
//        int pos=s.find(',');
//        if (pos==string::npos)  {
//            delete head;
//        }
//        string nb=s.substr(1,pos-1);
//        string tac=s.substr(pos+1);
//        tac.erase((int)tac.size()-1);
//        buildTree(nb,tac);
//    }
//    return 0;
//}
//
//void buildTree
