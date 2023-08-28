#include <iostream>    
#include <queue>    
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define N 101    
#define M 101 
#define INF 0x3f3f3f3f    
//问题表示
int m,n,s,t;    
char map[M][N];				//存放网格地图    
struct man					//记录小人的坐标    
{    
    int x,y;    
} man[N];    
struct house				//记录房子的坐标    
{    
    int x,y;    
} house[N];
struct Edge					//边类型
{	int from,to;				//一条边(from,to)
	int flow;					//边的流量
	int cap;					//边的容量
	int cost;					//边的单流量费用
};
vector<Edge> edges;				//存放网络中所有边
vector<int> G[N];				//邻接表，G[i][j]表示顶点i的第j条边在edges数组中的下标
//求解结果表示
int mincost;					//最大流的最小费用
bool visited[N];
int pre[N],a[N],dist[N];
void Init()						//初始化
{
	for (int i=0; i<n; i++)		//删除顶点关联边
		G[i].clear();
	edges.clear();				//删除所有边
}
void AddEdge(int from,int to,int cap,int cost)	//添加一条边
{	Edge temp1 = {from,to,0,cap,cost};	//前向边，初始流用为0
	Edge temp2 = {to,from,0,0,-cost };	//反向边，初始流用为0
	edges.push_back(temp1);				//添加前向边
	G[from].push_back(edges.size()-1);	//前向边的位置
	edges.push_back(temp2);				//添加反向边
	G[to].push_back(edges.size()-1);	//反向边的位置
}
bool SPFA()								//SPFA算法求cost最小的路径
{	for (int i=0; i<=t;i++)				//初始化dist设置
		dist[i]=INF;
	dist[s]=0;
	memset(visited,0,sizeof(visited));
	memset(pre, -1, sizeof(pre));
	pre[s]=-1;						//起点的前驱为-1
	queue<int> qu;					//定义一个队列
	qu.push(s);
	visited[s]=1;
	a[s]=INF;
	while (!qu.empty())				//队列不空循环
	{	int u=qu.front(); qu.pop();
		visited[u]=0;
		for (int i=0; i<G[u].size();i++)		//查找顶点u的所有关联边
		{	Edge &e=edges[G[u][i]];			//关联边e=(u,G[u][i])
			if (e.cap>e.flow && dist[e.to]>dist[u]+e.cost)	//松弛
			{	dist[e.to]=dist[u]+e.cost;
				pre[e.to]=G[u][i];			//顶点e.to的前驱顶点为G[u][i]
				a[e.to]=min(a[u], e.cap-e.flow);
				if (!visited[e.to])		//e.to不在队列中
				{	qu.push(e.to);		//将e.to进队
					visited[e.to]=1;
				}
			}
 		}
	}
	if (dist[t]==INF)						//找不到终点，返回false
		return false;
	mincost += dist[t]*a[t];				//累计最小费用
	for (int j=t; j!=s; j=edges[pre[j]].from)	//调整增广路径中流
	{
		edges[pre[j]].flow += a[t];			//前向边增加a[t]
		edges[pre[j]+1].flow -= a[t];		//后向边减少a[t]
	}
	return true;							//找到终点，返回true
}
void MinCost()							//求出s到t的最小费用
{
	while (SPFA());						//SPFA算法返回真继续
}
void CreateG()						//创建网络G
{    
    int mcase=0,hcase=0;			//记录有多少个小人和房子    
    int i,j;    
    for(i=1; i<=m; i++)
    {    
        for(j=1; j<=n; j++)
        {    
            cin >> map[i][j];    
            if(map[i][j]=='m')		//记录小人的坐标
            {    
                mcase++;
                man[mcase].x=i;    
                man[mcase].y=j;    
            }    
            if(map[i][j]=='H')		//记录房子的坐标
            {    
                hcase++;    
                house[hcase].x=i;    
                house[hcase].y=j;    
            }    
        }    
    }
    s=0;
    t=mcase+hcase+1;					//加入起点0和终点t构成网络流结构
    for(i=1; i<=mcase; i++)				//处理所有的小人
    {    
		AddEdge(0,i,1,0);				//起点到各个小人之间的的容量为1,费用为0
        for(j=1; j<=hcase; j++)		//处理所有的房子
        {    
            int w=abs(house[j].x-man[i].x)+abs(house[j].y-man[i].y);//计算小人到每个房子之间的距离
			AddEdge(i,mcase+j,1,w);		//小人和房子之间的容量为1,费用取为w
		}    
    }
	for (j=1;j<=hcase; j++)
		AddEdge(mcase+j,t,1,0);			//各个房子到终点之间的容量为1,费用取为0
}
int main()
{    
    while(true)
	{
		cin >> m >> n;					//输入m,n
		if (m==0 || n==0) break;
		mincost=0;						//初始化最小费用为0
		Init();
		CreateG();
        MinCost();						//计算从起点0到终点t之间的最大流最小费用    
        cout << mincost << endl;    
    }    
    return 0;
}