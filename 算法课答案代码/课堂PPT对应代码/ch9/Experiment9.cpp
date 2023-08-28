//上机实验题9
#include<stdio.h>
#define INF 32767
#define MAXV 20
#define MAXL 20
typedef struct
{	int no;					//顶点编号
	char data[MAXL];			//顶点其他信息
} VertexType;					//顶点类型
typedef struct
{	int edges[MAXV][MAXV];		//邻接矩阵的边数组
	int n,e;					//顶点数，边数
	VertexType vexs[MAXV];		//存放顶点信息
} MGraph;						//完整的图邻接矩阵类型
void CreateMat(MGraph &g,int A[][MAXV],int n,int e)	//建立图的邻接矩阵
{	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MGraph g)						//输出图的邻接矩阵
{	int i,j;
	printf("  n=%d,e=%d\n",g.n,g.e);
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%4s","∞");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
int color[MAXV];						//顶点着色数组
bool ok(MGraph g,int k)					//判断顶点k的着色是否发生冲突
{	int i;
	for (i=0;i<k;i++)
		if (g.edges[k][i]==1 && color[i]==color[k])
			return false;
	return true;
}
void graphcolor(MGraph g,int m)			//非递归回溯法求解m着色问题
{	int i,k,count=0;
	for (i=0;i<g.n;i++)
		color[i]=0;					//初始化为0表示顶点i没有着色
	k=0;								//从顶点0开始着色
	while (k>=0)
	{	color[k]=color[k]+1;
		while (color[k]<=m)
			if (ok(g,k)) break;
			else color[k]=color[k]+1;	//搜索下一个颜色
		if (color[k]<=m && k==g.n-1)	//输出一个解
		{	printf(" 方案%d: ",++count);
			for (i=0;i<g.n;i++)
				printf("%d ",color[i]);
			printf("\n");
		}
		else if (color[k]<=m && k<g.n-1)
			k++;						//处理下一个顶点
		else
		{	color[k]=0;
			k--;						//回溯到前一个顶点
		}
	}
}
void main()
{	int m=3;
	MGraph g;
	int A[][MAXV]={					//一个无向连通图
		{0,1,0,0,0},
		{1,0,0,0,0},
		{0,1,0,0,1},
		{0,1,0,0,1},
		{0,0,1,1,0}};
	int n=5,e=5;
	CreateMat(g,A,n,e);				//创建图的邻接矩阵存储结构g
	printf("邻接矩阵:\n"); DispMat(g);	//输出邻接矩阵g
	printf("3着色问题的所有解:\n");
	graphcolor(g,m);
}
