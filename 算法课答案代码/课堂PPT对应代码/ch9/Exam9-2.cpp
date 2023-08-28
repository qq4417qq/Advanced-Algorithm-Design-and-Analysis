//��9.2���㷨
#include "Graph.cpp"
int visited[MAXV];
void FindaPath(ALGraph *G,int u,int v,int path[],int d)
{	//d��ʾpath�е�·�����ȣ���ʼΪ-1
	int w,i;
	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;				//·������d��1������u���뵽·����
	if (u==v)					//�ҵ�һ��·�������������
	{	printf("һ����·��Ϊ:");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
		return; 
	}
	p=G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;			//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindaPath(G,w,v,path,d);
		p=p->nextarc;			//pָ�򶥵�u����һ�����ڵ�
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
	int n=7,e=12,i;
	int u=0,v=5;
	int path[MAXV];
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	for (i=0;i<n;i++)		//��ʼ��visited����
		visited[i]=0;
	FindaPath(G,u,v,path,-1);
	DestroyAdj(G);
}
