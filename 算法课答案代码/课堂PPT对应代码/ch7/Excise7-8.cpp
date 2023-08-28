//练习题8
#include <stdio.h>
#define MAXN 20
#define MAXM 10
int m,n;
int x[MAXM];
int used[MAXN];
void fun(int i)					//求n个元素中m个元素的全排列
{	int j;
	if (i>m)
	{	for (j=1;j<=m;j++)
			printf("%d ",x[j]);	//输出一个排列
		printf("\n");
	}
	else
	{	for (j=1;j<=n;j++)
		{	if (!used[j])
			{	used[j]=1;		//修改used[i]
				x[i]=j;			//记录x[i]
				fun(i+1);		//继续搜索排列的下一个元素
				used[j]=0;		//回溯：还原used[i]
			}
		}
	}
}
void main()
{	m=3,n=5;
	int i;
	for (i=0;i<=n;i++)
		used[i]=0;				//used[i]为1表明第i个元素在当前排列中，反之亦然
	fun(1);
}
