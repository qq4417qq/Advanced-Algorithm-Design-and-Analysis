//采用进一步剪枝求解0/1背包问题的算法
#include <stdio.h>
#define MAXN 20					//最多物品数
int maxv; 						//存放最优解的总价值
int maxw;						//存放最优解的总重量
int x[MAXN];					//存放最终解
void knap(int w[],int v[],int W,int n,int i,int tw,int tv,int op[]) //考虑第i个物品
{	int j,m;
	if (i>n)					//找到一个叶子结点
	{	if (tw<=W && tv>maxv) 	//找到一个满足条件的更优解,保存它
		{	maxv=tv;
			maxw=tw;
			for (j=1;j<=n;j++)
				x[j]=op[j];
		}
	}
	else						//尚未找完所有物品
	{	if (tw+w[i]<W)  		//左孩子结点剪枝：满足条件时才放入第i个物品
		{	op[i]=1;			//选取第i个物品
			knap(w,v,W,n,i+1,tw+w[i],tv+v[i],op);
		}
		op[i]=0;				//不选取第i个物品,回溯
		m=0;
		for (j=0;j<i;j++)		//m累计不选取的物品数
			if (op[j]==0) m++;
		if (m<=1)				//右孩子结点剪枝：至少要选3个物品
			knap(w,v,W,n,i+1,tw,tv,op);
	}
}
void dispasolution(int x[],int n)//输出一个解
{	int i;
	printf("最佳装填方案是:\n");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("  选取第%d个物品\n",i);
	printf("总重量=%d,总价值=%d\n",maxw,maxv);
}
void main()
{	int n=4;					//4种物品
	int W=7;					//限制重量不超过7
	int op[MAXN];				//存放临时解
	int w[]={0,5,3,2,1};		//存放4个物品重量,不用下标0元素
	int v[]={0,4,4,3,1};		//存放4个物品价值,不用下标0元素
	knap(w,v,W,n,1,0,0,op);
	dispasolution(x,n);
}
