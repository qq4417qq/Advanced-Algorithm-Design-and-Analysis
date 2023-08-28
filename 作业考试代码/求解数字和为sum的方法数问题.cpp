#include <stdio.h>
#define MAXN 1001
#define MAXS 1001
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n,sum;
int a[MAXN];
long dp[MAXN][MAXS];
long solve()
{
	int i,j;
	//��ʼ��dp,��ǰi����ɺ�Ϊ0�ķ�����ֻ��1�֣�����ʲô����ȡ����Ϊ0��
    for (i=0; i<n ;i++)
        dp[i][0] = 1;
	//��0��Ԫ�ز������1~sum
    for (j=1; j<sum ;j++)
        dp[0][j]=0;
	for(i=1; i<=n; i++)
		for(j=0;j<=sum;j++)
		{
			if(a[i]<=j)
				dp[i][j]=max(dp[i-1][j-a[i]]+dp[i-1][j],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
       return dp[n][sum];
}
int main()
{
	scanf("%d%d",&n,&sum);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%ld\n",solve());
	return 0;
}
