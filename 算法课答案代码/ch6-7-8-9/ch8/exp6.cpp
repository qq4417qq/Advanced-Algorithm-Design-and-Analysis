#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 101					//最多的元素个数
#define MAXS 1000					//最大的集合元素差
//问题表示
int n=5;
int a[MAXN]={0,1,2,3,4,5};			//下标0不用
int dp[MAXN][MAXS];
int solve()
{ 
   int i,j,sum=0;
   memset(dp,-1,sizeof(dp));
   for (i=1;i<=n;i++)
	   sum+=a[i];
   dp[0][0]=0;
   for(i=1;i<=n;i++)					//扫描所有元素
   {
	   for(j=0;j<=sum;j++)				//枚举绝对值差
	   {
		   dp[i][j]=dp[i-1][j];			//不放a[i]
		   if(j+a[i]<=sum && dp[i-1][j+a[i]]>=0)
			   //添加到A中，添加后SUM(A)<SUM(B)
			   dp[i][j]=max(dp[i][j],dp[i-1][j+a[i]]+a[i]);  
		   if(a[i]-j>=0 && dp[i-1][a[i]-j]>=0)
			   //添加到A中，添加后SUM(A)>SUM(B)
			   dp[i][j]=max(dp[i][j],dp[i-1][a[i]-j]+a[i]-j);  
		   if(j-a[i]>=0 && dp[i-1][j-a[i]]>=0)
			   //添加到B中
			   dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]); 
        }
   }
   return dp[n][0];
}
void main()
{
	int ans=solve();
	if (ans==0)
		printf("没有解\n");
	else
		printf("SUM(A)=%d\n",ans);	//输出:SUM(A)=7
}
