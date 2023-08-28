//ͼ����ȱ����㷨
#include "Graph.cpp"
int visited[MAXV];
void DFS(MGraph g,int v)
{	int w;
	printf("%3d",v);					//��������ʶ���ı��
	visited[v]=1;						//���ѷ��ʱ��
	for (w=0;w<g.n;w++)					//�Ҷ���v���������ڵ�
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			DFS(g,w);					//�Ҷ���v��δ���ʹ������ڵ�w
}
void DFS(ALGraph *G,int v)
{	ArcNode *p;
	printf("%3d",v);					//��������ʶ���ı��
	visited[v]=1;						//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;			//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	if (visited[p->adjvex]==0)		//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);
		p=p->nextarc;					//pָ�򶥵�v����һ���ڽӵ�
	}
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
	int n=7,e=12,i;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	for (i=0;i<n;i++)		//��ʼ��visited����
		visited[i]=0;
	printf("DFS:");
	DFS(g,0);printf("\n");
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	for (i=0;i<n;i++)		//��ʼ��visited����
		visited[i]=0;
	printf("DFS:");
	DFS(G,0);printf("\n");
	DestroyAdj(G);
}
