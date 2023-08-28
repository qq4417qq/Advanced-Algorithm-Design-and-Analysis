//ͼ�Ĺ�ȱ����㷨
#include "Graph.cpp"
void BFS(MGraph g,int v)
{	int qu[MAXV],front=0,rear=0;			//����ѭ�����в���ʼ��
	int visited[MAXV];						//�����Ž��ķ��ʱ�־������
	int w,i;
	for (i=0;i<g.n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%3d",v);						//��������ʶ���ı��
	visited[v]=1;							//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	qu[rear]=v;								//v����
	while (front!=rear)						//�����в���ʱѭ��
	{	front=(front+1)%MAXV;
		w=qu[front];						//���Ӳ�����w
		for (i=0;i<g.n;i++)					//���붥��w���ڵĶ���
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{	//����ǰ�ڽӶ���iδ������
				printf("%3d",i);			//�������ڶ���
				visited[i]=1;				//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				qu[rear]=i;
			}
	}
	printf("\n");
}
void BFS(ALGraph *G,int v)
{	ArcNode *p;
	int qu[MAXV],front=0,rear=0;			//����ѭ�����в���ʼ����ͷ��β
	int visited[MAXV];						//�����Ŷ���ķ��ʱ�־������
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%3d",v);						//��������ʶ���ı��
	visited[v]=1; 							//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	qu[rear]=v;								//v����
	while (front!=rear)						//�����в���ʱѭ��
	{	front=(front+1)%MAXV;
		w=qu[front];						//���Ӳ�����w
		p=G->adjlist[w].firstarc;			//�Ҷ���w�ĵ�һ���ڽӵ�
		while (p!=NULL) 
		{	if (visited[p->adjvex]==0)		//����ǰ�ڽӶ���δ������
			{	printf("%3d",p->adjvex);	//�������ڶ���
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				qu[rear]=p->adjvex;
			}
			p=p->nextarc;					//�Ҷ���w����һ���ڽӵ�
		}
	}
	printf("\n");
}
void main()
{
	MGraph g;
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
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("BFS:");
	BFS(g,0);printf("\n");
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	printf("BFS:");
	BFS(G,0);printf("\n");
	DestroyAdj(G);
}
