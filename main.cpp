#include <stdio.h>
#include <queue>
#include <stack>
#include <cstdlib>

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
typedef struct BSTNode {
    ElemType data;
    int bf;
    BSTNode *lchild, *rchild;
} *BSTree, BSTNode;

void visit(BitNode *p) {
    printf("%d", p->data);
}

bool IsComplete(BiTree T){

}

void CreateTree(BiTree &T) {
    int x;
    scanf("%d", &x);
    if (x != -1) {
        T = (BiTree) malloc(sizeof(BiTNode));
        T->data = x;
        T->rchild = T->lchild = NULL;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}


int main() {
    BiTree T;
    CreateTree(T);
}