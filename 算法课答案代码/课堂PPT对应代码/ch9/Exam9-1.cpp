//例9.1的算法
#include "Graph.cpp"
int visited[MAXV];
void ExistPath(ALGraph *G,int u,int v,bool &has)
{	//has表示u到v是否有路径,初值为false
	int w;
	ArcNode *p;
	visited[u]=1;					//置已访问标记
	if (u==v)						//找到了一条路径
	{	has=true;					//置has为true并结束算法
		return;
	}
	p=G->adjlist[u].firstarc;		//p指向顶点u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;				//w为顶点u的相邻顶点
		if (visited[w]==0)			//若w顶点未访问,递归访问它
			ExistPath(G,w,v,has);
		p=p->nextarc;				//p指向顶点u的下一个相邻点
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
	bool has=false;
	CreateAdj(G,A,n,e);		//创建图的邻接表存储结构G
	printf("图的邻接表:\n");
	DispAdj(G);				//输出邻接表G
	for (i=0;i<n;i++)		//初始化visited数组
		visited[i]=0;
	ExistPath(G,u,v,has);
	if (has)
		printf("从顶点%d到顶点%d存在简单路径\n",u,v);
	else
		printf("从顶点%d到顶点%d不存在简单路径\n",u,v);
	DestroyAdj(G);
}
