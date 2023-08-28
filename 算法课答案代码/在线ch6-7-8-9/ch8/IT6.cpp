#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 500001
#define MAXH 51
//�����ʾ
int n;
int height[MAXN];
//�������ʾ
int dp[2][MAXH];  
int sum;  
void solve()
{
	memset(dp,-1,sizeof(dp));
    dp[0][0]=0;  
    for(int i=1;i<=n;i++)					//ɨ������ש��
    {  
        for(int h=0;h<=sum;h++)				//ö�ٸ߶Ȳ�  
        {  
            dp[i&1][h]=dp[(i-1)&1][h];		//����ש��
            if(h+height[i]<=sum && dp[(i-1)&1][h+height[i]]>=0)  //���ڰ����ϣ�����ȥ��߶ȱ�ԭ���ߵİ�
                dp[i&1][h]=max(dp[i&1][h],dp[(i-1)&1][h+height[i]]+height[i]);  
            if(height[i]-h>=0 && dp[(i-1)&1][height[i]-h]>=0)		//���ڰ����ϣ�����ȥ��߶ȱ�ԭ���ߵĸ�
                dp[i&1][h]=max(dp[i&1][h],dp[(i-1)&1][height[i]-h]+height[i]-h);  
            if(h-height[i]>=0 && dp[(i-1)&1][h-height[i]]>=0)  //���ڸ�����
                dp[i&1][h]=max(dp[i&1][h],dp[(i-1)&1][h-height[i]]);  
        }  
    }  
}
int main()  
{  
    sum=0;  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&height[i]);  
        sum+=height[i];  
    }  
	solve();
	printf("%d\n",dp[n&1][0]==0? -1:dp[n&1][0]);  
    return 0;  
} 

