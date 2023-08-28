#include <stdio.h>
#include <vector>
using namespace std;
#define MAXM 100
#define MAXN 100
//�����ʾ
int a[MAXM][MAXN]={{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
int m=4,n=4;
//�������ʾ
int ans;						//��С·������
int dp[MAXM][MAXN];
int pre[MAXM][MAXN];
void Minpath()					//����С��·��ans
{	int i,j;
	dp[0][0]=a[0][0];
	for(i=1;i<m;i++)				//�����һ�е�ֵ
	{	dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=0;			//��ֱ·��
	}
	for(j=1;j<n;j++)				//�����һ�е�ֵ
	{	dp[0][j]=dp[0][j-1]+a[0][j];
		pre[0][j]=1;			//ˮƽ·��
	}
	for(i=1;i<m;i++)				//��������dpֵ
		for(j=1;j<n;j++)
		{	if (dp[i][j-1]<dp[i-1][j])
			{	dp[i][j]=dp[i][j-1]+a[i][j];
				pre[i][j]=1;
			}
			else
			{	dp[i][j]=dp[i-1][j]+a[i][j];
				pre[i][j]=0;
			}
		}
	ans=dp[m-1][n-1];
}
void Disppath()					//�����С��·��
{	int i=m-1,j=n-1;
	vector<int> path;				//��ŷ�����С·��
	vector<int>::reverse_iterator it;
	while (true)
	{	path.push_back(a[i][j]);
		if (i==0 && j==0) break;
		if (pre[i][j]==1)	j--;		//ͬ��
		else i--;				//ͬ��
	}
	printf("    ���·��: ");
	for (it=path.rbegin();it!=path.rend();++it)
		printf("%d ",*it);		//���������������·��
	printf("\n    ���·����:%d\n",ans);
}
void main()
{
	Minpath();					//����С·����
	printf("�����\n");
	Disppath();					//�������С·������С·����
}
