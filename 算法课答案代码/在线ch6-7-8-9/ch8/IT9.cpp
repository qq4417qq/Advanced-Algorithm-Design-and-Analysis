#include <stdio.h>
#define MAX 105
//问题表示
int k;
int n,p;
//求解结果表示    
long dp[MAX][MAX][2];
void solve()
{
	dp[1][0][0]=dp[1][0][1]=1;
	for(int i=2;i<=MAX;i++)
	{
		dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
		dp[i][0][1] = dp[i-1][0][0];
		for(int j=1;j<i;j++)
		{
			dp[i][j][0] = dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j-1][1];
		}
	}  
}
int main()  
{
	scanf("%d",&k);
	solve();
	while(k--)
	{
		scanf("%d%d",&n,&p);  
		printf("%lld\n",dp[n][p][0]+dp[n][p][1]);
	}
	return 0;  
 }  
