//分枝限界法求解TSP问题
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <vector>
#include <queue>
using namespace std;
//带调试结果的程序
struct Node					//搜索空间结点类
{
public:
     int no;				//当前顶点的编号
     int level;				//当前顶点的搜索层次
     vector<int> path;		//当前路径
	 int pathlen;			//当前路径长度
     Node(){};
     Node(int no1,int level1,vector<int> path1,int pathlen1)	//构造函数
	 {
		 no=no1;
		 level=level1;
		 path=path1;
		 pathlen=pathlen1;
	 };
     bool operator< (const Node &s) const	//重载运算符
     {
          return pathlen>s.pathlen;
     }
};
void disp(int pathlen,vector<int> path)	//输出路径及其长度
{
	int i;
	printf("路径长度=%d\t",pathlen);
	printf("路径:");
	printf("%d",path[0]);
	for (i=1;i<path.size();i++)
		printf("→%d",path[i]);
	printf("\n");
}
vector<int> minpath;				//存放最短路径
int minpathlen=INF;					//存放最短路径长度
void TSP(MGraph g)
{
	bool find;
	int i,j,no,level1;				//一组存放结点值的临时变量
	vector<int> path1,path;
	int pathlen1;
	priority_queue<Node> qu;		//定义优先队列qu
	path.push_back(0);
	Node firstNode(0,0,path,0);		//建立起点0对应的结点
	qu.push(firstNode);             //起点0进队
	Node node;
	while (!qu.empty())				//队不空循环
	{
		node=qu.top();				//取队头顶点node
		qu.pop();					//出队
		printf("出队顶点:%d\n",node.no);
		for (i=1;i<g.n;i++)			//从顶点1到n-1循环
		{
			if (g.edges[node.no][i]!=0 && g.edges[node.no][i]!=INF)	//当前顶点到顶点i有边
			{
				find=false;
				for (j=0;j<node.path.size();j++)		//判断顶点i是否在路径中
					if (i==node.path[j])				//路径里有顶点i
					{
						find=true;
						break;
					}
				if (!find)				//顶点i不在路径中
				{
					no=i;
					level1=node.level+1;
					path1=node.path;
					path1.push_back(i);
					pathlen1=node.pathlen+g.edges[node.no][i];
					printf("no=%d,level1=%d,",no,level1); disp(pathlen1,path1);
					if (level1>=g.n-1)
					{
						if (g.edges[no][0]!=0 && g.edges[no][0]!=INF)	//叶子顶点到起点0有边
						{
							pathlen1+=g.edges[no][0];			//计入从no到起点0的路径
							path1.push_back(0);					//路径中加入起点0
							printf("叶子结点: "); disp(pathlen1,path1);
							if (pathlen1<minpathlen)
							{
								minpathlen=pathlen1;
								minpath=path1;
							}
						}
					}
					else
					{
						if (pathlen1<minpathlen)
						{
							Node snode(no,level1,path1,pathlen1);
							qu.push(snode);
						}
					}
				}
			}
		}
	}
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
	CreateMat(g,A,n,e);					//创建图的邻接矩阵存储结构g
	printf("邻接矩阵:\n"); DispMat(g);	//输出邻接矩阵g
	printf("起点为0的解:\n");TSP(g);
	printf("最短路径及其长度:\n");
	disp(minpathlen,minpath);
}
