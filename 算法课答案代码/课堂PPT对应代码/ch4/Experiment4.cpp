//�ϻ�ʵ����4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
void randa(int a[],int n)		//����n��1��20�������
{
	int i;
	for (i=0;i<n;i++)
		a[i]=rand()%20+1;
}
void MaxMin(int a[],int n,int &comp)	//�������СԪ�غͱȽϴ���
{
	int i,max,min;
	comp=0;
	max=min=a[0];
	for (i=1;i<n;i++)
	{
		comp++;
		if(a[i]>max)
			max=a[i];
		else
		{
			comp++;
			if(a[i]<min)
				min=a[i];
		}
	}
	for (i=0;i<n;i++)
		printf("%4d",a[i]);
	printf(" :max=%d,min=%d,comp=%d\n",max,min,comp);
}
void main()
{
	int a[MAXN];
	int m,sumcomp=0,comp;
	srand((unsigned)time(NULL));
	for (m=1;m<=100;m++)
	{
		randa(a,10);
		MaxMin(a,10,comp);
		sumcomp+=comp;
	}
	printf("ƽ���Ƚϴ���=%g\n",1.0*sumcomp/100);
}
