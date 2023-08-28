#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 6005
//问题表示 
int n;  
int father[MAXN];		//i的直接主管为father[i]
int dp[MAXN][2];		//dp[i][0]=0表示不去，dp[i][1]=1表示去了
bool visited[MAXN];  
void tree_dp(int i)		//在树中后根遍历求dp
{
	visited[i]=1;
	for(int j=1; j<=n; j++)
	{
		if(visited[j]==0 && father[j]==i)		//员工j是员工i的下属,并且没有考虑过  
         {  
             tree_dp(j);						//递归调用孩子结点，从叶子结点开始dp  
             dp[i][1] += dp[j][0];				//主管i来,下属j不来  
             dp[i][0] += max(dp[j][1],dp[j][0]);//主管i不来，下属j来或者不来  
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
		for(int i=1; i<=n; i++)		//获取员工i的快乐指数
			scanf("%d",&dp[i][1]);
		root;					//记录根结点
		while (scanf("%d%d",&c,&f),c||f)
		{
			father[c] = f;		//c的直接主管为f
			root=f;
		}
		while(father[root])		//查找到根结点
			root=father[root];
		tree_dp(root);
		int ans=max(dp[root][0],dp[root][1]);
		printf("%d\n",ans);
	}
	return 0;
}
