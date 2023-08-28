//求解最大不相交区间问题的算法
#include <stdio.h>
#define MaxSize 10
typedef struct				//声明区间类型
{	int start;				//左端点
	int end;				//右端点
} IntervalType;
int Partition(IntervalType a[],int s,int t)	//划分算法
{	int i=s,j=t;
	IntervalType tmp=a[s];			//用第1个区间作为基准
	while (i!=j)					//从两端交替向中间扫描,直至i=j为止
	{	while (j>i && a[j].end>=tmp.end)
			j--;					//从右向左扫描
		a[i]=a[j];					//将a[j]前移到a[i]的位置
		while (i<j && a[i].end<=tmp.end)
			i++;					//从左向右扫描
		a[j]=a[i];					//将a[i]后移到a[j]的位置
	}
	a[i]=tmp;
	return i;
}
void QuickSort(IntervalType a[],int s,int t)	//对a[s..t]元素序列进行递增排序
{	int i;
	if (s<t) 						//至少存在2个区间的情况
	{	i=Partition(a,s,t);
		QuickSort(a,s,i-1);			//对左部分递归排序
		QuickSort(a,i+1,t);			//对右部分递归排序
	}
}
int maxCover(IntervalType x[],int n,IntervalType y[])	//求x的最大不相交区间集合y
{	int i,m=0;						//m为y的下标，从0开始
	int j=0;						//j保存刚求得的最小闭区间的下标，从0开始
	y[0]=x[0];
	for (i=1;i<n;i++)
	{	if (x[i].start>=x[j].end)
		{	m++; y[m]=x[i];
			j=i;
		}
	}
	return m+1;
}
void disp(IntervalType x[],int n)	//输出x中的n个区间
{	int i;
	for (i=0;i<n;i++)
		printf("[%d,%d] ",x[i].start,x[i].end);
	printf("\n");
}
void main()
{	int n,m;
	IntervalType y[MaxSize];
	IntervalType x[]={{2,6},{1,4},{3,6},{3,7},{6,8},{2,4},{3,5}};n=7;
	printf("排序前:"); disp(x,n);
	QuickSort(x,0,n-1);
	printf("排序后:"); disp(x,n);
	m=maxCover(x,n,y);
	printf("求解结果:\n");
	printf("选取的区间为%d个\n",m);
	printf("选取的区间:"); disp(y,m);
}
