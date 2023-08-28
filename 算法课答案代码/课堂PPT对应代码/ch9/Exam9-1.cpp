//��9.1���㷨
#include "Graph.cpp"
int visited[MAXV];
void ExistPath(ALGraph *G,int u,int v,bool &has)
{	//has��ʾu��v�Ƿ���·��,��ֵΪfalse
	int w;
	ArcNode *p;
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v)						//�ҵ���һ��·��
	{	has=true;					//��hasΪtrue�������㷨
		return;
	}
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u�����ڶ���
		if (visited[w]==0)			//��w����δ����,�ݹ������
			ExistPath(G,w,v,has);
		p=p->nextarc;				//pָ�򶥵�u����һ�����ڵ�
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
	bool has=false;
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	for (i=0;i<n;i++)		//��ʼ��visited����
		visited[i]=0;
	ExistPath(G,u,v,has);
	if (has)
		printf("�Ӷ���%d������%d���ڼ�·��\n",u,v);
	else
		printf("�Ӷ���%d������%d�����ڼ�·��\n",u,v);
	DestroyAdj(G);
}
