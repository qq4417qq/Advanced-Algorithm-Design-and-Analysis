#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 6005
//�����ʾ 
int n;  
int father[MAXN];		//i��ֱ������Ϊfather[i]
int dp[MAXN][2];		//dp[i][0]=0��ʾ��ȥ��dp[i][1]=1��ʾȥ��
bool visited[MAXN];  
void tree_dp(int i)		//�����к��������dp
{
	visited[i]=1;
	for(int j=1; j<=n; j++)
	{
		if(visited[j]==0 && father[j]==i)		//Ա��j��Ա��i������,����û�п��ǹ�  
         {  
             tree_dp(j);						//�ݹ���ú��ӽ�㣬��Ҷ�ӽ�㿪ʼdp  
             dp[i][1] += dp[j][0];				//����i��,����j����  
             dp[i][0] += max(dp[j][1],dp[j][0]);//����i����������j�����߲���  
         }  
     }  
 }  
int main()  
{
	int f,c,root;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(father,0,sizeof(father));
		memset(visited,0,sizeof(visited));
		for(int i=1; i<=n; i++)		//��ȡԱ��i�Ŀ���ָ��
			scanf("%d",&dp[i][1]);
		root;					//��¼�����
		while (scanf("%d%d",&c,&f),c||f)
		{
			father[c] = f;		//c��ֱ������Ϊf
			root=f;
		}
		while(father[root])		//���ҵ������
			root=father[root];
		tree_dp(root);
		int ans=max(dp[root][0],dp[root][1]);
		printf("%d\n",ans);
	}
	return 0;
}
