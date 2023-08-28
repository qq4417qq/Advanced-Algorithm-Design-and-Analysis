#include <stdio.h>
#include <string.h>
#define MAX 110
#define max(x,y) ((x)>(y)?(x):(y))
#define max3(x,y,z) max(max(x,y),z)			//求x,y,z中的最大值
int dp[MAX][MAX];
int matrix[5][5]={							//评分矩阵
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0},
};
char s[MAX],t[MAX];
int n,m;
char Char[5]={'A','C','G','T',' '};
int Value(char ch1, char ch2)					//通过矩阵求每一对字符(ch1,ch2)的分值
{	int r,c;
	for (int i=0; i<5; ++i)
	{	if (Char[i]==ch1)
			r=i;
		if (Char[i]==ch2)
			c=i;
	}
	return matrix[r][c];
}
int Similarity()								//求s和t的相似度
{	int i, j;
	dp[0][0]=0;
	for (i=1; i<=n; ++i)						//考虑第1列即a[i]与空字符
		dp[i][0]=dp[i-1][0]+Value(s[i-1],' ');
	for (j=1; j<=m; ++j)						//考虑第1行即空字符与b[j]
		dp[0][j]=dp[0][j-1]+Value(' ',t[j-1]);
	for (i=1; i<=n; ++i)
	{	for (j=1; j<=m; ++j)
			dp[i][j]=max3(
				dp[i-1][j]+Value(s[i-1],' '),	//插入t[j-1]为空字符
				dp[i][j-1]+Value (' ',t[j-1]),	//插入s[i-1]为空字符
				dp[i-1][j-1]+Value(s[i-1],t[j-1])	//不插入空字符
			);
	}
	return dp[n][m];
}
int main()
{	int T;
	int ans;
	while (scanf("%d",&T)!=EOF)
	{	while (T--)
		{	scanf ("%d%s",&n,s);
			scanf ("%d%s",&m,t);
			memset(dp,0,sizeof(dp));
			ans=Similarity();
			printf ("%d\n",ans);
		}
	}
	return 0;
}
