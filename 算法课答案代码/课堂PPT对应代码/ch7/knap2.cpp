//���ý�һ����֦���0/1����������㷨
#include <stdio.h>
#define MAXN 20					//�����Ʒ��
int maxv; 						//������Ž���ܼ�ֵ
int maxw;						//������Ž��������
int x[MAXN];					//������ս�
void knap(int w[],int v[],int W,int n,int i,int tw,int tv,int op[]) //���ǵ�i����Ʒ
{	int j,m;
	if (i>n)					//�ҵ�һ��Ҷ�ӽ��
	{	if (tw<=W && tv>maxv) 	//�ҵ�һ�����������ĸ��Ž�,������
		{	maxv=tv;
			maxw=tw;
			for (j=1;j<=n;j++)
				x[j]=op[j];
		}
	}
	else						//��δ����������Ʒ
	{	if (tw+w[i]<W)  		//���ӽ���֦����������ʱ�ŷ����i����Ʒ
		{	op[i]=1;			//ѡȡ��i����Ʒ
			knap(w,v,W,n,i+1,tw+w[i],tv+v[i],op);
		}
		op[i]=0;				//��ѡȡ��i����Ʒ,����
		m=0;
		for (j=0;j<i;j++)		//m�ۼƲ�ѡȡ����Ʒ��
			if (op[j]==0) m++;
		if (m<=1)				//�Һ��ӽ���֦������Ҫѡ3����Ʒ
			knap(w,v,W,n,i+1,tw,tv,op);
	}
}
void dispasolution(int x[],int n)//���һ����
{	int i;
	printf("���װ�����:\n");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",i);
	printf("������=%d,�ܼ�ֵ=%d\n",maxw,maxv);
}
void main()
{	int n=4;					//4����Ʒ
	int W=7;					//��������������7
	int op[MAXN];				//�����ʱ��
	int w[]={0,5,3,2,1};		//���4����Ʒ����,�����±�0Ԫ��
	int v[]={0,4,4,3,1};		//���4����Ʒ��ֵ,�����±�0Ԫ��
	knap(w,v,W,n,1,0,0,op);
	dispasolution(x,n);
}
