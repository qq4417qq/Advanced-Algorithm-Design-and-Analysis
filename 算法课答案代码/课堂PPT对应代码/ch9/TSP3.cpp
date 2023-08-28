//回溯法求解TSP问题
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <list>
using namespace std;
typedef list<int> LISTINT;				//采用list列表表示集合
LISTINT minpath;						//保存最短路径
int minpathlen=INF;						//保存最短路径长度
int getpathlen(MGraph g,LISTINT path)	//求path中一条路径的长度
{	int sum=0,i;
	LISTINT::iterator j;
	i=0;								//起点为0
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

void getpath(MGraph g,int i,LISTINT V,LISTINT path)		//求TSP路径长度
{	LISTINT tmpV;
	LISTINT::iterator j;
	int tmpj,pathlen;
	path.push_back(i);
	if (V.size()==0)								//找到一个叶子结点
	{
		if (g.edges[i][0]!=0 && g.edges[i][0]!=INF)	//该顶点到起点0有边
		{	
			path.push_back(0);				//路径中加入起点0
			pathlen=getpathlen(g,path);		//求路径长度			
        	printf("叶子i=%d:",i); disp(g,path);
			if (pathlen<minpathlen)
			{
				minpathlen=pathlen;
				minpath=path;
				printf("更小路径长度:minpathlen=%d\n",minpathlen);
			}
		}
	}
	else											//对于非叶子结点
	{	printf("调用i=%d:",i); disp(g,path);
		for (j=V.begin();j!=V.end();j++)
		{	tmpV=V;
			tmpj=*j;
			tmpV.remove(tmpj);
			pathlen=getpathlen(g,path);
			if (pathlen<minpathlen)					//剪支
				getpath(g,tmpj,tmpV,path);			//递归调用
			else
				printf("剪支\n");
		}
	}
}
void TSP(MGraph g)				//回溯法求从顶点0出发的TSP路径和长度
{	int i;
	LISTINT V,path;
	LISTINT::iterator j;
	for (i=1;i<g.n;i++)
		V.push_back(i);
	getpath(g,0,V,path);		//起点为0
	printf("TSP路径长度=%d\n",minpathlen);
	printf("最短路径:");		//输出最短路径
	j=minpath.begin();
	printf("%d",*j++);
	for (;j!=minpath.end();j++)
		printf("→%d",*j);
	printf("\n");
}
void main()
{
	MGraph g;
	int A[][MAXV]={						//一个带权有向图
		{0,8,5,36},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);		//创建图的邻接矩阵存储结构g
	printf("邻接矩阵:\n"); DispMat(g);	//输出邻接矩阵g
	printf("起点为0的解:\n");TSP(g);
}
