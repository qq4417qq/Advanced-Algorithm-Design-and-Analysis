//求解0/1背包问题的算法
#include <stdio.h> 
#define MaxN 20				//最多物品数
#define MaxL 100				//最大限制重量
int knap(int f[MaxN][MaxL],int w[],int v[],int W,int n)	//动态规划法求0/1背包问题
{	int i,r;
	for (i=0;i<=n;i++)			//置边界条件f(i,0)=0
		f[i][0]=0;
	for (r=0;r<=W;r++)			//置边界条件f(0,r)=0
		f[0][r]=0;
	for (i=1;i<=n;i++)
	{	for (r=1;r<=W;r++)
			if (r<w[i])
				f[i][r]=f[i-1][r];
			else
			{	if (f[i-1][r]<f[i-1][r-w[i]]+v[i])
					f[i][r]=f[i-1][r-w[i]]+v[i];
				else
					f[i][r]=f[i-1][r];
			}
	}
	return f[n][W];			//返回总价值
}
int Traceback(int f[MaxN][MaxL],int w[],int x[],int W,int n) //回推求最优解
{	int i,r=W;
	int maxw=0; 				//存放最优解的总价值
	for (i=n;i>0;i--)			//循环判断每个物品
		if (f[i][r]!=f[i-1][r]) 
		{	x[i]=1;			//选取物品i
			maxw+=w[i];		//累计总重量
			r=r-w[i];
		}
		else
			x[i]=0;			//不选取物品i
	return maxw;				//返回总重量
}
void dispknap(int x[],int maxw,int maxv,int n)	//输出最佳背包方案
{	int i;
	printf("最佳背包方案是:\n");
	for (i=0;i<=n;i++)
		if (x[i]==1)
			printf("  选取第%d种物品\n",i);
	printf("总重量=%d,总价值=%d\n",maxw,maxv);
}
void main()
{	int f[MaxN][MaxL];
	int x[MaxN];
	int maxv; 						//存放最优解的总价值
	int maxw;						//存放最优解的总重量
	int n=5,W=10;					//5种物品,限制重量不超过10
	int w[MaxN]={0,2,2,6,5,4};		//下标0不用
	int v[MaxN]={0,6,3,5,4,6};		//下标0不用
	maxv=knap(f,w,v,W,n);
	maxw=Traceback(f,w,x,W,n);
	dispknap(x,maxw,maxv,n);
}
