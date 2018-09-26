#include <bits/stdc++.h>
using namespace std;
struct node{
    node *pre,*nex;
    int val;
};
int main()  {
    node* head=new node;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)   {
        cin>>t;
        node* tn=new node;
        tn->pre=head;
    }
    return 0;
}

listReverse(node* head)    {
    node *pnode=head,*pre=NULL;
    while (pnode)   {
        swap(pnode->next,pnode->pre);
        pre=pnode;
        pnode=pnode->pre;
    }
    return pre;
}
