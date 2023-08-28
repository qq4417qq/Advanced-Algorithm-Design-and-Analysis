//求解最大连续子序列和问题的算法
#include <stdio.h>
#define MaxN 20
void maxSubSum(int a[],int b[],int n)	//求b数组
{	int j;
	b[0]=0;
	for (j=1;j<=n;j++)
	{	if (b[j-1]+a[j]>a[j])
			b[j]=b[j-1]+a[j];
		else
			b[j]=a[j];
	}
}
void dispmaxSum(int a[],int b[],int n)	//输出结果
{	int maxj,i,j,k;
	maxj=1;
	for (j=2;j<=n;j++)			//求b中最大元素b[maxj]
		if (b[j]>b[maxj]) maxj=j;
	for (k=maxj;k>=1;k--)		//找前一个值小于等于0者
		if (b[k]<=0) break;
	printf("最大连续子序列和:%d\n",b[maxj]);
	printf("所选子序列:");
	for (i=k+1;i<=maxj;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{	int a[]={0,-2,11,-4,13,-5,-2},n=6;	//a数组不用下标为0的元素
	int b[MaxN];
	maxSubSum(a,b,n);
	dispmaxSum(a,b,n);
}
