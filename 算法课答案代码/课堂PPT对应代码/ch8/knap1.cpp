//采用优先队列式分枝限界法求解求解0/1背包问题的算法
#include <stdio.h>
#define MAXN 20					//最多可能物品数
#define MAXQ 50					//优先队列（堆）大小
double maxv;					//存放最大价值,全局变量
int maxx[MAXN];					//存放最优解,全局变量
int count=1;					//搜索空间中结点数累计,全局变量
typedef struct
{	int no;						//结点编号
	int i;						//该结点在搜索空间中的层次
	int w;						//总重量
	double v;					//总价值
	int x[MAXN];				//解向量
	double ub;					//上界
} ElemType;						//堆中的结点类型
typedef struct
{	ElemType data[MAXQ];		//堆中结点从下标1开始存放
	int num;					//堆中结点个数
} HeapType;						//堆类型
void copyx(int x[],int y[],int i)//将解向量x复制到y
{	int j;
	for (j=1;j<=i;j++)
		y[j]=x[j];
}
void elemcopy(ElemType a,ElemType &b)	//队列结点a复制到b
{	b.no=a.no;
	b.i=a.i;	b.ub=a.ub;
	b.w=a.w;	b.v=a.v;
	copyx(a.x,b.x,a.i);
}
//--------大根堆运算算法-----------------------
void swap(ElemType &a,ElemType &b)		//a和b结点交换
{	ElemType tmp;
	elemcopy(a,tmp);
	elemcopy(b,a);
	elemcopy(tmp,b);
}
void initHeap(HeapType &heap)			//大根堆初始化
{
	heap.num=0;							//空堆结点个数为0
}
int emptyHeap(HeapType heap)			//判断是否为空堆
{
	return heap.num==0;
}
void delHeap(HeapType &heap,ElemType &e)	//删除堆顶结点e并调整为堆
{	int i,j;
	bool done=false;
	elemcopy(heap.data[1],e);				//取堆顶结点
	elemcopy(heap.data[heap.num],heap.data[1]);//将最后一个结点移动堆顶
	heap.num--;								//减少一个堆结点
	i=1;j=2*i;
	while (!done && j<=heap.num)
	{	if (j<heap.num && heap.data[j].ub<heap.data[j+1].ub)
			j++;							//若右孩子较大,把j指向右孩子
		if (heap.data[i].ub<heap.data[j].ub)
		{	swap(heap.data[i],heap.data[j]);//与双亲结点交换
			i=j;							//修改i和j值,以便继续向下筛选
			j=2*i;
		}
		else done=true;						//调整结束
	}
}
void insertHeap(HeapType &heap,ElemType e,int n)	//插入一个结点并调整为大根堆
{	bool done=false;
	int j;
	if (e.i==n)								//可行叶子结点,不进队
	{	if (e.v>maxv)						//比较找最优解
		{	maxv=e.v;						//保存最优解的总价值
			copyx(e.x,maxx,n);				//保存最优解的解向量
		}
	}
	else									//不为叶子结点,进队
	{	heap.num++; 						//堆中结点个数增1
		elemcopy(e,heap.data[heap.num]);	//元素e插入到尾部
		j=heap.num;
		if (j!=1)							//堆中至少在两个结点时才需要调整
		{	while (!done && j!=1)			//堆中从下向上调整
			{	if(heap.data[j].ub>heap.data[j/2].ub)	//孩子结点大于双亲
					swap(heap.data[j],heap.data[j/2]);	//交换
				else
					done=true;				//若已满足大根堆要求,调整结束
				j=j/2;
			}
		}
	}
}
//--------大根堆运算算法结束--------------------
void bound(int w[],int v[],int W,int n,ElemType &e)	 //计算分枝结点e的上界
{	int i=e.i+1;
	int sumw=e.w;
	double sumv=e.v;
	while ((sumw+w[i]<=W) && i<=n)
	{	sumw+=w[i];				//计算背包已装入载重
		sumv+=v[i];				//计算背包已装入价值
		i++;
	}
	if (i<=n)
		e.ub=sumv+(W-sumw)*v[i]/w[i];
	else
		e.ub=sumv;
}
void knap(int w[],int v[],int W,int n)	//求0/1背包问题的最优解
{	int j;						//i为搜索空间的层次,从第0层开始
	int ew=0,ev=0;
	HeapType heap;				//建立一个堆
	initHeap(heap);				//堆初始化
	ElemType e,e1,e2;
	e.i=0;						//根结点置初值
	e.w=0; e.v=0;
	e.no=count++; 
	for (j=1;j<=n;j++)
		e.x[j]=0;
	bound(w,v,W,n,e);			//求根结点的上界
	insertHeap(heap,e,n);		//根结点进队
	while (!emptyHeap(heap))	//队不空循环
	{	delHeap(heap,e);		//出队结点e
		if (e.w+w[e.i+1]<=W)	//检查左孩子结点
		{	e1.no=count++; 
			e1.i=e.i+1;			//建立左孩子结点
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1.i];
			copyx(e.x,e1.x,e.i);
			e1.x[e1.i]=1;
			bound(w,v,W,n,e1);	//求左孩子结点的上界
			insertHeap(heap,e1,n);
		}
		e2.no=count++; 
		e2.i=e.i+1;				//建立右孩子结点
		e2.w=e.w; e2.v=e.v;
		copyx(e.x,e2.x,e.i);
		e2.x[e2.i]=0;
		bound(w,v,W,n,e2);		//求右孩子结点的上界
		if (e2.ub>maxv)			//若右结点可行,则右结点进队
			insertHeap(heap,e2,n);
	}
}
void dispknap(int n)			//输出最优解
{	int i;
	printf("分枝限界法求解0/1背包问题:\nX=[");
	for(i=1;i<=n;i++)
		printf("%2d",maxx[i]);	//输出所求X[n]数组
	printf("]，装入总价值%g\n",maxv);
}
void main()
{	int n,W;
	int w[]={0,16,15,15}; n=3;
	int v[]={0,45,25,25}; W=30;
	knap(w,v,W,n);				//调用优先队列式分枝限界法求0/1背包问题
	dispknap(n);				//输出最优解
}
