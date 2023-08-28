#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 101					//����Ԫ�ظ���
#define MAXS 1000					//���ļ���Ԫ�ز�
//�����ʾ
int n=5;
int a[MAXN]={0,1,2,3,4,5};			//�±�0����
int dp[MAXN][MAXS];
int solve()
{ 
   int i,j,sum=0;
   memset(dp,-1,sizeof(dp));
   for (i=1;i<=n;i++)
	   sum+=a[i];
   dp[0][0]=0;
   for(i=1;i<=n;i++)					//ɨ������Ԫ��
   {
	   for(j=0;j<=sum;j++)				//ö�پ���ֵ��
	   {
		   dp[i][j]=dp[i-1][j];			//����a[i]
		   if(j+a[i]<=sum && dp[i-1][j+a[i]]>=0)
			   //��ӵ�A�У���Ӻ�SUM(A)<SUM(B)
			   dp[i][j]=max(dp[i][j],dp[i-1][j+a[i]]+a[i]);  
		   if(a[i]-j>=0 && dp[i-1][a[i]-j]>=0)
			   //��ӵ�A�У���Ӻ�SUM(A)>SUM(B)
			   dp[i][j]=max(dp[i][j],dp[i-1][a[i]-j]+a[i]-j);  
		   if(j-a[i]>=0 && dp[i-1][j-a[i]]>=0)
			   //��ӵ�B��
			   dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]); 
        }
   }
   return dp[n][0];
}
void main()
{
	int ans=solve();
	if (ans==0)
		printf("û�н�\n");
	else
		printf("SUM(A)=%d\n",ans);	//���:SUM(A)=7
}
