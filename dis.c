#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef char VertextType; /* 定义顶点的类型 */
typedef int EdgeType;     /* 定义权（也就是距离）的类型 */
#define MAXVEX 100          /* 定义最大顶点数 */

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

/*Prim 算法生成最小生成树*/
void FindTree(MGraph G,int inDis)
{
    int sumDis,diffDis,newDiff,i,j,k;
    sumDis = 0;
    diffDis = 9999;
    newDiff = 0;
    MGraph tmpG;
    for(i = 0;i< G.numVertexes;i++)
    {
        k = i;
        tmpG = G;
        for(j = 0;j< G.numVertexes;j++)
        {
            if (tmpG.arc[k][j]!=0)
            {
                sumDis += tmpG.arc[k][j];
                tmpG.arc[k][j] = 0;
                printf("(%d,%d)",k,j);
                printf("G.arc=%d",G.arc[k][j]);
                printf("tmpG.arc=%d \n",tmpG.arc[k][j]);
                if(j == G.numVertexes-1)
                {
                    tmpG = G;
                    sumDis = 0;
                    newDiff = labs(inDis-sumDis);
                    if(newDiff < diffDis)
                    {
                        diffDis = newDiff;
                        printf("total distance=%d,start next.\n",sumDis);
                    }
                }else{
                    k=j;
                    j=1;
                }
            }
         }
    }
}

typedef int Pathmatirx[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void ShorttestPath(MGraph G, int v0,Pathmatirx *P,ShortPathTable *D)
{
    int v,w,k,min;
    int finale[MAXVEX];
    for(v=0;v<G.numVertexes;v++)
    {
        finale[v] = 0;
        (*D)[v] = G.matirx[v0][v];
        (*P)[v] = 0;
    }
    (*D)[v0] = 0;
    finale[v0] = 1;

    for(v=1;v<G.numVertexes;v++)
    {
    /*此下面未写完。打算将把此程序改写成python*/
}

int main()
{
    int inDistance;
    printf("input the total distance:\n");
    scanf("%d",&inDistance);
    MGraph MGraph_1;
    CreateMGrapth(&MGraph_1);
    //FindTree(MGraph_1,inDistance);
}

