//0分，错误
#include <stdio.h>
#include <string.h>
#define MAXN 42								//最多的任务数
#define INF 0x3f3f3f3f							//最大整数∞
#define max(x,y) ((x)>(y)?(x):(y))
#define max3(x,y,z) max(max(x,y),z)
#define min(x,y) ((x)<(y)?(x):(y))
//问题表示
int n,n1=0,n2=0;
int A[MAXN][2],B[MAXN];

int x[MAXN];
int bestf=INF;

void swap(int &x,int &y)						//交换x和y
{	int tmp=x;
	x=y; y=tmp;
}
int solve1(int i,int cpu1,int cpu2,int gpu)		//从第i层开始搜索
{
	int m,k,tcpu1,tcpu2,tgpu;
	if (i==n1)									//到达叶结点,产生一种调度方案
    {
		m=max3(cpu1,cpu2,gpu);
		if (m<bestf)							//找到更优解
			bestf=m;
	}
	else
	{
		for(int j=i;j<n1;j++)					//没有到达叶结点
		{
			swap(x[i],x[j]);					//考虑第i步选择任务x[j]	
			for (k=1;k<=4;k++)					//考虑运行方式
			{
				tcpu1=cpu1; tcpu2=cpu2; tgpu=gpu;
				if (k==1)						//方案1：单个CPU上运行-CPU1
					cpu1+=A[x[i]][0];
				else if (k==2)					//方案1：单个CPU上运行-CPU2
					cpu2+=A[x[i]][0];
				else if (k==3)					//方案3：在CPU1和GPU上同时运行
				{
					m=max(cpu1,gpu)+A[x[i]][1];
					cpu1=gpu=m;
				}
				else if (k==4)					//方案3：在CPU2和GPU上同时运行
				{
					m=max(cpu2,gpu)+A[x[i]][1];
					cpu2=gpu=m;
				}
				m=max3(cpu1,cpu2,gpu);
				if (m<bestf)					//剪枝:仅仅扩展当前总时间小于bestf的结点
					solve1(i+1,cpu1,cpu2,gpu);
				cpu1=tcpu1; cpu2=tcpu2; gpu=tgpu;
			}
			swap(x[i],x[j]);
		}
	}
	//printf("bestf=%d\n",bestf);
	return bestf;
}
int solve2()
{
	int sum=0;
	for (int i=0;i<n2;i++)
		sum+=B[i];
	return sum;
}
int solve()
{
	int bestf=solve1(0,0,0,0);
	int sum=solve2();
	printf("bestf=%d,sum=%d\n",bestf,sum);
	return bestf+sum;

	//return solve1(0,0,0,0)+solve2();
}
int main()
{
	int a,b,c,d;
	scanf("%d",&n);
	for(int k=0; k<n; k++)  					//设置初始调度为作业0,1,…,n-1的顺序
		x[k]=k;
	for (int i=0;i<n;i++)
	{ 
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int m1=min(a,c);
		int m2=min(b,d);
		if (m1<=m2)
		{
			//printf("i=%d->A\n",i);
			A[n1][0]=a;			//CPU
			A[n1][1]=c;			//CPU+GPU
			n1++;
		}
		else
		{
			//printf("i=%d->B\n",i);
			B[n2++]=m2;
		}
		//for (int i1=0;i1<n1;i1++)
		//	printf("i1=%d 0: %d 1:%d\n",i1,A[i1][0],A[i1][1]);
	}
	//printf("n1=%d,n2=%d\n",n1,n2);
	printf("%d\n",solve());
	return 0;
}
