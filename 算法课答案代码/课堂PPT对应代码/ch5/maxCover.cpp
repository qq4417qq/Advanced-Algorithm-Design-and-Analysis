//�������ཻ����������㷨
#include <stdio.h>
#define MaxSize 10
typedef struct				//������������
{	int start;				//��˵�
	int end;				//�Ҷ˵�
} IntervalType;
int Partition(IntervalType a[],int s,int t)	//�����㷨
{	int i=s,j=t;
	IntervalType tmp=a[s];			//�õ�1��������Ϊ��׼
	while (i!=j)					//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && a[j].end>=tmp.end)
			j--;					//��������ɨ��
		a[i]=a[j];					//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i<j && a[i].end<=tmp.end)
			i++;					//��������ɨ��
		a[j]=a[i];					//��a[i]���Ƶ�a[j]��λ��
	}
	a[i]=tmp;
	return i;
}
void QuickSort(IntervalType a[],int s,int t)	//��a[s..t]Ԫ�����н��е�������
{	int i;
	if (s<t) 						//���ٴ���2����������
	{	i=Partition(a,s,t);
		QuickSort(a,s,i-1);			//���󲿷ֵݹ�����
		QuickSort(a,i+1,t);			//���Ҳ��ֵݹ�����
	}
}
int maxCover(IntervalType x[],int n,IntervalType y[])	//��x������ཻ���伯��y
{	int i,m=0;						//mΪy���±꣬��0��ʼ
	int j=0;						//j�������õ���С��������±꣬��0��ʼ
	y[0]=x[0];
	for (i=1;i<n;i++)
	{	if (x[i].start>=x[j].end)
		{	m++; y[m]=x[i];
			j=i;
		}
	}
	return m+1;
}
void disp(IntervalType x[],int n)	//���x�е�n������
{	int i;
	for (i=0;i<n;i++)
		printf("[%d,%d] ",x[i].start,x[i].end);
	printf("\n");
}
void main()
{	int n,m;
	IntervalType y[MaxSize];
	IntervalType x[]={{2,6},{1,4},{3,6},{3,7},{6,8},{2,4},{3,5}};n=7;
	printf("����ǰ:"); disp(x,n);
	QuickSort(x,0,n-1);
	printf("�����:"); disp(x,n);
	m=maxCover(x,n,y);
	printf("�����:\n");
	printf("ѡȡ������Ϊ%d��\n",m);
	printf("ѡȡ������:"); disp(y,m);
}
