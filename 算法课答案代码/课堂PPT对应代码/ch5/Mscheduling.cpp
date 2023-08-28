//���������������㷨
#include <stdio.h> 
#define M 10					//���Ļ���̨��
#define N 20					//������ҵ��
typedef struct					//����һ���ṹ�������ŷ��䷽��
{	int seq[N];					//��������ҵ����
	int sumt;					//�����ܴ���ʱ��
	int num;					//�����������ҵ����
} PlanType;						//���ȷ��䷽������
int Partition(int T[],int P[],int s,int t)	//�����㷨
{	int i=s,j=t;
	int tmpt=T[s];				//�����еĵ�1����¼��Ϊ��׼
	int tmpp=P[s];
	while (i!=j)				//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && T[j]<=tmpt) 
			j--;				//��������ɨ��
		T[i]=T[j];				//��T[j]ǰ�Ƶ�T[i]��λ��
		P[i]=P[j];				//��P[j]ǰ�Ƶ�P[i]��λ��
		while (i<j && T[i]>=tmpt) 
			i++;				//��������ɨ��
		T[j]=T[i];				//��T[i]���Ƶ�T[j]��λ��
		P[j]=P[i];				//��P[i]���Ƶ�P[j]��λ��
	}
	T[i]=tmpt;
	P[i]=tmpp;
	return i;
}
void QuickSort(int T[],int P[],int s,int t)	//T�ݼ�����,��Ӧ�޸�P
{	int i;
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{	i=Partition(T,P,s,t);
		QuickSort(T,P,s,i-1);	//���������еݹ�����
		QuickSort(T,P,i+1,t);	//���������еݹ�����
	}
}
void disp(int a[],int n)		//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}
void dispschedule(PlanType S[],int m,int n)	//���һ�����䷽��
{	int i,j;
	for (i=0;i<m;i++)
	{	printf("  ����%d�������ҵ����:",i+1);
		for (j=0;j<S[i].num;j++)
			printf("%d ",S[i].seq[j]);
		printf(",�ӹ���ʱ��Ϊ%d\n",S[i].sumt);
	}
}
void Mscheduling(int P[],int T[],PlanType S[],int n,int m)	//����ȷ���S
{	int i,j,k;
	for(i=0;i<m;i++)				//��m����ҵ�����m̨����
	{	S[i].num=S[i].sumt=0;
		S[i].seq[S[i].num]=P[i];	//����ҵP[i]���������i
		S[i].sumt=T[i];				//�ۼӴ���ʱ��
		S[i].num++;					//�ۼƴ�����ҵ��
	}
	for(i=m;i<n;i++)				//�������µ���ҵ
	{ 	j=0;
		for (k=1;k<m;k++)			//�����л����д���ʱ��������С���±�j
			if (S[k].sumt<S[j].sumt) j=k;
		S[j].seq[S[j].num]=P[i];	//����ҵP[i]���������j
		S[j].sumt+=T[i];			//�ۼӴ���ʱ��
		S[j].num++;					//�ۼƴ�����ҵ��
	}
}
void main() 
{	int n=7,m=3;
	int P[M]={1,2,3,4,5,6,7};		//���n����ҵ�ı��
	int T[M]={2,14,4,16,6,5,3};		//���n����ҵ�Ĵ���ʱ��
	PlanType S[M];					//��ŵ��ȷ���
	printf("����ǰ:\n");
	printf("  T: "); disp(T,n);
	printf("  P: "); disp(P,n);
	QuickSort(T,P,0,n-1);
	printf("�����:\n");
	printf("  T: "); disp(T,n);
	printf("  P: "); disp(P,n);
	printf("���ȷ�������:\n");
	Mscheduling(P,T,S,n,m);
	dispschedule(S,m,n);
}  
