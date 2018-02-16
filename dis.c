#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXVEX 100          /* 定义最大顶点数 */
typedef char VertextType; /* 定义顶点的类型 */
typedef int EdgeType;     /* 定义权（也就是距离）的类型 */
typedef int Pathmatirx[MAXVEX];
typedef int ShortPathTable[MAXVEX];


/*创建一个邻接矩阵的结构*/
typedef struct
{
    VertextType vexs[MAXVEX];   /*顶点表 */
    EdgeType arc[MAXVEX][MAXVEX];/*边表*/
    int numVertexes,numEdges;  /*图中当前的顶点数和边数*/
}MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGrapth( MGraph *G)
{
    int i,j,k,w;
    printf("输入定点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges); /*顶点数和边数　*/
    for(i = 0;i< G->numVertexes;i++)    /*读入顶点信息，建立顶点表 */
        printf("输入顶点名称：\n");
        scanf("%s", &G->vexs[i]);
    for(i = 0;i< G->numVertexes;i++)
        for(j = 0; j < G->numVertexes;j++)
            G->arc[i][j] = 0; /*邻接矩阵初始化*/
    for(k = 0; k<G->numEdges;k++)  /*读入 numEdges条边，建立矩阵*/
    {
        printf("输入变（vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w); /*输入变(vi vj) 上的权w */
        G->arc[i][j]=w;
        G->arc[j][i]= G->arc[i][j]; /*因为无向图，矩阵对称的 */
    }

}

void ShorttestPath(MGraph G)
{
    int v,w,k,min;
    int v0 = 0;
    Pathmatirx P;
    ShortPathTable D;
    int finale[MAXVEX];
    for(v=0;v<G.numVertexes;v++)
    {
        finale[v] = 0;
        D[v] = G.arc[v0][v];
        P[v] = 0;
    }
    D[v0] = 0;
    finale[v0] = 1;

    for(v=1;v<G.numVertexes;v++)
    {
        min = 999;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!finale[w] && D[w]<min)
            {
                k=w;
                min=D[w];
            }
        }
        finale[k] = 1;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!finale[w] && (min+G.arc[k][w]<D[w]))
            {
                D[w] = min + G.arc[k][w];
                P[w] = k;
            }
        }
    }
}

int main()
{
    int inDistance;
    printf("input the total distance:\n");
    scanf("%d",&inDistance);
    MGraph MGraph_1;
    CreateMGrapth(&MGraph_1);
    Pathmatirx P1;
    ShortPathTable D1;
    ShorttestPath(MGraph_1);
}

