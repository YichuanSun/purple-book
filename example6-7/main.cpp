#include <bits/stdc++.h>
#define N 300
using namespace std;
char s[N];
bool failed;
struct node   {
    bool used=false;
    int val;
    node *left=NULL,*right=NULL;
};
node* root;
queue<node*> qn;
vector<int> ans;

void dlt(node *a)  {
    if (a==NULL)    return;
    dlt(a->left);
    dlt(a->right);
    delete a;
}

void buildNode(int v,char *a)    {
    node *nw=root;
    for (int i=0;a[i]!=')';i++) {
        if (a[i]=='L')  {
            if (nw->left==NULL)   nw->left=new node;
            nw=nw->left;
        }
        else if (a[i]=='R') {
            if (nw->right==NULL)    nw->right=new node;
            nw=nw->right;
        }
    }
    if (nw->used)   failed=false;
    nw->val=v;
    nw->used=true;
}

bool read_input()   {
    failed=true;
    dlt(root);
    root=new node;
    while (true)    {
        if (scanf("%s",s)!=1)   return false;
        if (!strcmp(s,"()"))    break;
        int v;
        sscanf(s+1,"%d",&v);
        buildNode(v,strchr(s+1,',')+1);
    }
    return true;
}

void bfs()  {
    if (failed==false)  {
        printf("not complete\n");
        return;
    }
    qn.push(root);
    while (!qn.empty()) {
        node* p=qn.front();qn.pop();
        if (p->left)    qn.push(p->left);
        if (p->right)   qn.push(p->right);
        ans.push_back(p->val);
    }
    printf("%d",ans[0]);
    for (int i=1;i<(int)ans.size();i++) printf(" %d",ans[i]);
    printf("\n");
    ans.clear();
    while (!qn.empty()) qn.pop();
}

int main()  {
    while (read_input())    bfs();
    return 0;
}





//#include <bits/stdc++.h>
//using namespace std;
//struct node{
//    bool used;
//    int val;
//    node *left,*right;
//    node(bool used=false,int val=0,node* left=NULL,node* right=NULL)  {};
//};
//node root;
//char s[300];
//bool read_data();
//void buildTree(int num,char* s);
//int main()  {
//    return 0;
//}
//
//bool read_data()    {
//    root=new node;
//    while (scanf("%s",s))   {
//        int num;
//        if (!strcmp(s,"()"))    return true;
//        sscanf(s+1,"%d",&num);
//        buildTree(num,strchr(s,',')+1);
//    }
//    return false;
//}
//
//void buildTree(int num,char* s) {
//    int n=strlen(s);
//    node* it1=root;
//    for (int i=0;i<n;i++) {
//        if (s[i]=='L')  {
//            if (it1->left==NUll)
//                it1->left=new node;
//            it1=it1->left;
//        }
//        else if (s[i]=='R') {
//            if (it1->right==NULL)
//                it1->right=new node;
//            it1=it1->right;
//        }
//    }
//    if (it1->used)  failed=true;
//    it1->val=num;
//    it1->used=true;
//}

















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
