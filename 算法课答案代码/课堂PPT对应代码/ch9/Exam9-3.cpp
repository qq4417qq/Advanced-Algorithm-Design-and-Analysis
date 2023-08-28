//例9.3的算法
#include "Graph.cpp"
int visited[MAXV];
void FindPath(ALGraph *G,int u,int v,int path[],int d)
{	//d表示path中的路径长度，初始为-1
	int w,i;
	ArcNode *p;
	d++; path[d]=u;				//路径长度d增1，顶点u加入到路径中
	visited[u]=1;					//置已访问标记
	if (u==v && d>=1)				//找到一条路径则输出
	{	for (i=0;i<=d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;		//p指向顶点u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;				//w为顶点u的相邻顶点
		if (visited[w]==0)			//若w顶点未访问,递归访问它
			FindPath(G,w,v,path,d);
		p=p->nextarc;				//p指向顶点u的下一个相邻点
	}
	visited[u]=0;					//回溯
}
void main()
{
	ALGraph *G;
	int A[][MAXV]={			//一个带权有向图
		{0,  2, 5,  3, INF,INF,INF},
		{INF,0, 2, INF,INF, 8, INF},
		{INF,INF,0, 1,  3,  5, INF},
		{INF,INF,INF,0, 5, INF,INF},
		{INF,INF,INF,INF,0, 3,  9},
		{INF,INF,INF,INF,INF,0, 5},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7,e=12,i;
	int u=0,v=5;
	int path[MAXV];
	CreateAdj(G,A,n,e);		//创建图的邻接表存储结构G
	printf("图的邻接表:\n");
	DispAdj(G);				//输出邻接表G
	for (i=0;i<n;i++)		//初始化visited数组
		visited[i]=0;
	printf("从顶点%d到顶点%d的所有简单路径:\n",u,v);
	FindPath(G,u,v,path,-1);
	DestroyAdj(G);
}
