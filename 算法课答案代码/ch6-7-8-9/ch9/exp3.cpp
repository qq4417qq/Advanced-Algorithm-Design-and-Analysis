#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define N 101
#define INF 0x3f3f3f3f

//问题表示
int n,s,t;					//网络的顶点个数和边数
struct Edge					//边类型
{
	int from,to;			//一条边(from,to)
	int flow;				//边的流量
	int cap;				//边的容量
	int cost;				//边的单流量费用
};
vector<Edge> edges;			//存放网络中所有边
vector<int> G[N];			//邻接表，G[i][j]表示顶点i的第j条边在edges数组中的下标
//求解结果表示
int maxf=0;					//最大流量（这里没有使用，用于说明求最大流量的过程）
int mincost=0;				//最大流的最小费用

bool visited[N];
int pre[N],a[N],dist[N];
void Init()					//初始化
{
	for (int i=0; i<n; i++)	//删除顶点关联边
		G[i].clear();		
	edges.clear();				//删除所有边
}
void AddEdge(int from,int to,int cap,int cost)	//添加一条边
{
	Edge temp1 = {from,to,0,cap,cost};	//前向边，初始流用为0
	Edge temp2 = {to,from,0,0,-cost };	//反向边，初始流用为0
	edges.push_back(temp1);				//添加前向边
	G[from].push_back(edges.size()-1);	//前向边的位置
	edges.push_back(temp2);				//添加反向边
	G[to].push_back(edges.size()-1);	//反向边的位置
}
bool SPFA()								//SPFA算法求cost最小的路径
{
	for (int i=0; i<n;i++)				//初始化dist设置
		dist[i]=INF;
	dist[s]=0;
	memset(visited,0,sizeof(visited));	
	memset(pre, -1, sizeof(pre));
	pre[s]=-1;							//起点的前驱为-1
	queue<int> qu;						//定义一个队列
	qu.push(s);
	visited[s]=1;
	a[s]=INF;
	while (!qu.empty())					//队列不空循环
	{
		int u=qu.front(); qu.pop();
		visited[u]=0;
		for (int i=0; i<G[u].size();i++)				//查找顶点u的所有关联边
		{
			Edge &e=edges[G[u][i]];						//关联边e=(u,G[u][i])
			if (e.cap>e.flow && dist[e.to]>dist[u]+e.cost)	//松弛
			{
				dist[e.to]=dist[u]+e.cost;
				pre[e.to]=G[u][i];						//顶点e.to的前驱顶点为G[u][i]
				a[e.to]=min(a[u], e.cap-e.flow);
				if (!visited[e.to])						//e.to不在队列中
				{
					qu.push(e.to);						//将e.to进队
					visited[e.to]=1;
				}
			}
 		}
	}
	if (dist[t]==INF)					//找不到终点，返回false
		return false;
	maxf+=a[t];							//累计最大流量
	mincost += dist[t]*a[t];			//累计最小费用
	for (int j=t; j!=s; j=edges[pre[j]].from)	//调整增广路径中流
	{
		edges[pre[j]].flow += a[t];		//前向边增加a[t]
		edges[pre[j]+1].flow -= a[t];	//后向边减少a[t]
	}
	return true;				//找到终点，返回true
}
void MinCost()					//求出到t的最小费用
{
	while (SPFA());				//SPFA算法返回真继续
}

int main()
{
	n=6;						//顶点个数
	s=0; t=n-1;
	Init();
	AddEdge(0,1,3,1);
	AddEdge(0,2,3,1);
	AddEdge(1,3,2,1);
	AddEdge(1,4,3,1);
	AddEdge(2,3,2,1);
	AddEdge(4,5,3,1);
	AddEdge(3,5,3,1);
	MinCost();
	printf("求解结果\n");
	cout << "   最大网络流: " << maxf << endl;
	cout << "   最小费用: " << mincost << endl;
	return 0;
}
