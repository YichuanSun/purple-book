#include <bits/stdc++.h>
#define N 10005
using namespace std;

struct node{
    int val;
    node *left,*right;
};
int ans=1000000,ta=0,num;
char ts[N];

int read_arr(int* psp);
node* buildTree(int* ino,int* post,int n);
void dfs(node *root);
void lfs(node* root);

int main()  {
    int n=0;
    while (true)   {
        //read_arr(ino)
        //n=read_arr(post);
        //printf("%d\n",n);
        n=7;
        int ino[N]={3,2,1,4,5,7,6};
        int post[N]={3,1,2,5,6,7,4};
        node* root=buildTree(ino,post,n);
        lfs(root);
        dfs(root);
        cout<<"dgsgsg"<<endl;
        printf("%d\n",ans);
        ans=1000000,ta=0;
    }
    return 0;
}
queue<node*> q;
void lfs(node* root)    {
    q.push(root);
    while (!q.empty())  {
        node* tq=q.front();
        q.pop();
        if (tq==NULL)   continue;
        cout<<tq->val<<' ';
        q.push(tq->left);
        q.push(tq->right);
    }
    cout<<endl;
}

int read_arr(int* psp) {
    return 1;
    string line;
    while (!getline(cin,line))  return 0;
    stringstream ss(line);
    int n=0,x;
    while (ss>>x)   psp[n++]=x;
    return n;
//    int ee=0,c=0,i=0;
//    gets(ts);
//    while (i<(int)strlen(ts))    {
//        sscanf(ts+i+1,"%d",&psp[ee++]);
//        for (;i<(int)strlen(ts);i++)
//            if (ts[i]==' ') break;
//    }
//    return ee;
}

node* buildTree(int* ino,int* post,int n)   {
    if (n==0)   return NULL;
    int s=0;
    while (ino[s]!=post[n-1])   s++;
    node* nnd=new node;
    nnd->left=buildTree(ino,post,s);
    nnd->val=ino[s];
    nnd->right=buildTree(ino+s+1,post+s,n-s-1);
    return new node;
}

void dfs(node *root) {
    if (root==NULL) return;
    //cout<<root->val<<endl;
    //cout<<"-----"<<endl;
    ta+=root->val;
    if (root->left==NULL&&root->right==NULL)    {
        if (ans>ta) {ans=ta,num=root->val;}
        return;
    }
    dfs(root->left);
    if (root->left!=NULL)   ta-=root->left->val;
    dfs(root->right);
    if (root->right!=NULL)  ta-=root->right->val;
}



