//30分，错误
#include <stdio.h>
#include <string.h>
#define MAXN 42								//最多的任务数
#define SUM 402								//最多的SUM
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
//问题表示
int n,n1=0,n2=0;
int A[MAXN][2],B[MAXN];
//dp[i][r]:最大时间为i，已经使用GPU个数为r的处理时间
//dp[i][r]=0
//dp[i][r]=max{dp[i][r],min(dp[j][r])}
int solve1()					//求解双CPU处理问题
{
	int i,j;
	int sum=0;					//求所有任务长度和
	for(i=0;i<n1;i++)
		sum=sum+max(A[i][0],A[i][1]);
	int dp[SUM/2][2];			//动态规划数组
	memset(dp,0,sizeof(dp));	//所有元素初始化为0
	for(i=0;i<n1;i++)
	{
		for(j=sum/2; j>=min(A[i][0],A[i][1]); j--)
		{
			dp[j][0]=max(dp[j][0],dp[j-A[i][0]][0]+A[i][0]);//已使用GPU为0个，A[i]选择CPU->已使用GPU为0个

			int m1=max(dp[j][0],dp[j-A[i][1]][0]+A[i][1]);	//已使用GPU为0个，A[i]选择CPU+GPU->已使用GPU为1个
			int m2=max(dp[j][1],dp[j-A[i][0]][0]+A[i][0]);	//已使用GPU为1个，A[i]选择CPU->已使用GPU为1个
			int m=max(m1,m2);
			dp[j][1]=max(dp[j][1],m);
		}
	}
	int ans1=max(dp[sum/2][0],sum-dp[sum/2][0]);
	int ans2=max(dp[sum/2][1],sum-dp[sum/2][1]);
	printf("ans=%d\n",max(ans1,ans2));
	return max(ans1,ans2);
}
int solve2()
{
	int sum=0;
	for (int i=0;i<n2;i++)
		sum+=B[i];
	return sum;
}
int solve()
{
	return solve1()+solve2();
}
int main()
{
	int a,b,c,d;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{ 
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int m1=min(a,c);
		int m2=min(b,d);
		if (m1<=m2)
		{
			printf("i=%d->A\n",i);
			A[n1][0]=a;			//CPU
			A[n1++][1]=c;		//CPU+GPU
		}
		else
		{
			printf("i=%d->B\n",i);
			B[n2++]=m2;
		}
		for (int i1=0;i1<n1;i1++)
			printf("i1=%d 0: %d 1:%d\n",i1,A[i1][0],A[i1][1]);
	}
	printf("n1=%d,n2=%d\n",n1,n2);
	printf("%d\n",solve());
	return 0;
}
