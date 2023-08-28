//��ϰ��9
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXV 200001
//------ͼ���ڽӱ���---------
typedef struct ANode
{	int no;				//������
	struct ANode *nextarc;	//ָ����һ����ͨ�Ŷ�����
} ArcNode;
typedef struct Vnode
{
	ArcNode *firstarc;		//ָ���һ����ͨ�Ŷ�����
} VNode;
typedef struct
{	int n;				//�������
	int m;				//��ͨ�Ŷ������
	VNode adjlist[MAXV];	//��ͷ�������
} ALGraph;
int BFS(ALGraph *G,int s,int e)	//������������㷨
{	int visited[MAXV];
	struct
	{	int no;			//������
		int level;		//���
	} qu[MAXV];			//˳�����
	int front=0,rear=0,i,w,l;
	ArcNode *p;
	if (s==e) return 0;
	for (i=0;i<G->n;i++)
		visited[i]=0;
	visited[s]=1;
	rear=(rear+1) % MAXV;		//���s����
	qu[rear].no=s; qu[rear].level=0;
	while (front!=rear)
	{	front=(front+1) % MAXV;
		w=qu[front].no; l=qu[front].level;
		p=G->adjlist[w].firstarc;
		while (p!=NULL)
		{	if (visited[p->no]==0)
			{	visited[p->no]=1;
				rear=(rear+1) % MAXV;	//���ڶ������
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
void InitGraph(ALGraph *&G,int n)		//��ʼ���ڽӱ�
{	int i;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	G->n=n;
	G->m=0;
}
void Add(ALGraph *&G,int a,int b)		//ͼ�����һ����(a,b)
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
void DestroyGraph(ALGraph *&G)		//����ͼ
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
		{	printf("��(%d)",p->no);
			p=p->nextarc;
		}
		printf("����\n");
	}
}
int main()
{	ALGraph *G;
	int m,n,k,a,b,s,e,i;
	while (scanf("%d%d",&n,&m)==2)
	{	InitGraph(G,n);
		for (i=0;i<m;i++)		//�������뽨���ڽӱ��еĵ�����
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
