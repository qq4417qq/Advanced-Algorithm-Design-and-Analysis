//����ݼ�����-�ⷨ1
#include <stdio.h>
#include <math.h>
#define MaxN 10
void change(int b[],int n);
void pset(int a[],int b[],int n)
{	int i,k;
	int pw=pow(2,n);			//��2n
	printf("����a�������Ӽ�:");
	for(i=0;i<pw;i++)			//ִ��2n��
	{	printf("{ ");
		for (k=0;k<n;k++)		//ִ��n��
			if(b[k])
				printf("%d ",a[k]);
		printf("} ");
		change(b,n);			//b��ʾ�Ķ���������1
	}
	printf("\n");
}
void change(int b[], int n)		//�ı�b���飬��b��ʾ�Ķ���������1
{	int i;
	for(i=0;i<n;i++)			//��������b
	{	if(b[i])				//��Ԫ��1��Ϊ0
			b[i]=0;
		else					//��Ԫ��0��Ϊ1���˳�forѭ��
		{	b[i]=1;
			break;
		}
	}
}
void main()
{	int n=3,i;
	int a[MaxN],b[MaxN];
	for (i=0;i<n;i++)
	{	a[i]=i+1;				//a��ʼ��Ϊ{1,2,3}
		b[i]=0;				//b��ʼ��Ϊ{0,0,0}
	}
	pset(a,b,n);
}
