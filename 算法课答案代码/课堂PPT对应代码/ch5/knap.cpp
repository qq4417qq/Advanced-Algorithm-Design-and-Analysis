//求解背包问题的算法
#include <stdio.h>
#define MaxSize 20
int Partition(double w[],double v[],int s,int t) //划分算法
{	int i=s,j=t;
	double tmp1=w[s],tmp2=v[s];	//用第1个物品作为基准
	while (i!=j)				//从两端交替向中间扫描,直至i=j为止
	{	while (j>i && v[j]/w[j]<=tmp2/tmp1)
			j--;				//从右向左扫描
		w[i]=w[j]; v[i]=v[j];	//将w[j]、v[j]前移
		while (i<j && v[i]/w[i]>=tmp2/tmp1)
			i++;				//从左向右扫描
		w[j]=w[i]; v[j]=v[i];	//将w[i]、v[i]后移
	}
	w[i]=tmp1; v[i]=tmp2;
	return i;
}
void QuickSort(double w[],double v[],int s,int t)	//对w、v按v/w进行递减排序
{	int i;
	if (s<t) 					//至少存在2个物品的情况
	{	i=Partition(w,v,s,t);
		QuickSort(w,v,s,i-1);	//对左部分递归排序
		QuickSort(w,v,i+1,t);	//对右部分递归排序
	}
}
double knap(double W,double w[],double v[],int n,double x[]) //求解背包问题并返回总价值
{	int i;
	double V=0;					//V为总价值
	double weight=W;			//背包中能装入的余下重量
	for (i=0;i<n;i++)			//初始化x向量
		x[i]=0;
	i=0;
	while (w[i]<weight)			//物品i能够全部装入时循环
	{	x[i]=1;					//装入物品i
		weight-=w[i];			//减少背包中能装入的余下重量
		V+=v[i];				//累计总价值
		i++;					//继续循环
	}
	if (weight>0)				//当余下重量大于0
	{	x[i]=weight/w[i];		//将物品i的一部分装入
		V+=x[i]*v[i];			//累计总价值
	}
	return V;					//返回总价值
}
void disp(double a[],int n)		//输出a中的n个元素
{	int i;
	for (i=0;i<n;i++)
		printf("%g\t",a[i]);
	printf("\n");
}
void main()
{	int n=5,i;
	double x[MaxSize];
	double W=100,V;
	double w[]={10,20,30,40,50};
	double v[]={20,30,66,40,60};
	QuickSort(w,v,0,n-1);
	printf("按v/w递减排序并求解:\n");
	printf("i: "); 
	for (i=0;i<n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("v: "); disp(v,n);
	printf("w: "); disp(w,n);
	V=knap(W,w,v,n,x);
	printf("x: "); disp(x,n);
	printf("总价值=%g\n",V);
}
