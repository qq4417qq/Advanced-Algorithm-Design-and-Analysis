//上机实验题6
#include <stdio.h>
#define MAXN 20
void display(int a[],int b[],int k)	//回推输出最长单调递增子序列
{
	int i;
	for (i=k-1;i>=0;i--)
	{
		if (b[k]==b[i]+1 && a[i]<=a[k])
		{
			display(a,b,i);
			break;
		}
	}
	printf("%d ",a[k]);
} 
int maxL(int b[],int n) //求数组b中最大值下标
{
	int i,k=0;
	int max=b[0];
	for (i=0;i<n;i++)
	{
		if (max<b[i])
		{
			max=b[i];
			k=i;
		}
	}
	return k;
}  
void Maxsubseq(int a[],int b[],int n)
{
	int i,j,k;
	b[0]=1;
	for (i=1;i<n;i++)
	{
		k=0;
		for (j=0;j<i;j++)
			if (a[j]<=a[i] && k<b[j])
				k=b[j];
		b[i]=k+1;
	}
}
void main()
{
	int a[]={4,5,1,3,6,7,2,9,8};
	int b[MAXN];
	int n=8,k;
	Maxsubseq(a,b,n);
	k=maxL(b,n);
	printf("最长单调递增子序列最后元素下标k=%d\n",k);
	printf("最长单调递增子序列:");
	display(a,b,k);		//输出结果
	printf("\n");
}