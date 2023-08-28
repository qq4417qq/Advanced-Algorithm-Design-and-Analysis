#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 101
#define MAXE (MAX*(MAX-1)/2)
//问题表示
int n;								//顶点个数
int m;								//边数
struct Edge							//边类型
{	int a;							//边的起点
	int b;							//边的终点
	int d;							//边长度
};
Edge road[MAXE];
int tree[MAX];						//并查集
int find_root(int a)					//在并查集中查找a的根
{
	if (tree[a]==-1)
		return a;					//a为根,返回a
    int tmp=find_root(tree[a]);
   	tree[a]=tmp;					//a不是根,让它指向根tmp
    return tmp;
}
bool cmp(Edge a,Edge b)				//排序比较函数
{    if (a.d<b.d) return true;
    return false;						//用于按边长度递增排序
}
int solve()							//采用Kruskal算法求解
{	sort(road,road+m,cmp);			//按边长度递增排序
	int ans=0;						//存放最低成本
	for(int i=0;i<m;i++)
	{	//第i条边的两个顶点是a、b
		int ra=find_root(road[i].a);		//查找顶点a的根
		int rb=find_root(road[i].b);		//查找顶点b的根
		if(ra!=rb)					//若它们的根不同,取该边的成本
		{	tree[rb]=ra;
			ans+=road[i].d;
		}
	}
	return ans;
}  
int main()
{	int f;
    	while(scanf("%d",&n)!=EOF && n!=0)
	{	m=n*(n-1)/2;
        	for(int i=0;i<=n;i++)			//初始化并查集
            	tree[i]=-1;
        	for(int j=0;j<m;j++)			//输入
		{	scanf("%d%d%d%d",&road[j].a,&road[j].b,&road[j].d,&f);
			if(f==1) road[j].d=0;		//已建道路成本为0
        	}
		printf("%d\n",solve());
	}
    	return 0;
}
