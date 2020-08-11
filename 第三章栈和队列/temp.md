```c
#include <stdio.h>
#include <cstdlib>

using namespace std;
const int MaxSize = 50;
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;
typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
} LinkNode, *LinkStack;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    if (S.top == -1) return true;
    else return false;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

bool pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)return false;
    x = S.data[S.top];
    return true;
}

void InitStack(LinkStack &S) {
    S = (LinkStack) malloc(sizeof(LinkNode));
    S->next = NULL;
}

bool StackEmpty(LinkStack S) {
    if (S->next == NULL) return true;
    else return false;
}

bool Push(LinkStack &S, ElemType x) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    p->next = S->next;
    S->next = p;
    return true;
}

bool Pop(LinkStack &S, ElemType &x) {
    if (S->next == NULL) return false;
    LinkNode *p = S->next;
    x = p->data;
    S->next = p->next;
    free(p);
    return true;
}

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}

bool isEmpty(SqQueue Q){
    if(Q.rear=Q.front) return true;
    else return false;
}

bool Push(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front) return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    Q.rear=NULL;
}

bool isEmpty(LinkQueue &Q){
    if(Q.front==Q.rear) return true;
    else return false;
}

bool EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    p->data=x;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return true;
}

bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.rear==Q.front) return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p) Q.rear=Q.front;
    free(p);
    return true;
}

void InitStack1(LinkStack &S){
    S=NULL;
}

bool isEmpty(LinkStack S){
    if(S==NULL) return true;
    else return false;
}

bool Push1(LinkStack &S,ElemType x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    p->data=x;
    p->next=S;
    S=p;
    return true;
}

bool Pop1(LinkStack &S,ElemType &x){
    if(S==NULL) return false;
    LinkNode *p=S;
    S=p->next;
    x=p->data;
    free(p);
    return true;
}
```
