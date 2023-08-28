#include <stdio.h>
//问题表示
int n;
int solve(int num1,int num2)
{
	int ans=0;
	int sum;
	for(int j=num1;j<=num2;j++)	//执行num2-num1+1次循环
	{
		sum=0;
		for(int k=1;k<j;k++)
		{
			if(j%k==0)			//累计j的因子
				sum+=k;
		}
		if (sum==j)
			ans++;				//如果是完数，统计其个数
	}
	return ans;
}
int main()
{
	int num1,num2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)			//执行n次循环
	{
		scanf("%d%d",&num1,&num2);	//输入两个整数
		printf("%d\n",solve(num1,num2));
	}
	return 0;
}
