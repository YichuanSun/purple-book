#include <bits/stdc++.h>
#define N 100005
using namespace std;
char s[N];
struct node{
    char c;
    node* next;
};
node *head,*tail,*p;

int main()  {
    while (scanf("%s",s)!=EOF)  {
        head=new node;
        head->next=nullptr;
        p=tail=head;
        int len=strlen(s);
        for (int i=0;i<len;i++) {
            char c=s[i];
            if (c=='[') p=head;
            else if (c==']')    p=tail;
            else {
                node *nd=new node;
                nd->c=c;
                nd->next=p->next;
                p->next=nd;
                p=nd;
                if (p->next==nullptr)   tail=p;
            }
        }
        p=head->next;
        while (p!=nullptr) {
            printf("%c",p->c);
            p=p->next;
        }
        printf("\n");
    }
    return 0;
}
