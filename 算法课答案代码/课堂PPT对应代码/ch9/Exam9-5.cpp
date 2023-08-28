//��9.5���㷨
#include "Graph.cpp"
typedef struct
{	int data;					//������
	int parent;				//ǰһ�������ڶ����е�λ��
} QUERE;						//�ǻ��ζ�������
void ShortPath(ALGraph *G,int u,int v)
{	//����Ӷ���u������v�������·��
	ArcNode *p;
	int w,i;
	QUERE qu[MAXV];			//�ǻ��ζ���
	int front=-1,rear=-1;		//���е�ͷ��βָ��
	int visited[MAXV];
	for (i=0;i<G->n;i++)		//���ʱ���ó�ֵ0
		visited[i]=0;
	rear++;					//����u����
	qu[rear].data=u;
	qu[rear].parent=-1;
	visited[u]=1;
	while (front!=rear)		//�Ӳ���ѭ��
	{	front++;				//���Ӷ���w
		w=qu[front].data;
		if (w==v)				//�ҵ�vʱ���·��֮�沢�˳�
		{	i=front;			//ͨ�����������·��
			while (qu[i].parent!=-1)
			{	printf("%3d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%3d\n",qu[i].data);
			break; 
		}
		p=G->adjlist[w].firstarc;	//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;			//��w��δ���ʹ����ڽӵ����
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;
			}
			p=p->nextarc;			//��w����һ���ڽӵ�
		}
	}
}
void main()
{
	ALGraph *G;
	int A[][MAXV]={			//һ����Ȩ����ͼ
		{0,  2, 5,  3, INF,INF,INF},
		{INF,0, 2, INF,INF, 8, INF},
		{INF,INF,0, 1,  3,  5, INF},
		{INF,INF,INF,0, 5, INF,INF},
		{INF,INF,INF,INF,0, 3,  9},
		{INF,INF,INF,INF,INF,0, 5},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7,e=12;
	int u=0,v=5;
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	printf("�Ӷ���%d������%d�����·��(��):\n",u,v);
	ShortPath(G,u,v);
	DestroyAdj(G);
}
