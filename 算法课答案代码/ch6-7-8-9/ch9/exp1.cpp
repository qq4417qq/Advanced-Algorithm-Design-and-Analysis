#include <stdio.h>
#define INF 0x3f3f3f3f			//定义∞
#define MAXV 101
int A[MAXV][MAXV];			//邻接矩阵
int n,m;
int s,t;
int dist[MAXV];
void BellmanFord(int v)			//贝尔曼-福特算法
{	int i,k,u;
	for (i=0;i<n;i++)
		dist[i]=A[v][i];		//对dist0[i]初始化
	for (k=1;k<n;k++)			//从dist0[u]递推出dist2[u], …,distn-1[u]循环n-2次
	{	for (u=0;u<n; u++)		//修改所有非顶点v的dist[]值
		{	if (u!=v)
			{	for (i=0;i<n;i++)	
				{	if (A[i][u]<INF && dist[u]>dist[i]+A[i][u])
						dist[u]=dist[i]+A[i][u];
				}
			}
		}
	}
}
int main()
{	int i,j;
	int a,b,l;
	scanf("%d%d",&n,&m);		//输入n、m
	for (i=0;i<n;i++)				//初始化邻接矩阵
		for (j=0;j<n;j++)
			if (i==j)
				A[i][j]=0;
			else
				A[i][j]=INF;
	for (i=0;i<m;i++)			//输入边
	{	scanf("%d%d%d",&a,&b,&l);
		A[a][b]=-l;
	}
	scanf("%d%d",&s,&t);		//输入s和t
	BellmanFord(s);				//采用BellmanFord算法求s出发的最短路径
	printf("%d\n",-dist[t]);		//输出结果
	return 1;
}
