#include <stdio.h>
#define MAX 100
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int a[]={68,69,54,64,68,64,70,67,78,62,98,87};
int n=sizeof(a)/sizeof(a[0]);
//�������ʾ
int ans=0;
int dp[MAX];
void solve(int a[],int n)		//��dp
{	int i,j;
	for(i=0;i<n;i++)
	{	dp[i]=1;
		for(j=0;j<i;j++)
			if (a[i]<a[j])	//��������������г��ȵ�a[i]>a[j]��Ϊa[i]<a[j]
				dp[i]=max(dp[i],dp[j]+1);
	}
	ans=dp[0];
	for(i=1;i<n;i++)			//�����һ������dp[i]
		ans=max(ans,dp[i]);
}
void main()
{
	solve(a,n);
	printf("%d\n",ans);		//���4
}
