//求解资源分配问题的算法
#include <stdio.h>
#define MAXK 10				//最多项目数
#define MAXS 10				//最多投入的人数
int Plan(int v[][MAXS],int d[][MAXS],int K,int S)	//求最优方案d
{	int x,s,k;
	int maxf;
	int f[MAXK][MAXS];
	for (s=0;s<=S;s++)			//置边界条件
		f[K][s]=0;
	for (k=K-1;k>=1;k--)		//从阶段3到1进行处理
	{	for (s=0;s<=S;s++)		//将各人数分配给第k个商店
		{	maxf=0;
			for (x=0;x<=s;x++)	//找该商店最优分配人数x
			{	if ((v[k][x]+f[k+1][s-x])>=maxf)
				{	maxf=v[k][x]+f[k+1][s-x];
					d[k][s]=x;
				}
			}
			f[k][s]=maxf;
		}
	}
	return f[1][S];			//返回总赢利
}
void dispPlan(int max,int d[][MAXS],int K,int S) //输出最优分配方案
{	int k,r,s;
	s=d[1][S];
	r=S-s;					//r为余下的人数
	printf("最优资源分配方案如下:\n");
	for (k=1;k<K;k++)
	{	printf("  %c商店分配%d人\n",'A'+k-1,s);
		s=d[k+1][r];			//求下一个阶段分配的人数
		r=r-s;				//余下人数递减
	}
	printf("该分配方案的总赢利为%d万元\n",max);
}
void main()
{	int v[MAXK][MAXS]={{0,0,0,0,0,0},{0,3,7,9,12,13},
		{0,5,10,11,11,11},{0,4,6,11,12,12}}; //不计v[0]行
	int d[MAXK][MAXS],max;
	int K=4,S=5;				//阶段数为K,总人数为S
	max=Plan(v,d,K,S);
	dispPlan(max,d,K,S);
}
