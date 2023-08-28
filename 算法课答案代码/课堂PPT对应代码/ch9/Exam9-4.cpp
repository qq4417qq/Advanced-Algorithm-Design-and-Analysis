//��9.4���㷨
#include "Graph.cpp"
int visited[MAXV];
void PathAll(ALGraph *G,int u,int v,int l,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i;
	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;				//·������d��1������u���뵽·����
	if (u==v && d==l)				//���һ��·��
	{	printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;			//mΪu���ڽӵ�
		if (visited[w]==0)		//���ö���δ��Ƿ���,��ݹ����֮
			PathAll(G,w,v,l,path,d);
		p=p->nextarc;			//pָ�򶥵�u����һ�����ڵ�
	}
	visited[u]=0;				//����
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
	printf("�Ӷ���%d������%d�ĳ���Ϊ3�����м�·��:\n",u,v);
	PathAll(G,u,v,3,path,-1);
	DestroyAdj(G);
}
