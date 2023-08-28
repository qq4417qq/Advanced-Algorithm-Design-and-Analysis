//Hanoi问题非递归算法
#include <stdio.h>
#define MaxSize 100
struct
{	int n;			//保存n值
	char x,y,z;		//保存f(n)值
	int tag;		//标识是否求出f(n)值,1:未求出,0:已求出
} St[MaxSize];		//定义栈
int top=-1;			//栈指针初始化
void Hanoi1(int n,char x,char y,char z)
{	int n1,x1,y1,z1;
	if (n<=0)
	{	printf("参数错误\n");
		return;
	}
	else if (n==1)
	{	printf("将%c上的1个盘片直接移动到%c\n",x,z);
		return;
	}
	top++;
	St[top].n=n;							//初值进栈
	St[top].x=x; St[top].y=y; St[top].z=z; St[top].tag=1;
	while (top>-1)						//栈不空循环
	{	if (St[top].tag==1 && St[top].n>1)	//当不能直接操作时
		{	n1=St[top].n;					//退栈hanoi(n,x,y,z)
			x1=St[top].x; y1=St[top].y; z1=St[top].z;
			top--;
			top++;						//将Hanoi(n-1,y,x,z)进栈
			St[top].n=n1-1; St[top].x=y1; St[top].y=x1; St[top].z=z1;
			if (n1-1==1)					//只有一个盘片时直接操作
				St[top].tag=0;
			else
				St[top].tag=1;
			top++;						//将第n个圆盘从x移到z;
			St[top].n=n1; St[top].x=x1; St[top].z=z1; St[top].tag=0;
			top++;						//将Hanoi(n-1,x,z,y)进栈
			St[top].n=n1-1; St[top].x=x1; St[top].y=z1; St[top].z=y1;
			if (n1-1==1)					//只有一个盘片时直接操作
				St[top].tag=0;
			else
				St[top].tag=1;
		}
		else if	(St[top].tag==0)			//当可以直接操作时
		{	printf("\t将第%d个盘片从%c移动到%c\n",St[top].n,St[top].x,St[top].z);
			top--;						//移动盘片后退栈
		}
	}
}
void main()
{
	int n=3;
	printf("n=%d时Hanoi的步骤如下:\n",n);
	Hanoi1(3,'x','y','z');
}