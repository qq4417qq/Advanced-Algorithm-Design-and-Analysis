//�������������㷨
#include <stdio.h>
#define MaxSize 20
int Partition(int b[],int e[],int s,int t)	//�����㷨
{	int i=s,j=t;
	int tmpb=b[s],tmpe=e[s];		//�õ�1�����Ϊ��׼
	while (i!=j)					//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && e[j]>=tmpe)
			j--;					//��������ɨ��
		b[i]=b[j]; e[i]=e[j];		//��b[j]/e[j]ǰ�Ƶ�b[i]/e[i]��λ��
		while (i<j && e[i]<=tmpe)
			i++;					//��������ɨ��
		b[j]=b[i]; e[j]=e[i];		//��b[i]/e[i]���Ƶ�b[j]/e[j]��λ��
	}
	b[i]=tmpb; e[i]=tmpe;
	return i;
}
void QuickSort(int b[],int e[],int s,int t)	//��e[s..t]Ԫ�����н��е�������
{	int i;
	if (s<t) 						//���ٴ���2����������
	{	i=Partition(b,e,s,t);
		QuickSort(b,e,s,i-1);		//���󲿷ֵݹ�����
		QuickSort(b,e,i+1,t);		//���Ҳ��ֵݹ�����
	}
}
int ActiveManage(int b[],int e[],int n,int B[],int E[])
{	int i,m=0;							//mΪB��E���±꣬��0��ʼ
	int j=0;							//ѡȡ�ĵ�һ������±�
	B[0]=b[0]; E[0]=e[0];				//ѡȡ��һ���
	for (i=1;i<n;i++)
	{	if (b[i]>=e[j])
		{	j=i;						//jָ��ǰѡȡ�Ļ���±�
			m++; B[m]=b[i]; E[m]=e[i];	//ѡȡ�i
		}
	}
	return m+1;							//����ѡȡ�Ļ����
}
void disp(int b[],int e[],int n)		//���n���
{	int i;
	for (i=0;i<n;i++)
		printf("[%d,%d] ",b[i],e[i]);
	printf("\n");
}
void main()
{
	int n=11,m;
	int B[MaxSize],E[MaxSize];
	int b[]={1,3,0,5,3,5,6,8,8,2,12};		//11�������ʼʱ��
	int e[]={4,5,6,7,8,9,10,11,12,13,14};	//11�������ֹʱ��
	printf("����ǰ:"); disp(b,e,n);
	QuickSort(b,e,0,n-1);
	printf("�����:"); disp(b,e,n);
	m=ActiveManage(b,e,n,B,E);
	printf("�����:\n");
	printf("  ѡȡ�ĻΪ%d��\n",m);
	printf("  ѡȡ�Ļ:"); disp(B,E,m);
}
