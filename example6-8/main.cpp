#include <bits/stdc++.h>
#define N 10005
using namespace std;

struct node{
    int val;
    node *left,*right;
};
int ino[N],post[N],ans=1000000,ta=0;

int read_arr(int* psp);
node* buildTree(int* ino,int* post,int n);
void dfs(node *root);

int main()  {
    int n=0;
    while (read_arr(ino))   {
        n=read_arr(post);
        node* root=buildTree(ino,post,n);
        dfs(root);
        cout<<"dgsgsg"<<endl;
        printf("%d\n",ans);
        ans=1000000,ta=0;
    }
    return 0;
}

int read_arr(int* psp) {
    int ee=0,c=0;
    while ((c=getchar())&&c!='\n'){
        if (c==EOF) return 0;
        psp[ee++]=c-'0';
    }
    return ee;
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
    cout<<root->val<<endl;
    cout<<"-----"<<endl;
    ta+=root->val;
    if (root->left==NULL&&root->right==NULL)    {
        if (ans>ta) ans=ta;
        return;
    }
    dfs(root->left);
    if (root->left!=NULL)   ta-=root->left->val;
    dfs(root->right);
    if (root->right!=NULL)  ta-=root->right->val;
}



