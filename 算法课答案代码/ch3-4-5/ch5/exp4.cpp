#include <stdio.h>
//�����ʾ
int x[5];					//��������
int n=5;
void swap(int &a, int &b)	//��������Ԫ��
{
	int tmp=a;
	a=b; b=tmp;
}
void dispasolution(int x[])		//���һ����
{
	printf("  %d*%d-%d*%d-%d=1\n",x[0],x[1],x[2],x[3],x[4]);
}
void dfs(int i)		//����㷨
{
	if (i==n)		//�ﵽҶ�ӽ��
	{
		if (x[0]*x[1]-x[2]*x[3]-x[4]==1)
			dispasolution(x);
		
	}
	else
	{
		for (int j=i;j<n;j++)
		{
			swap(x[i],x[j]);
			dfs(i+1);
			swap(x[i],x[j]);
		}
	}
}
void main()
{
	for (int j=0;j<n;j++)
		x[j]=j+1;
	printf("�����\n");
	dfs(0);
}
