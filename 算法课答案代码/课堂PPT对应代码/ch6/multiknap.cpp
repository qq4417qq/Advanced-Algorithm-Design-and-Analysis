//求解完全背包问题的算法
#include <stdio.h>
#define MaxN 20				//最多物品数
#define MaxW 100			//最大限制重量
int f[MaxN+1][MaxW+1],fk[MaxN+1][MaxW+1];
int n,W;
int w[MaxN],v[MaxN];
int solve()					//求解多重背包问题
{
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<=W;j++)
			for (k=0;k*w[i]<=j;k++)
			{
				if (f[i+1][j]<f[i][j-k*w[i]]+k*v[i])
				{
					f[i+1][j]=f[i][j-k*w[i]]+k*v[i];
					fk[i][j]=k;		//物品i取k件
				}									
			}
	}
	for (i=0;i<=W;i++)
		printf("%5d",i);
	printf("\n");
	for (i=0;i<=n;i++)
	{
		printf("%d  ",i);
		for (j=0;j<=W;j++)
			printf("%d[%d] ",f[i][j],fk[i][j]);
		printf("\n");
	}
	return f[n][W];
}
int solve1()				//求解多重背包问题
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<=W;j++)
		{
			if (j<w[i])
				f[i+1][j]=f[i][j];
			else
			{
				if (f[i][j]>f[i+1][j-w[i]]+v[i])
					f[i+1][j]=f[i][j];
				else
					f[i+1][j]=f[i+1][j-w[i]]+v[i];
			}
		}
	return f[n][W];
}
void Traceback()	//回推求最优解
{
	int i=n-1,j=W;
	while (i>=0)
	{
		printf("物品%d:%d件 ",i,fk[i][j]);
		j-=fk[i][j]*w[i];
		i--;
	}
	printf("\n");
}
void main()
{
	w[0]=3; w[1]=4; w[2]=2;
	v[0]=4; v[1]=5; v[2]=3;
	n=3; W=7;
	printf("方法1最优解:\n");
	printf("  总价值=%d\n",solve());
	printf("  方案:");Traceback();
	printf("方法2最优解:\n");
	printf("  总价值=%d\n",solve1());
}
