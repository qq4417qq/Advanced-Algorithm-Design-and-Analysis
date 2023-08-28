//求解幂集问题-解法1
#include <stdio.h>
#include <math.h>
#define MaxN 10
void change(int b[],int n);
void pset(int a[],int b[],int n)
{	int i,k;
	int pw=pow(2,n);			//求2n
	printf("集合a的所有子集:");
	for(i=0;i<pw;i++)			//执行2n次
	{	printf("{ ");
		for (k=0;k<n;k++)		//执行n次
			if(b[k])
				printf("%d ",a[k]);
		printf("} ");
		change(b,n);			//b表示的二进制数增1
	}
	printf("\n");
}
void change(int b[], int n)		//改变b数组，将b表示的二进制数增1
{	int i;
	for(i=0;i<n;i++)			//遍历数组b
	{	if(b[i])				//将元素1改为0
			b[i]=0;
		else					//将元素0改为1并退出for循环
		{	b[i]=1;
			break;
		}
	}
}
void main()
{	int n=3,i;
	int a[MaxN],b[MaxN];
	for (i=0;i<n;i++)
	{	a[i]=i+1;				//a初始化为{1,2,3}
		b[i]=0;				//b初始化为{0,0,0}
	}
	pset(a,b,n);
}
