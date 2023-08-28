//求最小费用最大流算法
#include <stdio.h>
#define MAXV 10
#define INF 32767
int s,t,n;						//全局变量,分别表示起点、终点和顶点个数
void disp(int a[][MAXV])		//输出一个矩阵
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (a[i][j]!=INF)
				printf("%4d",a[i][j]);
			else
				printf("%4s","∞");
			printf("\n");
	}
}
void Createw(int c[][MAXV],int f[][MAXV],int b[][MAXV],int w[][MAXV])	//构造一个赋权图w
{
	int i,j;
	for (i=0;i<n;i++)			//w数组元素初始化
		for (j=0;j<n;j++)
			w[i][j]=INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			if (c[i][j]!=0 && c[i][j]<INF)
			{
				if (f[i][j]<c[i][j])
					w[i][j]=b[i][j];
				else if (f[i][j]==c[i][j])
					w[i][j]=INF;
				if (f[i][j]>0)
					w[j][i]=-b[i][j];
				else if (f[i][j]==0)
					w[j][i]=INF;
			}
			else if (i==j)
				w[i][j]=0;
		}
}
bool BellmanFord(int w[][MAXV],int v,int path[])	//对w求从s到t的最短路径path
{
	int i,k,u;
	int dist[MAXV];
	for (i=0;i<n;i++)
	{
		dist[i]=w[v][i];			//对dist(1)[i]初始化
		if (i!=v && dist[i]<INF) 
			path[i]=v;				//对path(1)[i]初始化
		else 
			path[i]=-1;
	}
	for (k=2;k<n;k++)
	{
		for (u=0;u<n; u++)			//修改每个顶点的dist[u]和path[u]
		{
			if (u!=v)
			{
				for (i=0;i<n;i++)	//考虑其他每个顶点
				{
					if (w[i][u]<INF && dist[u]>dist[i]+w[i][u])
					{
						dist[u]=dist[i]+w[i][u];
						path[u]=i;
					}
				}
			}
		}
	}
	if (path[t]==-1)
		return false;	//当没有从起点到终点的最短路径,返回false
	else
		return true;	//当存在从起点到终点的最短路径,返回true
}
int Getarg(int c[][MAXV],int f[][MAXV],int path[])	//求path表示的调整流量min
{
	int i,j,min=INF;
	printf("path:");
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
	j=t,i=path[j];
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//前向边
		{
			printf("%d  ",c[i][j]-f[i][j]);
			if (c[i][j]-f[i][j]<min)
				min=c[i][j]-f[i][j];
		}
		if (c[j][i]>0 && c[j][i]<min)		//后向边
		{
			printf("%d ",f[i][j]);
			if (f[i][j]<min)
				min=f[i][j];
		}
		if (i==-1) break;					//当到达起点时退出循环
		j=i;
		i=path[j];
	}
	//printf("求调整量 MIN=%d\n",min);
	return min;
}
void argument(int c[][MAXV],int f[][MAXV],int path[],int min)	//根据调整流量min对增广链进行调整
{
	int i,j;
	j=t,i=path[j];
	printf("调整流量\n");
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//前向边
		{
			f[i][j]+=min;
			printf("f[%d][%d]调整为%d\n",i,j,f[i][j]);
		}
		if (c[j][i]>0 && c[j][i]<min)		//后向边
		{
			f[j][i]-=min;
			printf("f[%d][%d]调整为%d\n",j,i,f[j][i]);
		}
		if (i==-1) break;					//当到达起点时退出循环
		j=i;
		i=path[j];
	}
}
void Minmaxflow(int c[][MAXV],int b[][MAXV],int f[][MAXV])	//求最小费用最大流f
{
	int k=0;
	int path[MAXV],min;
	int w[MAXV][MAXV];	//赋权有向图
	while (true)
	{
		printf("k=%d\n",k++);
		Createw(c,f,b,w);
		printf("w:\n"); disp(w);
		if (BellmanFord(w,s,path))
		{
			min=Getarg(c,f,path);
			printf("min=%d\n",min);
			argument(c,f,path,min);
			printf("f:\n");	disp(f);
		}
		else break;
	}
}
void main()
{
	n=6; s=0; t=n-1;
	int f[][MAXV]={				//置一个零网络流
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}};
	int c[][MAXV]={				//一个网络流容量
		{0,4,5,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,2,INF},
		{INF,INF,INF,0,INF,5},
		{INF,1,INF,3,0,2},
		{INF,INF,INF,INF,INF,0}};
	int b[][MAXV]={				//一个网络流单位流量费用
		{0,1,3,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,4,INF},
		{INF,INF,INF,0,INF,2},
		{INF,2,INF,1,0,4},
		{INF,INF,INF,INF,INF,0}};
	Minmaxflow(c,b,f);
	printf("最小费用最大网络流:\n");
	disp(f);
}
