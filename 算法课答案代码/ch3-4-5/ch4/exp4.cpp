#include<stdio.h>
#define MAX 30
//�����ʾ
int n=2;							//���ĸ���
int h=1;							//����ʱ��
int fi[MAX]={0,10,1};				//���������,�����±�0����
int di[MAX]={0,2,5};				//��λʱ����ļ�����,�����±�0����
int ti[MAX]={0,2};					//ti[i]Ϊ��i����i+1��ʱ��,�����±�0����
int cfi[MAX];						//����fi
//�������ʾ
struct NodeType
{	int num[MAX];					//�������ĵ���ʱ��
	int max;						//���ĵ�����
} Lake[MAX];						//Lake[i]��ʾ�������һ����i�Ľ��
int maxlast;						//��������ʱ��󾭹����ı��
int GetMax(int p[],int i,int j)			//��p[i..j]�����Ԫ�ص��±�
{	int maxi=i;						//���Ԫ���±��ʼ��
	for (int k=i+1;k<=j;k++)
		if (p[maxi]<p[k])	//�Ƚ�
			maxi=k;
	return maxi;
}
void solve()						//����������
{	int i,j,t,restT;
	int T=60*h;					//����ʱ����ʱ��
	for (i=1;i<=n;i++)				//ö��ÿһ�����ܵĽ�����λ��
	{	restT=T;					//ʣ�µ�ʱ��
		for (j=1;j<=i;j++)			//�����߹��ĺ���1,2,��,i
		{	cfi[j]=fi[j];				//��ʼ��cfi
			if (j<i)
				restT-=5*ti[j];		//��ȥ�����i·����·��ʱ��
		}
		t=0;
		while (t<restT)				//�������еĵ���ʱ��
		{	int k=GetMax(cfi,1,i);	//�ҵ����������ĺ�k
			Lake[i].max+=cfi[k];		//�ں�k�е�һ����λʱ�����
			Lake[i].num[k]+=5;		//��i�ĵ���ʱ������һ����λʱ��
			if (cfi[k]>=di[k])			//�޸ĺ�k��һ����λʱ��ĵ�����
				cfi[k]-=di[k];
			else
				cfi[k]=0;
			t+=5;					//����һ����λʱ��5
		}
	}
}
int main()
{	int i,j;
	for (i=1;i<=n;i++)				//Lake�����ʼ��
	{	Lake[i].max=0;
		for (j=0;j<=n;j++)
			Lake[i].num[j]=0;
	}
	solve();
	printf("�����\n");
	maxlast=1;
	for (i=2;i<=n;i++)
		if (Lake[i].max>Lake[maxlast].max)
			maxlast=i;
	for (i=1;i<=n;i++)
		printf("    �ں�%d����ʱ��Ϊ%d����\n",i,Lake[maxlast].num[i]);
	printf("  �ܵĵ�����: %d\n",Lake[maxlast].max);
    return 0;
}
