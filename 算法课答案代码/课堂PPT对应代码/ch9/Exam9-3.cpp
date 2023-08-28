//��9.3���㷨
#include "Graph.cpp"
int visited[MAXV];
void FindPath(ALGraph *G,int u,int v,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i;
	ArcNode *p;
	d++; path[d]=u;				//·������d��1������u���뵽·����
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v && d>=1)				//�ҵ�һ��·�������
	{	for (i=0;i<=d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u�����ڶ���
		if (visited[w]==0)			//��w����δ����,�ݹ������
			FindPath(G,w,v,path,d);
		p=p->nextarc;				//pָ�򶥵�u����һ�����ڵ�
	}
	visited[u]=0;					//����
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
	int n=7,e=12,i;
	int u=0,v=5;
	int path[MAXV];
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	for (i=0;i<n;i++)		//��ʼ��visited����
		visited[i]=0;
	printf("�Ӷ���%d������%d�����м�·��:\n",u,v);
	FindPath(G,u,v,path,-1);
	DestroyAdj(G);
}
