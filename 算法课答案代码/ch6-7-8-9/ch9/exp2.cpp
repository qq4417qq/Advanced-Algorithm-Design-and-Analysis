#include <stdio.h>
#include <string.h>
#define INF 32767				//定义∞
#define	MAXV 105			//最大顶点个数
int A[MAXV][MAXV];			//所有人之间传递的时间和最短路径长度
int n;							//人数
void Floyd()					//用Floyd算法求所有顶点最短路径长度
{	int i,j,k;
	for (k=0;k<n;k++)			//依次考察所有顶点
	{	for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
					A[i][j]=A[i][k]+A[k][j];//修改最短路径长度
	}
}
int Minp()						//求题目要求的人编号
{	int i,j,mm;
	int mini=-1,mint=INF;
	for (i=0;i<n;i++)
	{	mm=0;
		for (j=0;j<n;j++)			//求顶点i到其他顶点的最长最短路径长度
			mm=A[i][j]>mm?A[i][j]:mm;
		if (mm<mint)			//求最小的最长最短路径长度的顶点mini
		{	mint=mm;
			mini=i;
		}
	}
	if (mini==-1)				//图不连通的情况
		return -1;
	else
		return mini;
}
int main()
{	int i,j,t,m;
	int a,b;
	while (true)
	{	scanf("%d",&n);			//输入人数
		if (n<=0) break;			//以n小于等于0表示结束
		scanf("%d",&m);		//输入边数
		for (i=0;i<n;i++)			//初始化A
		{	for (j=0;j<n;j++)
				A[i][j]=INF;
			A[i][i]=0;
		}
		while (m--)
		{	scanf("%d%d%d",&a,&b,&t);
			A[a][b]=A[b][a]=t;
		}
		Floyd();					//调用Floyd算法
		printf("%d\n",Minp());
	}
    return 0;
}
