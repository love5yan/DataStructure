#include <stdio.h>
#include <queue>
#include<stack>

using namespace std;
const int MaxLength = 100;
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;
} BitNode, *BiTree;
typedef struct ThreadNode {
    ElemType data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(BiTNode *T) {
    printf("%d", T->data);
}

void PreOrder(BiTNode *T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTNode *T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTNode *T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BiTree T) {
    queue<BiTNode *> Q;
    //Initqueue(Q);
    BiTNode *p;
    if (T != NULL)
        Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild != NULL) Q.push(p->lchild);
        if (p->rchild != NULL) Q.push(p->rchild);
    }
}

void PreOrder1(BiTree T) {
    stack<BiTNode *> S;
    //Initstack(S);
    BitNode *p = T;
    while (p || !S.empty()) {
        if (p) {
            visit(p);
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
}

void InOrder1(BiTree T) {
    stack<BiTNode *> S;
    //Initstack(S);
    BitNode *p = T;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            S.pop();
            visit(p);
            p = p->rchild;
        }
    }
}

void PostOrder1(BiTree T) {
    stack<BiTNode *> S;
    //InitStack(S);
    BiTNode *p = T, *r = NULL;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            if (p->rchild != NULL && p->rchild != r) {
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            } else {
                p = S.top();
                S.pop();
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}

void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree &p) {
    ThreadTree pre = NULL;
    if(p!=NULL){
        InThread(p,pre);
        pre->rchild=NULL;
        p->rtag=1;
    }
}

ThreadNode *FirstNode(ThreadNode *p) {

}

ThreadNode *NextNode(ThreadNode *p) {

}

void InOrder(ThreadNode *T) {

}

int main() {

}