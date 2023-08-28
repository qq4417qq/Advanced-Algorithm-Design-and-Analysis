//练习题9
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXV 200001
//------图的邻接表定义---------
typedef struct ANode
{	int no;				//动物编号
	struct ANode *nextarc;	//指向下一个可通信动物结点
} ArcNode;
typedef struct Vnode
{
	ArcNode *firstarc;		//指向第一个可通信动物结点
} VNode;
typedef struct
{	int n;				//动物个数
	int m;				//可通信动物对数
	VNode adjlist[MAXV];	//表头结点数组
} ALGraph;
int BFS(ALGraph *G,int s,int e)	//广度优先搜索算法
{	int visited[MAXV];
	struct
	{	int no;			//动物编号
		int level;		//层次
	} qu[MAXV];			//顺序队列
	int front=0,rear=0,i,w,l;
	ArcNode *p;
	if (s==e) return 0;
	for (i=0;i<G->n;i++)
		visited[i]=0;
	visited[s]=1;
	rear=(rear+1) % MAXV;		//起点s进队
	qu[rear].no=s; qu[rear].level=0;
	while (front!=rear)
	{	front=(front+1) % MAXV;
		w=qu[front].no; l=qu[front].level;
		p=G->adjlist[w].firstarc;
		while (p!=NULL)
		{	if (visited[p->no]==0)
			{	visited[p->no]=1;
				rear=(rear+1) % MAXV;	//相邻动物进队
				qu[rear].no=p->no;
				qu[rear].level=l+1;
				if (p->no==e)
					return qu[rear].level-1;
			}
			p=p->nextarc;
		}
	}
	return -1;
}
void InitGraph(ALGraph *&G,int n)		//初始化邻接表
{	int i;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	G->n=n;
	G->m=0;
}
void Add(ALGraph *&G,int a,int b)		//图中添加一条边(a,b)
{	ArcNode *p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->no=b;
	p->nextarc=G->adjlist[a].firstarc;
	G->adjlist[a].firstarc=p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->no=a;
	p->nextarc=G->adjlist[b].firstarc;
	G->adjlist[b].firstarc=p;
	G->m++;
}
void DestroyGraph(ALGraph *&G)		//销毁图
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{	pre=G->adjlist[i].firstarc;
		while (pre!=NULL)
		{	p=pre->nextarc;
			free(pre);
			pre=p;
		}
	}
	free(G);
}
void DispGraph(ALGraph *G)
{	int i;
	ArcNode *p;
	printf("n=%d,e=%d\n",G->n,G->m);
	for (i=0;i<G->n;i++)
	{	printf("[%3d]:",i);
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	printf("→(%d)",p->no);
			p=p->nextarc;
		}
		printf("→∧\n");
	}
}
int main()
{	ALGraph *G;
	int m,n,k,a,b,s,e,i;
	while (scanf("%d%d",&n,&m)==2)
	{	InitGraph(G,n);
		for (i=0;i<m;i++)		//根据输入建立邻接表中的单链表
		{	scanf("%d%d",&a,&b);
			Add(G,a,b);
		}
		//DispGraph(G);
		scanf("%d",&k);
		for (i=0;i<k;i++)
		{	scanf("%d %d",&s,&e);
			printf("%d\n",BFS(G,s,e));
		}
		DestroyGraph(G);
	}
	return 0;
}
