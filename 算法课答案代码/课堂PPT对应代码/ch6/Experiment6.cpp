//�ϻ�ʵ����6
#include <stdio.h>
#define MAXN 20
void display(int a[],int b[],int k)	//����������������������
{
	int i;
	for (i=k-1;i>=0;i--)
	{
		if (b[k]==b[i]+1 && a[i]<=a[k])
		{
			display(a,b,i);
			break;
		}
	}
	printf("%d ",a[k]);
} 
int maxL(int b[],int n) //������b�����ֵ�±�
{
	int i,k=0;
	int max=b[0];
	for (i=0;i<n;i++)
	{
		if (max<b[i])
		{
			max=b[i];
			k=i;
		}
	}
	return k;
}  
void Maxsubseq(int a[],int b[],int n)
{
	int i,j,k;
	b[0]=1;
	for (i=1;i<n;i++)
	{
		k=0;
		for (j=0;j<i;j++)
			if (a[j]<=a[i] && k<b[j])
				k=b[j];
		b[i]=k+1;
	}
}
void main()
{
	int a[]={4,5,1,3,6,7,2,9,8};
	int b[MAXN];
	int n=8,k;
	Maxsubseq(a,b,n);
	k=maxL(b,n);
	printf("������������������Ԫ���±�k=%d\n",k);
	printf("���������������:");
	display(a,b,k);		//������
	printf("\n");
}