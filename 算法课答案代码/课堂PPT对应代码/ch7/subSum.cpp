//����Ӽ���������㷨
#include <stdio.h>
#define MAXN 20						//�����������
int n,W;
int count=0;						//�ۼƽ����
void dispasolution(int w[],int x[])	//���һ����
{	int i;
	printf("��%d����:\n",++count);
	printf("  ѡȡ����Ϊ");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("%d ",w[i]);
	printf("\n");
}
void subSum(int w[],int tw,int rw,int x[],int i) //���ǵ�i������
{	//twΪ���ǵ�i������ʱѡȡ�������ͣ�cwΪʣ�µ�������
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{	if (tw==W)					//�ҵ�һ�����������Ľ�,�����
			dispasolution(w,x);
	}
	else							//��δ����������Ʒ
	{	rw-=w[i];					//��ʣ���������
		if (tw+w[i]<=W)				//���ӽ���֦��ѡȡ��������������w[i]
		{	x[i]=1;					//ѡȡ��i������
			subSum(w,tw+w[i],rw,x,i+1);
		}
		if (tw+rw>=W)				//�Һ��ӽ���֦�����������ܴ��ڽ�Ľ��
		{	x[i]=0;					//��ѡȡ��i����װ��,����
			subSum(w,tw,rw,x,i+1);
		}
	}
}
void main()
{	int j,rw=0;
	int w[]={0,11,13,24,7};			//�����������,�����±�0��Ԫ��
	int x[MAXN];					//��Ž�����
	n=4,W=31;
	for (j=1;j<=n;j++)				//������������rw
		rw+=w[j];
	subSum(w,0,rw,x,1);
}
