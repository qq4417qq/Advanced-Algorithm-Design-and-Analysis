//例9.5的算法
#include "Graph.cpp"
typedef struct
{	int data;					//顶点编号
	int parent;				//前一个顶点在队列中的位置
} QUERE;						//非环形队列类型
void ShortPath(ALGraph *G,int u,int v)
{	//输出从顶点u到顶点v的最短逆路径
	ArcNode *p;
	int w,i;
	QUERE qu[MAXV];			//非环形队列
	int front=-1,rear=-1;		//队列的头、尾指针
	int visited[MAXV];
	for (i=0;i<G->n;i++)		//访问标记置初值0
		visited[i]=0;
	rear++;					//顶点u进队
	qu[rear].data=u;
	qu[rear].parent=-1;
	visited[u]=1;
	while (front!=rear)		//队不空循环
	{	front++;				//出队顶点w
		w=qu[front].data;
		if (w==v)				//找到v时输出路径之逆并退出
		{	i=front;			//通过队列输出逆路径
			while (qu[i].parent!=-1)
			{	printf("%3d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%3d\n",qu[i].data);
			break; 
		}
		p=G->adjlist[w].firstarc;	//找w的第一个邻接点
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;			//将w的未访问过的邻接点进队
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;
			}
			p=p->nextarc;			//找w的下一个邻接点
		}
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
	int n=7,e=12;
	int u=0,v=5;
	CreateAdj(G,A,n,e);		//创建图的邻接表存储结构G
	printf("图的邻接表:\n");
	DispAdj(G);				//输出邻接表G
	printf("从顶点%d到顶点%d的最短路径(逆):\n",u,v);
	ShortPath(G,u,v);
	DestroyAdj(G);
}
