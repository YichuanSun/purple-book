#include <bits/stdc++.h>
using namespace std;
struct node{
    node *pre,*nex;
    int val;
};
node* listReverse(node* head);
int main()  {
    node* head=new node,*tail;
    head->pre=NULL;
    tail=head;
    int n,t;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>t;
        node* tn=new node;
        tn->pre=head;
        tn->nex=nullptr;
        tn->val=t;
        tail->nex=tn;
        tail=tn;
    }
    node* tt=listReverse(head);
    while (tt)  {
        cout<<tt->val<<' ';
        tt=tt->nex;
    }
    cout<<endl;
    return 0;
}

node* listReverse(node* head)    {
    node *pnode=head,*pre=NULL;
    while (pnode)   {
        swap(pnode->nex,pnode->pre);
        pre=pnode;
        pnode=pnode->pre;
    }
    return pre;
}
