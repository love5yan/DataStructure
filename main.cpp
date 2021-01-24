#include <stdio.h>
#include <cstdlib>
#include <queue>
using namespace std;
const int MAXSize = 20;
typedef char ElemType;
typedef struct CSNode {
    ElemType data;
    int i;
    CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;
typedef struct Node {
    int data;
    Node *next;
} Node;
typedef struct CNode {
    ElemType data;
    Node *child;
} CNode, CTree[MAXSize];

void CreateCTree(CTree &C) {
    int i, j = 0;
    int n;
    int x;
    Node *rear;
    Node *p;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        scanf("%c", &C[i].data);
        C[i].child = NULL;
        scanf("%d", &x);
        j = 0;
        while (x != -1) {
            p = (Node *) malloc(sizeof(Node));
            p->data = x;
            p->next=NULL;
            if (j == 0) {
                C[i].child=p;
                rear=p;
            }else{
                rear->next=p;
                rear=rear->next;
            }
            j++;
            scanf("%d", &x);
        }
        getchar();
    }
}
void CToCSTree(CTree C,CSTree &L){
    L=(CSNode *)malloc(sizeof(CSNode));
    L->data=C[0].data;
    L->i=0;
    L->firstChild=NULL;
    L->nextSibling=NULL;
    queue<CSNode *>Q;
    CSNode *q,*r,*x;
    Node *p;
    int j;
    Q.push(L);
    while (!Q.empty()){
        j=0;
        x=Q.front();
        Q.pop();
        p=C[x->i].child;
        while(p){
            q=(CSNode *)malloc(sizeof(CSNode));
            q->i=p->data;
            q->data=C[q->i].data;
            q->nextSibling=NULL;
            if(j==0){
                x->firstChild=q;
                r=q;
            }else{
               r->nextSibling=q;
               r=q;
            }
            j++;
            Q.push(q);
            p=p->next;
        }
    }
}
void PreOrder(CSTree L){
    if(L){
        printf("%c",L->data);
        PreOrder(L->firstChild);
        PreOrder(L->nextSibling);
    }
}
int main(){
    CTree C;
    CSTree L;
    CreateCTree(C);
    CToCSTree(C,L);
    PreOrder(L);
}