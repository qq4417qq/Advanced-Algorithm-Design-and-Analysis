//图的广度遍历算法
#include "Graph.cpp"
void BFS(MGraph g,int v)
{	int qu[MAXV],front=0,rear=0;			//定义循环队列并初始化
	int visited[MAXV];						//定义存放结点的访问标志的数组
	int w,i;
	for (i=0;i<g.n;i++) visited[i]=0;		//访问标志数组初始化
	printf("%3d",v);						//输出被访问顶点的编号
	visited[v]=1;							//置已访问标记
	rear=(rear+1)%MAXV;
	qu[rear]=v;								//v进队
	while (front!=rear)						//若队列不空时循环
	{	front=(front+1)%MAXV;
		w=qu[front];						//出队并赋给w
		for (i=0;i<g.n;i++)					//找与顶点w相邻的顶点
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{	//若当前邻接顶点i未被访问
				printf("%3d",i);			//访问相邻顶点
				visited[i]=1;				//置该顶点已被访问的标志
				rear=(rear+1)%MAXV;			//该顶点进队
				qu[rear]=i;
			}
	}
	printf("\n");
}
void BFS(ALGraph *G,int v)
{	ArcNode *p;
	int qu[MAXV],front=0,rear=0;			//定义循环队列并初始化队头队尾
	int visited[MAXV];						//定义存放顶点的访问标志的数组
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//访问标志数组初始化
	printf("%3d",v);						//输出被访问顶点的编号
	visited[v]=1; 							//置已访问标记
	rear=(rear+1)%MAXV;
	qu[rear]=v;								//v进队
	while (front!=rear)						//若队列不空时循环
	{	front=(front+1)%MAXV;
		w=qu[front];						//出队并赋给w
		p=G->adjlist[w].firstarc;			//找顶点w的第一个邻接点
		while (p!=NULL) 
		{	if (visited[p->adjvex]==0)		//若当前邻接顶点未被访问
			{	printf("%3d",p->adjvex);	//访问相邻顶点
				visited[p->adjvex]=1;		//置该顶点已被访问的标志
				rear=(rear+1)%MAXV;			//该顶点进队
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//找顶点w的下一个邻接点
		}
	}
	printf("\n");
}
void main()
{
	MGraph g;
	ALGraph *G;
	int A[][MAXV]={			//一个带权有向图
		{0,  2, 5,  3, INF,INF,INF},
		{INF,0, 2, INF,INF, 8, INF},
		{INF,INF,0, 1,  3,  5, INF},
		{INF,INF,INF,0, 5, INF,INF},
		{INF,INF,INF,INF,0, 3,  9},
		{INF,INF,INF,INF,INF,0, 5},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7,e=12;
	CreateMat(g,A,n,e);		//创建图的邻接矩阵存储结构g
	printf("图的邻接矩阵:\n");
	DispMat(g);				//输出邻接矩阵g
	printf("BFS:");
	BFS(g,0);printf("\n");
	CreateAdj(G,A,n,e);		//创建图的邻接表存储结构G
	printf("图的邻接表:\n");
	DispAdj(G);				//输出邻接表G
	printf("BFS:");
	BFS(G,0);printf("\n");
	DestroyAdj(G);
}
