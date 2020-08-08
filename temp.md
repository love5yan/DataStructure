```c
#include <stdio.h>
#include <queue>
#include <stack>
#include <malloc.h>

using namespace std;
const int MaxVertexNum = 100;
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MaxVertexNum];//顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum, arcnum;//顶点数，弧数
} MGraph;
typedef struct ArcNode {//边表节点
    int adjvex;//该边指向的顶点位置
    ArcNode *next;//指向下一条弧的指针
    //infoType
} ArcNode;
typedef struct VNode {//顶点表节点
    VertexType data;//顶点信息
    ArcNode *first;//第一个边
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;//邻接表
    int vexnum, arcnum;//图的顶点数和弧数
} AlGraph;
bool visited[MaxVertexNum];


void visit(int v) {
}

int FirstNeighbor(MGraph G, int v) {
    return -1;
}
int FirstNeighbor(AlGraph G,int i){
    if(G.vertices[i].first) return G.vertices[i].first->adjvex;
    else return -1;
}
int NextNeighbor(MGraph G, int v, int w) {
    return -1;
}
int NextNeighbor(AlGraph G, int v, int w){
    ArcNode *p = G.vertices[v].first;
    while(p){
        if(p->adjvex==w&&p->next!=NULL) return p->next->adjvex;
        p=p->next;
    }
    return -1;
}
void Convert(AlGraph &G, MGraph &M) {
    ArcNode *p;
    for (int i = 0; i < M.vexnum; i++) {
        G.vertices[i].first;
        int tag = 1;
        for (int j = 0; j < M.vexnum; j++) {
            if (M.Edge[i][j]) {
                p = (ArcNode *) malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->next = NULL;
                if (tag) {
                    G.vertices[i].first = p;
                    tag = 0;
                } else {
                    p->next = G.vertices[i].first->next;
                    G.vertices[i].first->next = p;
                }
            }
        }
    }
}


int main() {
    AlGraph G;
    G.vexnum = 5;
    MGraph G1;
    G1.vexnum = 5;
    int path[MaxVertexNum];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            /*0 1 0 1 0
            1 0 1 0 1
            0 1 0 0 1
            1 0 0 0 0
            0 1 1 0 0
            0 0 0 0 0 0*/
            scanf("%d", &G1.Edge[i][j]);
        }
    }
    Convert(G, G1);
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    int d=0;
}
```