//���ݷ����TSP����
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <list>
using namespace std;
typedef list<int> LISTINT;				//����list�б��ʾ����
LISTINT minpath;						//�������·��
int minpathlen=INF;						//�������·������
int getpathlen(MGraph g,LISTINT path)	//��path��һ��·���ĳ���
{	int sum=0,i;
	LISTINT::iterator j;
	i=0;								//���Ϊ0
	j=path.begin();
	while (j!=path.end())
	{	sum+=g.edges[i][*j];
		i=*j;
		j++;
	}
	return sum;
}

void disp(MGraph g,LISTINT path)
{
	LISTINT::iterator j;
	for (j=path.begin();j!=path.end();j++)
		printf("%d\t",*j);
	printf(":%d\n",getpathlen(g,path));
}

void getpath(MGraph g,int i,LISTINT V,LISTINT path)		//��TSP·������
{	LISTINT tmpV;
	LISTINT::iterator j;
	int tmpj,pathlen;
	path.push_back(i);
	if (V.size()==0)								//�ҵ�һ��Ҷ�ӽ��
	{
		if (g.edges[i][0]!=0 && g.edges[i][0]!=INF)	//�ö��㵽���0�б�
		{	
			path.push_back(0);				//·���м������0
			pathlen=getpathlen(g,path);		//��·������			
        	printf("Ҷ��i=%d:",i); disp(g,path);
			if (pathlen<minpathlen)
			{
				minpathlen=pathlen;
				minpath=path;
				printf("��С·������:minpathlen=%d\n",minpathlen);
			}
		}
	}
	else											//���ڷ�Ҷ�ӽ��
	{	printf("����i=%d:",i); disp(g,path);
		for (j=V.begin();j!=V.end();j++)
		{	tmpV=V;
			tmpj=*j;
			tmpV.remove(tmpj);
			pathlen=getpathlen(g,path);
			if (pathlen<minpathlen)					//��֧
				getpath(g,tmpj,tmpV,path);			//�ݹ����
			else
				printf("��֧\n");
		}
	}
}
void TSP(MGraph g)				//���ݷ���Ӷ���0������TSP·���ͳ���
{	int i;
	LISTINT V,path;
	LISTINT::iterator j;
	for (i=1;i<g.n;i++)
		V.push_back(i);
	getpath(g,0,V,path);		//���Ϊ0
	printf("TSP·������=%d\n",minpathlen);
	printf("���·��:");		//������·��
	j=minpath.begin();
	printf("%d",*j++);
	for (;j!=minpath.end();j++)
		printf("��%d",*j);
	printf("\n");
}
void main()
{
	MGraph g;
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);	//����ڽӾ���g
	printf("���Ϊ0�Ľ�:\n");TSP(g);
}
