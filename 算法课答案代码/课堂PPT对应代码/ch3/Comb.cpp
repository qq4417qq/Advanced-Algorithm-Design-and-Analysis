//�ݹ�������������
#include <stdio.h>
#define MAXK 10
int n,k;						//ȫ�ֱ���
void dispcomb(int a[])			//���һ�����
{	int j;
for (j=0;j<k;j++)
printf("%3d",a[j]);
printf("\n");
}
void comb(int a[],int n,int k)	//��1..n��k�����������
{	int i;
	if (k==0)					//kΪ0ʱ���һ�����
		dispcomb(a);
	else
	{	for (i=k;i<=n;i++)
		{	a[k-1]=i;			//a[k-1]λ��ȡk��n������
			comb(a,i-1,k-1); 	//a[k-1]���a[0..i-1]�е�k-1����������һ�����
		}
	}
}
void main()
{	int a[MAXK];
n=5; k=3;
printf("1..%d��%d�����������������:\n",n,k);
comb(a,n,k);
}
