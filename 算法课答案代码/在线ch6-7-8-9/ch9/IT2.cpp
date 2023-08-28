#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INF 0x3f3f3f3f					//定义无穷大∞
int root[MAX];							//root[i]=j表示顶点i所在连通分量的根为顶点j
int find(int i)							//查找顶点i所在的连通分量编号
{
    return i==root[i] ? i:find(root[i]);
}
int main()
{	int A[MAX][MAX],S[MAX],dist[MAX];
	int i,j,a,b,cost;
    	int n,m;
    	while (scanf("%d %d",&n,&m)!=EOF)	//获取邻接矩阵A
    	{	for (i=0;i<n;i++)
        	{	root[i]=i;
            	S[i]=0;
        	}
        	for (i=0;i<n;i++)					//初始化邻接矩阵A
        	{	for (j=0;j<n;j++)
                A[i][j]=INF;
            A[i][i]=0;
        	}
		cost=1;						//边长度从1开始
        	for (i=0;i<m;i++)
        	{	scanf("%d %d",&a,&b);
            	int x=find(a);
            	int y=find(b);
            	if (x!=y)					//有效边
            	{	root[x]=y;				//y作为x的根
                	A[a][b]=A[b][a]=cost;		//无向图边是对称的
            	}
            	cost=cost*2 % 100000;		//cost增大两倍
        	}
    	}
	for (i=0;i<n;i++)						//Dijkstra算法
		dist[i]=A[0][i];
    	S[0]=1;
    	for (i=0;i<n;i++)
    	{	int min=INF,u;
        	for (j=0;j<n;j++)
        	{	if (S[j]==0 && dist[j]<INF)
            	{	u=j;
                	min=dist[j];
            	}
        	}
        	S[u]=1;
        	for (j=1;j<n;j++)
        	{	if (S[j]==0)
				if (A[u][j]<INF && dist[u]+A[u][j]<dist[j])
					dist[j]=dist[u]+A[u][j];
        	}
    	}
    	for (i=1;i<n;i++)						//输出结果
		if (dist[i]==INF)					//没有路径
			printf("-1\n");
		else							//存在路径
			printf("%d\n",dist[i] % 100000);
    	return 0;
}
