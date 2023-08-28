//递归求解组合列问题
#include <stdio.h>
#define MAXK 10
int n,k;						//全局变量
void dispcomb(int a[])			//输出一个组合
{	int j;
for (j=0;j<k;j++)
printf("%3d",a[j]);
printf("\n");
}
void comb(int a[],int n,int k)	//求1..n中k个整数的组合
{	int i;
	if (k==0)					//k为0时输出一个组合
		dispcomb(a);
	else
	{	for (i=k;i<=n;i++)
		{	a[k-1]=i;			//a[k-1]位置取k～n的整数
			comb(a,i-1,k-1); 	//a[k-1]组合a[0..i-1]中的k-1个整数产生一个组合
		}
	}
}
void main()
{	int a[MAXK];
n=5; k=3;
printf("1..%d中%d个的整数的所有组合:\n",n,k);
comb(a,n,k);
}
