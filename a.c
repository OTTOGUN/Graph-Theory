#include <stdio.h>
#include <stdlib.h>

#define MAXVERTEX 20
#define ERROR 0
#define OK 1
#define MAXWEIGHT 23267

typedef char VertexType;
typedef int MatrixType;

typedef struct _AMGraph{
    int vertices,edges;
    char vertex[MAXVERTEX];
    MatrixType edge[MAXVERTEX][MAXVERTEX];
}AMGraph;

int locate_vertex(AMGraph* G,char name){
    for(int i = 0;i < G ->vertices;i++){
        if(G -> vertex[i] == name){
            return i;
        }
    }
    return ERROR;
}

void Creat_UnAMGraph_Unweighted(AMGraph* G){
    //初始化边和个数
    printf("请输边和顶点的数量:\n");
    scanf("%d",&G -> edges);
    getchar();
    scanf("%d",&G -> vertices);

    for(int i = 0;i < G -> vertices;i++){
        printf("请输入每个顶点的名字\n");
        getchar();
        scanf("%c",&(G -> vertex[i]));
    }

    //初始化矩阵
    for(int i = 0;i < G -> vertices;i++)
        for (int j = 0; j < G->vertices; j++)
            G->edge[i][j] = 0;

        char v1,v2;
        int index_v1,index_v2;
        for(int i = 0;i < G -> edges;i++){
            printf("请输入边\n");
            getchar();
            scanf("%c %c",&v1,&v2);
            index_v1 = locate_vertex(G,v1);
            index_v2 = locate_vertex(G,v2);

            G -> edge[index_v1][index_v2] = 1;
            G -> edge[index_v2][index_v1] = 1;
        }
    }

void Traverse(AMGraph* G){
    for(int i = 0;i < G -> vertices;i++){
        for(int j = 0;j < G -> vertices;j++){
            printf("%d\t",G -> edge[i][j]);
        }
        printf("\n");
    }
}

//》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》

void Creat_UnAMGraph_Weighted(AMGraph* G){
    //初始边以及顶点的个数
    printf("请输入顶点以及边的个数\n");
    scanf("%d",&G -> vertices);
    scanf("%d",&G -> edges);

    for(int i = 0;i < G -> vertices;i++){
        printf("请输入每个顶点的名字\n");
        getchar();
        scanf("%c",&G -> vertex[i]);
    }

    //初始矩阵
    for(int i = 0;i < G -> vertices;i++){
        for(int j = 0;j < G -> vertices;j++){
            G -> edge[i][j] = 0;
        }
    }

    char v1,v2;
    int l1,l2;
    int weight;
    for(int i = 0;i < G -> vertices;i++){
        printf("请输入第%d条边的起点与终点,以及权重\n",i + 1);
        getchar();
        scanf("%c %c %d",&v1,&v2,&weight);

        l1 = locate_vertex(G,v1);
        l2 = locate_vertex(G,v2);

        G -> edge[l1][l2] = weight;
        G -> edge[l2][l1] = weight;
    }
}

//》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》

typedef struct _EdgeNode{
    int weight,adjacency;
    struct Edge* next;
}Edge;

typedef struct _HeadNode{
    VertexType name;
    Edge* first;
}Head;

typedef struct _ALGraph{
    int vertices;
    int edges;
    Head vertex[MAXVERTEX];
}ALGraph;

void Creat_UnALGraph_UnWeighted(AMGraph* G){
    //初始化边和顶点个数
    printf("请输入边数和顶点数\n");
    getchar();
    scanf("%d",G -> vertices);
    scanf("%d",G -> edges);

    for(int i = 0;i < G -> vertices;i++){
        printf("请输入每个顶点的名字\n");
        getchar();
        scanf("%c",&G -> vertex[i].name);
        G -> vertex[i].first;
    }
}

int main(){
}