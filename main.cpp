#include <stdio.h>

const int MaxVertexNum=100;
typedef char VertexType ;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];//顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum,arcnum;//顶点数，弧数
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

int main(){

}