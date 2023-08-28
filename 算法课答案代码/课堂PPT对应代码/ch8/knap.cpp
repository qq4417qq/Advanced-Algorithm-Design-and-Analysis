//采用队列式分枝限界法求解0/1背包问题的算法
#include <stdio.h>
#define MAXN 20						//最多可能物品数
#define MAXQ 50						//队列大小
int maxv;							//存放最大价值,全局变量
int maxx[MAXN];						//存放最优解,全局变量
int count=1;						//搜索空间中结点数累计,全局变量
typedef struct
{	int no;							//结点编号
	int i;							//当前结点在搜索空间中的层次
	int w;							//当前结点的总重量
	double v;						//当前结点的总价值
	int x[MAXN];					//当前结点包含的解向量
	double ub;						//上界
} ElemType;							//队列中的结点类型
typedef struct
{	ElemType data[MAXQ];
	int front,rear;					//队头队尾指针
} QueueType;						//队列类型
void copyx(int x[],int y[],int i) 	//解向量x复制到y
{	int j;
	for (j=1;j<=i;j++)
		y[j]=x[j];
}
void elemcopy(ElemType a,ElemType &b) //队列结点a复制到b
{	b.no=a.no; b.i=a.i;
	b.ub=a.ub; b.w=a.w;
	b.v=a.v;
	copyx(a.x,b.x,a.i);				//复制解向量
}
//------------队列基本运算-----------------------
void initQueue(QueueType &q)		//队列初始化
{
	q.front=q.rear=0;
}
int emptyQueue(QueueType q)			//判队空
{
	return q.front==q.rear;
}
int enQueue(QueueType &q,ElemType e,int n)	//结点e进队
{	if ((q.rear+1)%MAXQ==q.front)	//队满
		return 0;
	else
	{	if (e.i==n)					//可行叶子结点,不进队
		{	if (e.v>maxv)			//比较找最优解
			{	maxv=e.v;
				copyx(e.x,maxx,n);
			}
		}
		else						//其他结点进队
		{	q.rear=(q.rear+1)%MAXQ;
			elemcopy(e,q.data[q.rear]);
		}
		return 1;
	}
}
int deQueue(QueueType &q,ElemType &e)//结点e出队
{	if (emptyQueue(q))				//队空
		return 0;
	else
	{	q.front=(q.front+1)%MAXQ;
		elemcopy(q.data[q.front],e);
		return 1;
	}
}
//------------队列基本运算结束-------------------
void bound(int w[],int v[],int W,int n,ElemType &e) //计算分枝结点e的上界
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
//----------------------------------
void knap(int w[],int v[],int W,int n)	//求0/1背包的最优解
{	int j;
	QueueType q;					//建立一个队列
	initQueue(q);					//队列初始化
	ElemType e,e1,e2;				//定义3个结点
	e.i=0;							//根结点置初值，其层次计为0
	e.w=0; e.v=0;
	e.no=count++; 
	for (j=1;j<=n;j++)
		e.x[j]=0;
	bound(w,v,W,n,e);				//求根结点的上界
	enQueue(q,e,n);					//根结点进队
	while (!emptyQueue(q))			//队不空循环
	{	deQueue(q,e);				//出队结点e
		if (e.w+w[e.i+1]<=W)		//检查左孩子结点
		{	e1.no=count++; 
			e1.i=e.i+1;				//建立左孩子结点
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1.i];
			copyx(e.x,e1.x,e.i);
			e1.x[e1.i]=1;
			bound(w,v,W,n,e1);		//求左孩子结点的上界
			enQueue(q,e1,n);
		}
		e2.no=count++; 
		e2.i=e.i+1;					//建立右孩子结点
		e2.w=e.w; e2.v=e.v;
		copyx(e.x,e2.x,e.i);
		e2.x[e2.i]=0;
		bound(w,v,W,n,e2);			//求右孩子结点的上界
		if (e2.ub>maxv)				//若右孩子结点可行,则进队,否则被剪枝
			enQueue(q,e2,n);
	}
}
void dispknap(int n)				//输出最优解
{	int i;
	printf("分枝限界法求解0/1背包问题:\n  X=[");
	for(i=1;i<=n;i++)
		printf("%2d",maxx[i]);		//输出所求X[n]数组
	printf("]，装入总价值为%d\n",maxv);
}
void main()
{	int n=3,W=30;
	int w[]={0,16,15,15};			//重量，不计下标0的元素
	int v[]={0,45,25,25};  			//价值，不计下标0的元素
	knap(w,v,W,n);					//调用队列式分枝限界法求0/1背包问题
	dispknap(n);					//输出最优解
}
