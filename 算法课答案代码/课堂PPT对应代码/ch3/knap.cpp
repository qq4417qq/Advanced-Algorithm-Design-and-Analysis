//求解0/1背包问题
#include <stdio.h>
#define Maxn 10							//最大的n值
#define MaxSize 1000					//最大的子集个数
typedef struct							//定义幂集类型
{	int data[MaxSize][Maxn];			//data[i][0]表示该子集的长度
	int n;								//子集个数
} PSetType;
void copy(int a[],int b[],int m)		//将a[0..m]复制到b[0..m]
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
void knap(PSetType p,int w[],int v[],int W)	//求所有的方案和最佳方案
{	int i,j;
	int sumw,sumv;
	int maxi,maxsumw=0,maxsumv=0;
	printf("  序号\t选中物品\t总重量\t总价值\t能否装入\n");
	for (i=0;i<p.n;i++)
	{	printf("  %d\t",i+1);
		sumw=sumv=0;
		printf("{ ");
		for (j=1;j<=p.data[i][0];j++)
		{	printf("%d ",p.data[i][j]);
			sumw+=w[p.data[i][j]-1];
			sumv+=v[p.data[i][j]-1];
		}
		printf("}\t\t%d\t%d\t",sumw,sumv);
		if (sumw<=W)
		{	printf("能\n");
			if (sumv>maxsumv)
			{	maxsumw=sumw;
				maxsumv=sumv;
				maxi=i;
			}
		}
		else printf("否\n");
	}
	printf("最佳方案为 ");
	printf("选中物品:");
	printf("{ ");
	for (j=1;j<=p.data[maxi][0];j++)
		printf("%d ",p.data[maxi][j]);
	printf("},");
	printf("总重量:%d,总价值:%d\n",maxsumw,maxsumv);
}
void main()
{	int n=4,W=7;
	int w[]={5,3,2,1};
	int v[]={4,4,3,1};
	PSetType p;
	pset(n,p);
	printf("0/1背包的求解方案\n",n);
	knap(p,w,v,W); printf("\n");
}
