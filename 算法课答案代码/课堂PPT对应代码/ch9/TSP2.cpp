//��̬�滮���TSP����
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <algorithm>
#include <list>
#include <map>
using namespace std;
typedef list<int> LISTINT;				//����list�б��ʾ����
struct node
{
	int i;
	LISTINT V;
	int minj;
} u[MAXV];			//���ڴ�ž��߱���ֵ
int d=0;			//d��ʾu��Ԫ�ظ���
int getpathlen(MGraph g,int i,LISTINT V)	//��TSP·������
{
	LISTINT tmpV;
	LISTINT::iterator j;
	int minj,tmpj,pathlen;
	int minpathlen=INF;
	if (V.size()==0)				//��VΪ��ʱ
	{
		u[d].i=i;
		u[d].V=V;
		u[d].minj=0;
		d++;
		return g.edges[0][i];
	}
	else							//��VΪ����ʱ
	{
		minj=-1;					//���·��������С�Ķ���
		for (j=V.begin();j!=V.end();j++)
		{	tmpV=V;
			tmpj=*j;
			tmpV.remove(tmpj);
			pathlen=getpathlen(g,tmpj,tmpV)+g.edges[tmpj][i];
			if (pathlen<minpathlen)
			{
				minpathlen=pathlen;
				minj=tmpj;
			}
		}
		u[d].i=i;					//�������u��
		u[d].V=V;
		u[d].minj=minj;
		d++;
	}
	return minpathlen;
}
void disppath()				//ͨ��u����������·��
{
	int minpath[MAXV];		//�������·��
	int minpathlen=0;		//���·������
	LISTINT v;
	int i,j;
	minpath[minpathlen]=0;	//��������·����
	minpathlen++;
	for (i=0;i<d;i++)		//��u������������Ԫ��(Ψһ)
		if (u[i].i==0)
			break;
	v=u[i].V;
	i=u[i].minj;
	v.remove(i);
	while (i!=0)
	{
		minpath[minpathlen]=i;
		minpathlen++;
		for (j=0;j<d;j++)
			if (u[j].i==i && u[j].V==v)
				break;
		v=u[i].V;
		i=u[i].minj;
		v.remove(i);
	}
	printf("0��");			//������·��
	for (i=minpathlen-1;i>0;i--)
		printf("%d��",minpath[i]);
	printf("%d\n",minpath[0]);
}
void TSP(MGraph g)		//��Ӷ���0������TSP·������
{	int i;
	LISTINT V;
	for (i=1;i<g.n;i++)
		V.push_back(i);
	printf("TSP·������=%d\n",getpathlen(g,0,V));//���Ϊ0
	printf("TSP·��:"); disppath();
}
void main()
{
	MGraph g;
	int A[][MAXV]={			//һ����Ȩ����ͼ
		{0,8,5,6},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);	//����ڽӾ���g
	printf("���Ϊ0��TSP���Ž�:\n"); TSP(g);
}
