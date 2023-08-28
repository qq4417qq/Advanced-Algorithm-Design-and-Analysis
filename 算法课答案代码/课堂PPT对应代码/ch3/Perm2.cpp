//递归求解全排列问题
#include <stdio.h>
#define MaxSize 10
void disp(int a[],int n)			//输出一个排列
{	int i;
	for (i=0;i<n;i++)
		printf("%d",a[i]);
	printf(" ");
}
void perm(int a[],int n,int k)
{	int i,j;
	if (k==n)						//当a中所有位置已填数,则输出一个解
		disp(a,n);
	else
		for (i=1;i<=n;i++)			//尝试在a中填入整数i
		{	bool has=false;
			for (j=0;j<k;j++)		//在a[0..k]中出现过i,置has为true
				if (a[j]==i) has=true;
			if (!has)				//若a[0..k]中没有出现过i,则选i
			{	a[k]=i;
				perm(a,n,k+1);		//继续添加下一个位置的整数
			}
		}
}
void main()
{	int n=3;
	int a[MaxSize];
	printf("1～%d的全排序如下:",n);
	perm(a,n,0);
	printf("\n");
}
