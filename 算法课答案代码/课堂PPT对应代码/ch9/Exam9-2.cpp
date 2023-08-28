//例9.2的算法
#include "Graph.cpp"
int visited[MAXV];
void FindaPath(ALGraph *G,int u,int v,int path[],int d)
{	//d表示path中的路径长度，初始为-1
	int w,i;
	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;				//路径长度d增1，顶点u加入到路径中
	if (u==v)					//找到一条路径后输出并返回
	{	printf("一条简单路径为:");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
		return; 
	}
	p=G->adjlist[u].firstarc;	//p指向顶点u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;			//相邻点的编号为w
		if (visited[w]==0)
			FindaPath(G,w,v,path,d);
		p=p->nextarc;			//p指向顶点u的下一个相邻点
	}
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
	FindaPath(G,u,v,path,-1);
	DestroyAdj(G);
}
