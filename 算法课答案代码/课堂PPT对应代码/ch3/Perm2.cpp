//�ݹ����ȫ��������
#include <stdio.h>
#define MaxSize 10
void disp(int a[],int n)			//���һ������
{	int i;
	for (i=0;i<n;i++)
		printf("%d",a[i]);
	printf(" ");
}
void perm(int a[],int n,int k)
{	int i,j;
	if (k==n)						//��a������λ��������,�����һ����
		disp(a,n);
	else
		for (i=1;i<=n;i++)			//������a����������i
		{	bool has=false;
			for (j=0;j<k;j++)		//��a[0..k]�г��ֹ�i,��hasΪtrue
				if (a[j]==i) has=true;
			if (!has)				//��a[0..k]��û�г��ֹ�i,��ѡi
			{	a[k]=i;
				perm(a,n,k+1);		//���������һ��λ�õ�����
			}
		}
}
void main()
{	int n=3;
	int a[MaxSize];
	printf("1��%d��ȫ��������:",n);
	perm(a,n,0);
	printf("\n");
}
