#include <stdio.h>
#include <stdlib.h>				//��������������Ŀ⺯��
#include <time.h>
#define MAX 102
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
	int sum1,sum2;
	if (low==high)					//ֻ��һ��Ӳ��
		return low;
	if (low==high-1)				//ֻ������Ӳ��
	{
		printf("  Ӳ��%d��Ӳ��%d����һ��: ",low,high);
		if (a[low]<a[high])
		{
			printf("Ӳ��%d������\n",low);
			return low;
		}
		else
		{
			printf("Ӳ��%d������\n",high);
			return high;
		}
	}
	else if (low==high-2)			//ֻ��3��Ӳ��
	{
		printf("  Ӳ��%d��Ӳ��%d����һ��: ",low,low+1);
		sum1=a[low];
		sum2=a[low+1];
		if (sum1<=sum2)
		{
			printf("Ӳ��%d������\n",low);
			return low;
		}
		else if (sum1>sum2)
		{
			printf("Ӳ��%d������\n",low+1);
			return low+1;
		}
		else
		{
			printf("����������ͬ\n");
			return low+2;
		}
	}
	int len=(high-low+1)/3;			//ÿ������ĳ���
	int mid1=low+len-1;				//����1:a[low..mid1]
	int mid2=mid1+len;				//����2:a[mid1+1,mid2],����3:a[mid2+1..high]
	sum1=SUM(low,mid1);
	sum2=SUM(mid1+1,mid2);
	printf("  Ӳ��%d-%d��Ӳ��%d-%d����һ��: ",low,mid1,mid1+1,mid2);
	if (sum1==sum2)
	{
		printf("����������ͬ\n");
		return solve(mid2+1,high);	//�ٱ�������3
	}
	else if (sum1<sum2)				//�ٱ�������1
	{
		printf("ǰ��������\n");
		return solve(low,mid1);
	}
	else							//�ٱ�������2
	{
		printf("����������\n");
		return solve(mid1+1,mid2);
	}
}
void main()
{
	int n=100;
	for (int i=0;i<n;i++)
		a[i]=2;					//����Ӳ������
	srand((unsigned)time(NULL));
	a[rand()%n]=1;				//�������һ���ٱ�����Ϊ1
	printf("������\n");
	printf("  Ӳ��%d�Ǽٱ�\n",solve(0,n-1));
}
