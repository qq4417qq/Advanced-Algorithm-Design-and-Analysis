//�ݹ�����ݼ�����
#include <stdio.h>
#define Maxn 10						//����nֵ
#define MaxSize 1000				//�����Ӽ�����
typedef struct						//�����ݼ�����
{	int data[MaxSize][Maxn];		//data[i][0]��ʾ���Ӽ��ĳ���
	int n;							//�Ӽ�����
} PSetType;
void copy(int a[],int b[],int m)	//a[0..m]���Ƶ�b[0..m]
{	int i;
	for (i=0;i<=m;i++)
		b[i]=a[i];
}
void addi(PSetType &p,int i)		//���ݼ�p�������Ӽ����i�������Ӽ������뵽p��
{	int j,m;
	int a[Maxn];
	m=p.n; 
	for (j=0;j<m;j++)				//����p��ԭ�е������Ӽ�
	{	copy(p.data[j],a,p.data[j][0]);
		a[0]++;						//�Ӽ��ĳ�����1
		a[a[0]]=i;					//�Ӽ�β���i
		copy(a,p.data[p.n],a[0]);	//���Ӽ����뵽�ݼ���
		p.n++;						//�ݼ����Ӽ�������1
	}
}
void disp(PSetType p)				//����ݼ�
{	int i,j;
	for (i=0;i<p.n;i++)
	{	printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
			printf("%d ",p.data[i][j]);
		printf("} ");
	}
}
void pset(int i,int n,PSetType p)	//���1��n���ݼ�
{	if (i>n)						//����ݹ��������������ݼ�
	{	printf("1��%d���ݼ�����:",n);
		disp(p); printf("\n");
	}
	else
	{	addi(p,i);				//��i���뵽�����Ӽ��в������Ӽ�
		pset(i+1,n,p);			//�ݹ����
	}
}
void main()
{	int n=3;
	PSetType p;					//�����ݼ�
	p.data[0][0]=0; p.n=1;			//�ݼ��ó�ʼ�ռ�
	pset(1,n,p);					//���1��n���ݼ�
}
