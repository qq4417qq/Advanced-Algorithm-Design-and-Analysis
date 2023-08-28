//求解全排列问题
#include <stdio.h>
#define Maxn 10						//最大的n值
#define MaxSize 1000
typedef struct						//定义栈元素类型
{	struct
	{	int a[Maxn];					//存放一个排列
		int m;						//存放该排序的元素个数
	} data[MaxSize];
	int top;							//栈顶指针
} StackType;
void insert(int a[],int m,int j,int k)	//在a[1..m]中a[j]处插入k
{	int i;
	for (i=m+1;i>j;i--)				//将a[j..m]元素后移
		a[i]=a[i-1];
	a[j]=k;
}
void disp(int a[],int m)				//输出a[1..m]中元素
{	int i;
	for (i=1;i<=m;i++)
		printf("%d",a[i]);
	printf(" ");
}
void copy(int a[],int b[],int m)			//将a[1..m]复制到b[1..m]
{	int i;
	for (i=1;i<=m;i++)
		b[i]=a[i];
}
void perm(int n)							//输出1～n的所有全排列
{	int j,m;
	int b[Maxn],c[Maxn];					//用于临时存放一个排列
	StackType st;							//定义一个顺序栈
	st.top=-1;							//初始化顺序栈
	st.top++;								//将1进栈
	st.data[st.top].a[1]=1; st.data[st.top].m=1;
	while (st.top!=-1)						//栈不空循环
	{	m=st.data[st.top].m;				//取栈顶元素的m值
		if (m==n)							//找到一种全排列,输出并退栈
		{	disp(st.data[st.top].a,n);
			st.top--;						//退栈
		}
		else								//找到一种部分排序
		{	copy(st.data[st.top].a,c,m);	//取出栈顶排列到c中
			st.top--;						//退栈
			for (j=1;j<=m+1;j++)
			{	copy(c,b,m);				//将c[1..m]中部分排序复制到b中
				insert(b,m,j,m+1);			//将m+1插入到b[j]处
				st.top++;					//将b进栈
				copy(b,st.data[st.top].a,m+1);
				st.data[st.top].m=m+1;
			}
		}
	}
}
void main()
{	int n=3;
	printf("1～%d的全排序如下:",n);
	perm(n); printf("\n");
}

