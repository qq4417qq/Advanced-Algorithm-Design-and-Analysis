#include <stdio.h>
//�����ʾ
int n;
int solve(int num1,int num2)
{
	int ans=0;
	int sum;
	for(int j=num1;j<=num2;j++)	//ִ��num2-num1+1��ѭ��
	{
		sum=0;
		for(int k=1;k<j;k++)
		{
			if(j%k==0)			//�ۼ�j������
				sum+=k;
		}
		if (sum==j)
			ans++;				//�����������ͳ�������
	}
	return ans;
}
int main()
{
	int num1,num2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)			//ִ��n��ѭ��
	{
		scanf("%d%d",&num1,&num2);	//������������
		printf("%d\n",solve(num1,num2));
	}
	return 0;
}
