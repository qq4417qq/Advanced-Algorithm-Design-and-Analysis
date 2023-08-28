//求解整数拆分问题的算法
#include <stdio.h>
#define MAXN 500
int dpf(int n,int k)
{
	if (n==1 || k==1)
		return 1;
	else if (n<k)
		return dpf(n,n);
	else if (n==k)
		return dpf(n,k-1)+1;
	else
		return dpf(n,k-1)+dpf(n-k,k);
}

int dp[MAXN][MAXN];
void split(int n,int k)
{
	int i,j;
	for (i=1;i<=n;i++)
		for(j=1;j<=k;j++)
		{
			if (i==1 || j==1)
				dp[i][j]=1;
			else if (i<j)
				dp[i][j]=dp[i][i];
			else if (i==j)
				dp[i][j]=dp[i][j-1]+1;
			else if (i>j)
				dp[i][j]=dp[i][j-1]+dp[i-j][j];
		}
}
void main()
{
	int n=5,k=5;
	split(n,k);
	printf("  递归算法求解结果:%d\n",dp[n][k]);
	printf("非递归算法求解结果:%d\n",dpf(n,k));
}
