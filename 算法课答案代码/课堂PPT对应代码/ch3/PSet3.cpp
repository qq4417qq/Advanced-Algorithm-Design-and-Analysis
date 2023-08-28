//递归求解幂集问题
#include <stdio.h>
#define Maxn 10						//最大的n值
#define MaxSize 1000				//最大的子集个数
typedef struct						//定义幂集类型
{	int data[MaxSize][Maxn];		//data[i][0]表示该子集的长度
	int n;							//子集个数
} PSetType;
void copy(int a[],int b[],int m)	//a[0..m]复制到b[0..m]
{	int i;
	for (i=0;i<=m;i++)
		b[i]=a[i];
}
void addi(PSetType &p,int i)		//向幂集p中所有子集添加i产生新子集并插入到p中
{	int j,m;
	int a[Maxn];
	m=p.n; 
	for (j=0;j<m;j++)				//处理p中原有的所有子集
	{	copy(p.data[j],a,p.data[j][0]);
		a[0]++;						//子集的长度增1
		a[a[0]]=i;					//子集尾添加i
		copy(a,p.data[p.n],a[0]);	//该子集插入到幂集中
		p.n++;						//幂集中子集个数增1
	}
}
void disp(PSetType p)				//输出幂集
{	int i,j;
	for (i=0;i<p.n;i++)
	{	printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
			printf("%d ",p.data[i][j]);
		printf("} ");
	}
}
void pset(int i,int n,PSetType p)	//输出1～n的幂集
{	if (i>n)						//满足递归出口条件，输出幂集
	{	printf("1～%d的幂集如下:",n);
		disp(p); printf("\n");
	}
	else
	{	addi(p,i);				//将i插入到现有子集中产生新子集
		pset(i+1,n,p);			//递归调用
	}
}
void main()
{	int n=3;
	PSetType p;					//定义幂集
	p.data[0][0]=0; p.n=1;			//幂集置初始空集
	pset(1,n,p);					//输出1～n的幂集
}
