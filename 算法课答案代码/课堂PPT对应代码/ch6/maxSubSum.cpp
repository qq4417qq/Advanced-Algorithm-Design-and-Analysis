//���������������к�������㷨
#include <stdio.h>
#define MaxN 20
void maxSubSum(int a[],int b[],int n)	//��b����
{	int j;
	b[0]=0;
	for (j=1;j<=n;j++)
	{	if (b[j-1]+a[j]>a[j])
			b[j]=b[j-1]+a[j];
		else
			b[j]=a[j];
	}
}
void dispmaxSum(int a[],int b[],int n)	//������
{	int maxj,i,j,k;
	maxj=1;
	for (j=2;j<=n;j++)			//��b�����Ԫ��b[maxj]
		if (b[j]>b[maxj]) maxj=j;
	for (k=maxj;k>=1;k--)		//��ǰһ��ֵС�ڵ���0��
		if (b[k]<=0) break;
	printf("������������к�:%d\n",b[maxj]);
	printf("��ѡ������:");
	for (i=k+1;i<=maxj;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{	int a[]={0,-2,11,-4,13,-5,-2},n=6;	//a���鲻���±�Ϊ0��Ԫ��
	int b[MaxN];
	maxSubSum(a,b,n);
	dispmaxSum(a,b,n);
}
