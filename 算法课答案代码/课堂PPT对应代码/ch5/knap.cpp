//��ⱳ��������㷨
#include <stdio.h>
#define MaxSize 20
int Partition(double w[],double v[],int s,int t) //�����㷨
{	int i=s,j=t;
	double tmp1=w[s],tmp2=v[s];	//�õ�1����Ʒ��Ϊ��׼
	while (i!=j)				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && v[j]/w[j]<=tmp2/tmp1)
			j--;				//��������ɨ��
		w[i]=w[j]; v[i]=v[j];	//��w[j]��v[j]ǰ��
		while (i<j && v[i]/w[i]>=tmp2/tmp1)
			i++;				//��������ɨ��
		w[j]=w[i]; v[j]=v[i];	//��w[i]��v[i]����
	}
	w[i]=tmp1; v[i]=tmp2;
	return i;
}
void QuickSort(double w[],double v[],int s,int t)	//��w��v��v/w���еݼ�����
{	int i;
	if (s<t) 					//���ٴ���2����Ʒ�����
	{	i=Partition(w,v,s,t);
		QuickSort(w,v,s,i-1);	//���󲿷ֵݹ�����
		QuickSort(w,v,i+1,t);	//���Ҳ��ֵݹ�����
	}
}
double knap(double W,double w[],double v[],int n,double x[]) //��ⱳ�����Ⲣ�����ܼ�ֵ
{	int i;
	double V=0;					//VΪ�ܼ�ֵ
	double weight=W;			//��������װ�����������
	for (i=0;i<n;i++)			//��ʼ��x����
		x[i]=0;
	i=0;
	while (w[i]<weight)			//��Ʒi�ܹ�ȫ��װ��ʱѭ��
	{	x[i]=1;					//װ����Ʒi
		weight-=w[i];			//���ٱ�������װ�����������
		V+=v[i];				//�ۼ��ܼ�ֵ
		i++;					//����ѭ��
	}
	if (weight>0)				//��������������0
	{	x[i]=weight/w[i];		//����Ʒi��һ����װ��
		V+=x[i]*v[i];			//�ۼ��ܼ�ֵ
	}
	return V;					//�����ܼ�ֵ
}
void disp(double a[],int n)		//���a�е�n��Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%g\t",a[i]);
	printf("\n");
}
void main()
{	int n=5,i;
	double x[MaxSize];
	double W=100,V;
	double w[]={10,20,30,40,50};
	double v[]={20,30,66,40,60};
	QuickSort(w,v,0,n-1);
	printf("��v/w�ݼ��������:\n");
	printf("i: "); 
	for (i=0;i<n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("v: "); disp(v,n);
	printf("w: "); disp(w,n);
	V=knap(W,w,v,n,x);
	printf("x: "); disp(x,n);
	printf("�ܼ�ֵ=%g\n",V);
}
