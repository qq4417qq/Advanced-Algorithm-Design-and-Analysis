//���0/1��������
#include <stdio.h>
#define Maxn 10							//����nֵ
#define MaxSize 1000					//�����Ӽ�����
typedef struct							//�����ݼ�����
{	int data[MaxSize][Maxn];			//data[i][0]��ʾ���Ӽ��ĳ���
	int n;								//�Ӽ�����
} PSetType;
void copy(int a[],int b[],int m)		//��a[0..m]���Ƶ�b[0..m]
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
void knap(PSetType p,int w[],int v[],int W)	//�����еķ�������ѷ���
{	int i,j;
	int sumw,sumv;
	int maxi,maxsumw=0,maxsumv=0;
	printf("  ���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");
	for (i=0;i<p.n;i++)
	{	printf("  %d\t",i+1);
		sumw=sumv=0;
		printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
		{	printf("%d ",p.data[i][j]);
			sumw+=w[p.data[i][j]-1];
			sumv+=v[p.data[i][j]-1];
		}
		printf("}\t\t%d\t%d\t",sumw,sumv);
		if (sumw<=W)
		{	printf("��\n");
			if (sumv>maxsumv)
			{	maxsumw=sumw;
				maxsumv=sumv;
				maxi=i;
			}
		}
		else printf("��\n");
	}
	printf("��ѷ���Ϊ ");
	printf("ѡ����Ʒ:");
	printf("{ ");
	for (j=1;j<=p.data[maxi][0];j++)
		printf("%d ",p.data[maxi][j]);
	printf("},");
	printf("������:%d,�ܼ�ֵ:%d\n",maxsumw,maxsumv);
}
void main()
{	int n=4,W=7;
	int w[]={5,3,2,1};
	int v[]={4,4,3,1};
	PSetType p;
	pset(n,p);
	printf("0/1��������ⷽ��\n",n);
	knap(p,w,v,W); printf("\n");
}
