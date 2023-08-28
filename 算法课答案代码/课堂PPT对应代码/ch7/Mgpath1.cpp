//采用回溯法非递归框架求解迷宫问题的算法
#include <stdio.h>
#define M 6
#define N 6
#define MaxSize 20					//栈最多元素个数
typedef struct
{	int i;							//当前方块的行号
	int j;							//当前方块的列号
	int di;							//当前方块的下一个可走方块的方位
} Box;								//声明一个方块的类型
typedef struct
{	Box data[MaxSize];				//存放栈中方块
	int top;						//栈顶指针
} StackType;						//声明顺序栈类型
void dispapath(StackType st)		//输出一条迷宫路径
{	static int count=0;				//静态变量用于统计迷宫路径总数
	int k;
	printf("第%d条迷宫路径:\n",++count);
	for (k=0;k<=st.top;k++)
		printf("(%d,%d)  ",st.data[k].i,st.data[k].j);
	printf("\n");
}
void mgpath(int mg[M][N],int xi,int yi,int xe,int ye)
//求(xi,yi)->(xe,ye)的所有迷宫路径
{	int i,j,i1,j1,di,find;
	StackType st;					//定义一个顺序栈
	st.top=-1;						//栈顶指针初始化
	st.top++;						//入口进栈
	st.data[st.top].i=xi;  st.data[st.top].j=yi;
	st.data[st.top].di=-1;	mg[xi][yi]=-1;
	while (st.top>-1)				//栈不空时循环
	{	i=st.data[st.top].i; j=st.data[st.top].j;
		di=st.data[st.top].di;		//取栈顶方块
		if (i==xe && j==ye)			//找到了出口,输出该路径
		{	dispapath(st);			//找到一条路径输出并退栈以便找下一条路径
			mg[i][j]=0;				//回溯:让出口变为其他路径可走方块
			st.top--;				//出口退栈
			i=st.data[st.top].i; j=st.data[st.top].j;
			di=st.data[st.top].di;	//取栈顶方块
		}
		find=0;
		while (di<4 && find==0)		//找(i,j)方块的一个相邻可走方块
		{	di++;
			switch(di)
			{
			case 0:i1=st.data[st.top].i-1;j1=st.data[st.top].j;break;
			case 1:i1=st.data[st.top].i;  j1=st.data[st.top].j+1;break;
			case 2:i1=st.data[st.top].i+1;j1=st.data[st.top].j;break;
			case 3:i1=st.data[st.top].i,  j1=st.data[st.top].j-1;break;
			}
			if (mg[i1][j1]==0) find=1;
		}
		if (find==1)				//找到了一个相邻可走方块(i1,j1)
		{	st.data[st.top].di=di;	//修改原栈顶元素的di值
			st.top++;
			st.data[st.top].i=i1; st.data[st.top].j=j1;
			st.data[st.top].di=-1;	//将相邻可走方块(i1,j1)方块进栈
			mg[i1][j1]=-1;			//避免重复走到该方块
		}
		else						//(i,j)再没有路径可走,则退栈
		{	mg[i][j]=0;				//回溯:恢复(i,j)方块为可走方块
			st.top--;				//退栈
		}
	}
}
void main()
{	int mg[M][N]={ {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
			 {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1} };
	mgpath(mg,1,1,4,4);	//求入口(1,1)到出口(4,4)的所有迷宫路径
}
