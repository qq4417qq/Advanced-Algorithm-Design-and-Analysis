//求解多机调度问题的算法
#include <stdio.h> 
#define M 10					//最多的机器台数
#define N 20					//最多的作业数
typedef struct					//采用一个结构体数组存放分配方案
{	int seq[N];					//机器的作业序列
	int sumt;					//机器总处理时间
	int num;					//机器处理的作业总数
} PlanType;						//调度分配方案类型
int Partition(int T[],int P[],int s,int t)	//划分算法
{	int i=s,j=t;
	int tmpt=T[s];				//用序列的第1个记录作为基准
	int tmpp=P[s];
	while (i!=j)				//从序列两端交替向中间扫描,直至i=j为止
	{	while (j>i && T[j]<=tmpt) 
			j--;				//从右向左扫描
		T[i]=T[j];				//将T[j]前移到T[i]的位置
		P[i]=P[j];				//将P[j]前移到P[i]的位置
		while (i<j && T[i]>=tmpt) 
			i++;				//从左向右扫描
		T[j]=T[i];				//将T[i]后移到T[j]的位置
		P[j]=P[i];				//将P[i]后移到P[j]的位置
	}
	T[i]=tmpt;
	P[i]=tmpp;
	return i;
}
void QuickSort(int T[],int P[],int s,int t)	//T递减排序,相应修改P
{	int i;
	if (s<t) 					//序列内至少存在2个元素的情况
	{	i=Partition(T,P,s,t);
		QuickSort(T,P,s,i-1);	//对左子序列递归排序
		QuickSort(T,P,i+1,t);	//对右子序列递归排序
	}
}
void disp(int a[],int n)		//输出a中所有元素
{	int i;
	for (i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}
void dispschedule(PlanType S[],int m,int n)	//输出一个分配方案
{	int i,j;
	for (i=0;i<m;i++)
	{	printf("  机器%d分配的作业序列:",i+1);
		for (j=0;j<S[i].num;j++)
			printf("%d ",S[i].seq[j]);
		printf(",加工总时间为%d\n",S[i].sumt);
	}
}
void Mscheduling(int P[],int T[],PlanType S[],int n,int m)	//求调度方案S
{	int i,j,k;
	for(i=0;i<m;i++)				//将m个作业分配给m台机器
	{	S[i].num=S[i].sumt=0;
		S[i].seq[S[i].num]=P[i];	//将作业P[i]分配给机器i
		S[i].sumt=T[i];				//累加处理时间
		S[i].num++;					//累计处理作业数
	}
	for(i=m;i<n;i++)				//分配余下的作业
	{ 	j=0;
		for (k=1;k<m;k++)			//求所有机器中处理时间总数最小的下标j
			if (S[k].sumt<S[j].sumt) j=k;
		S[j].seq[S[j].num]=P[i];	//将作业P[i]分配给机器j
		S[j].sumt+=T[i];			//累加处理时间
		S[j].num++;					//累计处理作业数
	}
}
void main() 
{	int n=7,m=3;
	int P[M]={1,2,3,4,5,6,7};		//存放n个作业的编号
	int T[M]={2,14,4,16,6,5,3};		//存放n个作业的处理时间
	PlanType S[M];					//存放调度方案
	printf("排序前:\n");
	printf("  T: "); disp(T,n);
	printf("  P: "); disp(P,n);
	QuickSort(T,P,0,n-1);
	printf("排序后:\n");
	printf("  T: "); disp(T,n);
	printf("  P: "); disp(P,n);
	printf("调度方案如下:\n");
	Mscheduling(P,T,S,n,m);
	dispschedule(S,m,n);
}  
