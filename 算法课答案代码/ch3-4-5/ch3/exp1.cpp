#include <stdio.h>
#include <stdlib.h>				//��������������Ŀ⺯��
#include <time.h>
#define MAX 100
//�����ʾ
int a[MAX];
int n;
int SUM(int low,int high)			//��a[low..high]������
{
	int sum=0;
	for (int i=low;i<=high;i++)
		sum+=a[i];
	return sum;
}
int solve(int low,int high)			//�ٶ�α�ҽ������
{
	if (low==high)					//ֻ��һ��Ӳ��
		return low;
	if (low==high-1)				//ֻ������Ӳ��
	{
		printf("  Ӳ��%d��Ӳ��%d����һ��: ",low,high);
		if (a[low]<a[high])
		{
			printf("ǰ��������\n");
			return low;
		}
		else
		{
			printf("����������\n");
			return high;
		}
	}
	int mid=(low+high)/2;
	int sum1,sum2;
	if ((high-low+1)%2==0)			//������Ӳ�Ҹ���Ϊż��
	{
		sum1=SUM(low, mid);
		sum2=SUM(mid+1,high);
		printf("  Ӳ��%d-%d��Ӳ��%d-%d����һ��: ",low,mid,mid+1,high);
	}
	else							//������Ӳ�Ҹ���Ϊ����
	{
		sum1=SUM(low,mid-1);
		sum2=SUM(mid+1,high);
		printf("  Ӳ��%d-%d��Ӳ��%d-%d����һ��: ",low,mid-1,mid+1,high);
	}
	if (sum1==sum2)
	{
		printf("����������ͬ\n");
		return mid;
	}
	else if(sum1<sum2)				//�ٱ���������
	{
		printf("ǰ��������\n");
		if ((high-low+1)%2==0)		//������Ӳ�Ҹ���Ϊż��
			return solve(low,mid);
		else						//������Ӳ�Ҹ���Ϊ����
			return solve(low,mid-1);
	}
	else							//�ٱ���������
	{
		printf("����������\n");
		return solve(mid+1,high);
	}
}
void main()
{
	int n=12;
	for (int i=0;i<n;i++)
		a[i]=2;					//����Ӳ������
	srand((unsigned)time(NULL));
	a[rand()%n]=1;				//�������һ���ٱ�����Ϊ1
	printf("������\n");
	printf("  Ӳ��%d�Ǽٱ�\n",solve(0,n-1));
}
