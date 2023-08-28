//求解幂集问题-解法2
#include <stdio.h>
#define Maxn 10						//最大的n值
#define MaxSize 1000					//最大的子集个数
typedef struct						//定义幂集类型
{	int data[MaxSize][Maxn];			//data[i][0]表示该子集的长度
	int n;							//子集个数
} PSetType;
void copy(int a[],int b[],int m)			//将a[0..m]复制到b[0..m]
{	int i;
	for (i=0;i<=m;i++)
		b[i]=a[i];
}
void pset(int n,PSetType &p)			//求1～n的幂集p
{	int i,j,m;
	int a[Maxn];						//a用于保存一个子集
	p.data[0][0]=0; p.n=1;				//置初值空集{}
	for (i=1;i<=n;i++)					//循环添加1～n
	{	m=p.n; 							//求原幂集中的子集个数
		for (j=0;j<m;j++)				//将每个子集添加i后插入到幂集中
		{	copy(p.data[j],a,p.data[j][0]);
			a[0]++;						//子集的长度增1
			a[a[0]]=i;					//子集尾添加i
			copy(a,p.data[p.n],a[0]);	//该子集插入到幂集中
			p.n++;						//幂集中子集个数增1
		}
	}
}
void disp(PSetType p)					//输出幂集p
{	int i,j;
	for (i=0;i<p.n;i++)
	{	printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
			printf("%d ",p.data[i][j]);
		printf("} ");
	}
}
void main()
{	int n=3;
	PSetType p;
	pset(n,p);
	printf("1～%d的幂集如下:",n);
	disp(p); printf("\n");
}

