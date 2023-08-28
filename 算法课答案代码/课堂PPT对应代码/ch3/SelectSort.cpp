//简单选择排序
#include <stdio.h>
void SelectSort(int a[],int n)	//对a[0..n-1]元素进行递增简单选择排序
{	int i,j,k;
	int tmp;
	for (i=0;i<n-1;i++)			//进行n-1趟排序
	{	k=i;					//用k记录每趟无序区中最小元素的位置
		for (j=i+1;j<n;j++)		//在a[i+1..n-1]中采用穷举法找最小元素a[k]
			if (a[j]<a[k]) 
				k=j;	
		if (k!=i)				//若a[k]不是最小元素
		{	tmp=a[i];			//将a[k]与a[i]交换
			a[i]=a[k]; a[k]=tmp;
		}
	}
}
void disp(int a[],int n)		//输出a中所有元素
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("排序前:"); disp(a,n);
	SelectSort(a,n);
	printf("排序后:"); disp(a,n);
}
