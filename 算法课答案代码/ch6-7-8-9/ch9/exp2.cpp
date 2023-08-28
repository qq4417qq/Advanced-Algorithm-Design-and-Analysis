#include <stdio.h>
#include <string.h>
#define INF 32767				//�����
#define	MAXV 105			//��󶥵����
int A[MAXV][MAXV];			//������֮�䴫�ݵ�ʱ������·������
int n;							//����
void Floyd()					//��Floyd�㷨�����ж������·������
{	int i,j,k;
	for (k=0;k<n;k++)			//���ο������ж���
	{	for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
					A[i][j]=A[i][k]+A[k][j];//�޸����·������
	}
}
int Minp()						//����ĿҪ����˱��
{	int i,j,mm;
	int mini=-1,mint=INF;
	for (i=0;i<n;i++)
	{	mm=0;
		for (j=0;j<n;j++)			//�󶥵�i���������������·������
			mm=A[i][j]>mm?A[i][j]:mm;
		if (mm<mint)			//����С������·�����ȵĶ���mini
		{	mint=mm;
			mini=i;
		}
	}
	if (mini==-1)				//ͼ����ͨ�����
		return -1;
	else
		return mini;
}
int main()
{	int i,j,t,m;
	int a,b;
	while (true)
	{	scanf("%d",&n);			//��������
		if (n<=0) break;			//��nС�ڵ���0��ʾ����
		scanf("%d",&m);		//�������
		for (i=0;i<n;i++)			//��ʼ��A
		{	for (j=0;j<n;j++)
				A[i][j]=INF;
			A[i][i]=0;
		}
		while (m--)
		{	scanf("%d%d%d",&a,&b,&t);
			A[a][b]=A[b][a]=t;
		}
		Floyd();					//����Floyd�㷨
		printf("%d\n",Minp());
	}
    return 0;
}
