//�����Դ����������㷨
#include <stdio.h>
#define MAXK 10				//�����Ŀ��
#define MAXS 10				//���Ͷ�������
int Plan(int v[][MAXS],int d[][MAXS],int K,int S)	//�����ŷ���d
{	int x,s,k;
	int maxf;
	int f[MAXK][MAXS];
	for (s=0;s<=S;s++)			//�ñ߽�����
		f[K][s]=0;
	for (k=K-1;k>=1;k--)		//�ӽ׶�3��1���д���
	{	for (s=0;s<=S;s++)		//���������������k���̵�
		{	maxf=0;
			for (x=0;x<=s;x++)	//�Ҹ��̵����ŷ�������x
			{	if ((v[k][x]+f[k+1][s-x])>=maxf)
				{	maxf=v[k][x]+f[k+1][s-x];
					d[k][s]=x;
				}
			}
			f[k][s]=maxf;
		}
	}
	return f[1][S];			//������Ӯ��
}
void dispPlan(int max,int d[][MAXS],int K,int S) //������ŷ��䷽��
{	int k,r,s;
	s=d[1][S];
	r=S-s;					//rΪ���µ�����
	printf("������Դ���䷽������:\n");
	for (k=1;k<K;k++)
	{	printf("  %c�̵����%d��\n",'A'+k-1,s);
		s=d[k+1][r];			//����һ���׶η��������
		r=r-s;				//���������ݼ�
	}
	printf("�÷��䷽������Ӯ��Ϊ%d��Ԫ\n",max);
}
void main()
{	int v[MAXK][MAXS]={{0,0,0,0,0,0},{0,3,7,9,12,13},
		{0,5,10,11,11,11},{0,4,6,11,12,12}}; //����v[0]��
	int d[MAXK][MAXS],max;
	int K=4,S=5;				//�׶���ΪK,������ΪS
	max=Plan(v,d,K,S);
	dispPlan(max,d,K,S);
}
