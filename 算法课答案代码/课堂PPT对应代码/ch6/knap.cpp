//���0/1����������㷨
#include <stdio.h> 
#define MaxN 20				//�����Ʒ��
#define MaxL 100				//�����������
int knap(int f[MaxN][MaxL],int w[],int v[],int W,int n)	//��̬�滮����0/1��������
{	int i,r;
	for (i=0;i<=n;i++)			//�ñ߽�����f(i,0)=0
		f[i][0]=0;
	for (r=0;r<=W;r++)			//�ñ߽�����f(0,r)=0
		f[0][r]=0;
	for (i=1;i<=n;i++)
	{	for (r=1;r<=W;r++)
			if (r<w[i])
				f[i][r]=f[i-1][r];
			else
			{	if (f[i-1][r]<f[i-1][r-w[i]]+v[i])
					f[i][r]=f[i-1][r-w[i]]+v[i];
				else
					f[i][r]=f[i-1][r];
			}
	}
	return f[n][W];			//�����ܼ�ֵ
}
int Traceback(int f[MaxN][MaxL],int w[],int x[],int W,int n) //���������Ž�
{	int i,r=W;
	int maxw=0; 				//������Ž���ܼ�ֵ
	for (i=n;i>0;i--)			//ѭ���ж�ÿ����Ʒ
		if (f[i][r]!=f[i-1][r]) 
		{	x[i]=1;			//ѡȡ��Ʒi
			maxw+=w[i];		//�ۼ�������
			r=r-w[i];
		}
		else
			x[i]=0;			//��ѡȡ��Ʒi
	return maxw;				//����������
}
void dispknap(int x[],int maxw,int maxv,int n)	//�����ѱ�������
{	int i;
	printf("��ѱ���������:\n");
	for (i=0;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",i);
	printf("������=%d,�ܼ�ֵ=%d\n",maxw,maxv);
}
void main()
{	int f[MaxN][MaxL];
	int x[MaxN];
	int maxv; 						//������Ž���ܼ�ֵ
	int maxw;						//������Ž��������
	int n=5,W=10;					//5����Ʒ,��������������10
	int w[MaxN]={0,2,2,6,5,4};		//�±�0����
	int v[MaxN]={0,6,3,5,4,6};		//�±�0����
	maxv=knap(f,w,v,W,n);
	maxw=Traceback(f,w,x,W,n);
	dispknap(x,maxw,maxv,n);
}
