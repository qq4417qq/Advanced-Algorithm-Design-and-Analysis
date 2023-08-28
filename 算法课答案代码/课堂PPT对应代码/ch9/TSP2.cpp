//动态规划求解TSP问题
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <algorithm>
#include <list>
#include <map>
using namespace std;
typedef list<int> LISTINT;				//采用list列表表示集合
struct node
{
	int i;
	LISTINT V;
	int minj;
} u[MAXV];			//用于存放决策变量值
int d=0;			//d表示u中元素个数
int getpathlen(MGraph g,int i,LISTINT V)	//求TSP路径长度
{
	LISTINT tmpV;
	LISTINT::iterator j;
	int minj,tmpj,pathlen;
	int minpathlen=INF;
	if (V.size()==0)				//当V为空时
	{
		u[d].i=i;
		u[d].V=V;
		u[d].minj=0;
		d++;
		return g.edges[0][i];
	}
	else							//当V为不空时
	{
		minj=-1;					//存放路径长度最小的顶点
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
		u[d].i=i;					//将其放入u中
		u[d].V=V;
		u[d].minj=minj;
		d++;
	}
	return minpathlen;
}
void disppath()				//通过u数组输出最短路径
{
	int minpath[MAXV];		//保存最短路径
	int minpathlen=0;		//最短路径长度
	LISTINT v;
	int i,j;
	minpath[minpathlen]=0;	//将起点放入路径中
	minpathlen++;
	for (i=0;i<d;i++)		//在u数组中找起点的元素(唯一)
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
	printf("0→");			//输出最短路径
	for (i=minpathlen-1;i>0;i--)
		printf("%d→",minpath[i]);
	printf("%d\n",minpath[0]);
}
void TSP(MGraph g)		//求从顶点0出发的TSP路径长度
{	int i;
	LISTINT V;
	for (i=1;i<g.n;i++)
		V.push_back(i);
	printf("TSP路径长度=%d\n",getpathlen(g,0,V));//起点为0
	printf("TSP路径:"); disppath();
}
void main()
{
	MGraph g;
	int A[][MAXV]={			//一个带权有向图
		{0,8,5,6},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//创建图的邻接矩阵存储结构g
	printf("邻接矩阵:\n"); DispMat(g);	//输出邻接矩阵g
	printf("起点为0的TSP最优解:\n"); TSP(g);
}
