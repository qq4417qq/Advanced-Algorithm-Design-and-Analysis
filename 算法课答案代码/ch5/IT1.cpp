#include <stdio.h>
#define MAX 10002
//�����ʾ
struct Action
{
	int b;					//���ʼʱ��
	int e;					//�����ʱ��
};
int n;
Action A[MAX];				//�±�0����
//�������ʾ
int x[MAX];					//������
int laste=0;				//һ�������������ݻ�Ľ���ʱ��
int sum=0;					//һ�����������м��ݻ��ʱ���
int maxsum=0;				//���ŷ��������м��ݻ��ʱ���
void swap(int &x,int &y)	//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void dfs(int i)							//������������Ž�
{
	if (i>n)							//����Ҷ���,����һ�ֵ��ȷ���
    {
		if (sum>maxsum)
			maxsum=sum;
	}
	else
	{
		for(int j=i; j<=n; j++)				//û�е���Ҷ���,����i��n�Ļ
		{	//��i����ѡ��x[j]
			int sum1=sum;					//����sum,laste�Ա����
			int laste1=laste;
			if (A[x[j]].b>=laste)			//�x[j]��ǰ�����
			{
				sum+=A[x[j]].e-A[x[j]].b;	//�ۼƻx[j]��ִ��ʱ��
				laste=A[x[j]].e;			//�޸ı�������������ʱ��
			}
			swap(x[i],x[j]);				//����������ݹ���:����x[i],x[j]
			dfs(i+1);						//����������ݹ���:������һ��
			swap(x[i],x[j]);				//����������ݹ���:����x[i],x[j]
			sum=sum1;						//����
			laste=laste1;					//��������i����Իx[j]��ѡ��,�Ա���ѡ�������
		}
	}
}
int main()
{
	int j;
	scanf("%d",&n);
	for (j=1; j<=n; j++)
		scanf("%d%d",&A[j].b,&A[j].e);	//����p,k
	for (j=1;j<=n;j++)					//x�����ʼ��
		x[j]=j;
	dfs(1);
	printf("%d\n",maxsum);
    return 0;
}



