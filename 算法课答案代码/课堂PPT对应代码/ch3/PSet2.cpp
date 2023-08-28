//����ݼ�����-�ⷨ2
#include <stdio.h>
#define Maxn 10						//����nֵ
#define MaxSize 1000					//�����Ӽ�����
typedef struct						//�����ݼ�����
{	int data[MaxSize][Maxn];			//data[i][0]��ʾ���Ӽ��ĳ���
	int n;							//�Ӽ�����
} PSetType;
void copy(int a[],int b[],int m)			//��a[0..m]���Ƶ�b[0..m]
{	int i;
	for (i=0;i<=m;i++)
		b[i]=a[i];
}
void pset(int n,PSetType &p)			//��1��n���ݼ�p
{	int i,j,m;
	int a[Maxn];						//a���ڱ���һ���Ӽ�
	p.data[0][0]=0; p.n=1;				//�ó�ֵ�ռ�{}
	for (i=1;i<=n;i++)					//ѭ�����1��n
	{	m=p.n; 							//��ԭ�ݼ��е��Ӽ�����
		for (j=0;j<m;j++)				//��ÿ���Ӽ����i����뵽�ݼ���
		{	copy(p.data[j],a,p.data[j][0]);
			a[0]++;						//�Ӽ��ĳ�����1
			a[a[0]]=i;					//�Ӽ�β���i
			copy(a,p.data[p.n],a[0]);	//���Ӽ����뵽�ݼ���
			p.n++;						//�ݼ����Ӽ�������1
		}
	}
}
void disp(PSetType p)					//����ݼ�p
{	int i,j;
	for (i=0;i<p.n;i++)
	{	printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
			printf("%d ",p.data[i][j]);
		printf("} ");
	}
}
void main()
{	int n=3;
	PSetType p;
	pset(n,p);
	printf("1��%d���ݼ�����:",n);
	disp(p); printf("\n");
}

