//���������������к�����-�ⷨ1
#include <stdio.h>
long maxSubSum1(int a[],int n)
{	int i,j,k;
	long maxSum=a[0],thisSum; 
	for (i=0;i<n;i++)				//����ѭ��������е�����������
	{	for (j=i;j<n;j++)
		{	thisSum=0;
			for (k=i;k<=j;k++)
				thisSum+=a[k];
			if (thisSum>maxSum)	//ͨ���Ƚ����������������֮��
				maxSum=thisSum;
		}
	}
	return maxSum;
}
void main()
{	int a[]={-2,11,-4,13,-5,-2},n=6;
	int b[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2},m=12;
	printf("a���е�������������еĺ�:%ld\n",maxSubSum1(a,n));
	printf("b���е�������������еĺ�:%ld\n",maxSubSum1(b,m));
}
