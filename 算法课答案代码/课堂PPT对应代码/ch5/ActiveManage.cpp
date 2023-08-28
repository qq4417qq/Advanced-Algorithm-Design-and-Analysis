//求解活动安排问题的算法
#include <stdio.h>
#define MaxSize 20
int Partition(int b[],int e[],int s,int t)	//划分算法
{	int i=s,j=t;
	int tmpb=b[s],tmpe=e[s];		//用第1个活动作为基准
	while (i!=j)					//从两端交替向中间扫描,直至i=j为止
	{	while (j>i && e[j]>=tmpe)
			j--;					//从右向左扫描
		b[i]=b[j]; e[i]=e[j];		//将b[j]/e[j]前移到b[i]/e[i]的位置
		while (i<j && e[i]<=tmpe)
			i++;					//从左向右扫描
		b[j]=b[i]; e[j]=e[i];		//将b[i]/e[i]后移到b[j]/e[j]的位置
	}
	b[i]=tmpb; e[i]=tmpe;
	return i;
}
void QuickSort(int b[],int e[],int s,int t)	//对e[s..t]元素序列进行递增排序
{	int i;
	if (s<t) 						//至少存在2个区间的情况
	{	i=Partition(b,e,s,t);
		QuickSort(b,e,s,i-1);		//对左部分递归排序
		QuickSort(b,e,i+1,t);		//对右部分递归排序
	}
}
int ActiveManage(int b[],int e[],int n,int B[],int E[])
{	int i,m=0;							//m为B和E的下标，从0开始
	int j=0;							//选取的第一个活动的下标
	B[0]=b[0]; E[0]=e[0];				//选取第一个活动
	for (i=1;i<n;i++)
	{	if (b[i]>=e[j])
		{	j=i;						//j指向当前选取的活动的下标
			m++; B[m]=b[i]; E[m]=e[i];	//选取活动i
		}
	}
	return m+1;							//返回选取的活动个数
}
void disp(int b[],int e[],int n)		//输出n个活动
{	int i;
	for (i=0;i<n;i++)
		printf("[%d,%d] ",b[i],e[i]);
	printf("\n");
}
void main()
{
	int n=11,m;
	int B[MaxSize],E[MaxSize];
	int b[]={1,3,0,5,3,5,6,8,8,2,12};		//11个活动的起始时间
	int e[]={4,5,6,7,8,9,10,11,12,13,14};	//11个活动的终止时间
	printf("排序前:"); disp(b,e,n);
	QuickSort(b,e,0,n-1);
	printf("排序后:"); disp(b,e,n);
	m=ActiveManage(b,e,n,B,E);
	printf("求解结果:\n");
	printf("  选取的活动为%d个\n",m);
	printf("  选取的活动:"); disp(B,E,m);
}
