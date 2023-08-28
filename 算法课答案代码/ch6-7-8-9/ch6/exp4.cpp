#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
#define MAX 31
//问题表示
int n;
char b[MAX][MAX];
//求解结果表示
int bite;							//被野狗咬的次数
int visited[MAX][MAX];
int px,py,ax,ay;					//Magicpig和Amaze的位置
int H[4] = {0, 1, 0, -1};			//水平偏移量,下标对应方位号0～3
int V[4] = {-1, 0, 1, 0};			//垂直偏移量

struct NodeType						//队列结点类型
{
	int x,y;						//当前位置
	int length;						//走过的路径长度
	double lb;
	bool operator<(const NodeType &s) const	//重载<关系函数
	{
		return lb>s.lb;				//按lb越小越优先出队
	}
};
void bound(NodeType &e)				//计算分枝结点e的下界
{
	double d=sqrt((e.x-ax)*(e.x-ax)+(e.y-ay)*(e.y-ay));
	e.lb=e.length+d;
}
bool bfs()			//求解解救Amaze问题
{
	priority_queue<NodeType> qu;
	NodeType e,e1;
	e.x=px; e.y=py;
	e.length=0;
	bound(e);
	visited[px][py]=1;
	qu.push(e);
	while (!qu.empty())				//队列不空循环
	{
		e=qu.top(); qu.pop();
		if (e.x==ax && e.y==ay)		//找到Amaze
			return true;
		for (int i=0;i<4;i++)
		{
			e1.x=e.x+H[i];
			e1.y=e.y+V[i];
			if (e1.x<0 || e1.x>=n || e1.y<0 || e1.y>=n)
				continue;
			if (visited[e1.x][e1.y]==1)		//已经走过，跳出
				continue;
			if (b[e1.x][e1.y]=='k')			//为金刚，跳出
				continue;
			if (b[e1.x][e1.y]=='r' || b[e1.x][e1.y]=='a')	//遇到道路或者Amaze
			{
				e1.length=e.length+1;		//路径长度增加1
				bound(e1);
				visited[e1.x][e1.y]=1;
				qu.push(e1);
			}
			else if (b[e1.x][e1.y]=='d')		//遇到野狗
			{
				if (bite==0)					//被野狗咬1次的情况	
				{
					e1.length=e.length+1;		//路径长度增加1
					bound(e1);
					visited[e1.x][e1.y]=1;
					qu.push(e1);
					bite++;						//被野狗咬次数增加1
				}
			}
		}
	}
	return false;
}
int main()
{
	int t,i,j,x,y;
	scanf("%d",&t);					//输入t
	while (t--)
	{
		bite=0;
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);				//输入n
		for(i=0;i<n;i++)			//输入一个测试用例
			scanf("%s",b[i]);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{
				if(b[i][j]=='p')	//Magicpig的位置(px,py)
				{	px=i;
					py=j;
				}
				if (b[i][j]=='a')	//Amaze的位置(ax,ay)
				{
					ax=i;
					ay=j;
				}
			}
		if(bfs())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
