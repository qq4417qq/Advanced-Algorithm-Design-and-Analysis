//30�֣�����
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 42								//����������
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
int n,n1=0,n2=0;
int A[MAXN],B[MAXN];
int solve1()					//���˫CPU��������
{	int i,j;
	int sum=0;					//���������񳤶Ⱥ�
	for(i=0;i<n1;i++)
		sum=sum+A[i];
	vector<int> dp(sum/2+1,0);	//��̬�滮����,����Ԫ�س�ʼ��Ϊ0
	for(i=0;i<n1;i++)
	{	for(j=sum/2; j>=A[i]; j--)
			dp[j]=max(dp[j], dp[j-A[i]]+A[i]);
	}
	int ans=max(dp[sum/2],sum-dp[sum/2]);
	return ans;
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
		if (m1<2*m2)
		{
			//printf("����%d->A\n",i);
			A[n1++]=m1;
		}
		else
		{
			//printf("����%d->B\n",i);
			B[n2++]=m2;
		}
	}
	printf("%d\n",solve());
	return 0;
}
