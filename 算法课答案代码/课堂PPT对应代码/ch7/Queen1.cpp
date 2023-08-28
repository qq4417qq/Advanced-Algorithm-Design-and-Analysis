//采用栈求解n皇后问题的算法
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct
{	int q[MaxSize];					//q[i]存放第i个皇后的列号
	int top;						//栈顶指针
} StackType;						//定义顺序栈类型
void dispasolution(StackType st)   	//输出一个解
{	static int count=0;				//静态变量用于统计解个数
	int i;
	printf("  第%d个解:",++count);
	for (i=1;i<=st.top;i++)
		printf("(%d,%d) ",i,st.q[i]);
	printf("\n");
}
int place(StackType st,int k,int j)	//测试(k,j)是否与1～k-1的皇后有冲突
{	int i=1;
	if (k==1) return 1;				//放第一个皇后时没有冲突
	while (i<=k-1)					//测试与前面已放置的皇后是否有冲突
	{	if ((st.q[i]==j) || (abs(j-st.q[i])==abs(i-k)))
			return 0;				//有冲突时返回0
		i++;
	}
	return 1;
}
void Queens(int n)					//求解n皇后问题
{	int k,j,find;
	StackType st;					//定义栈st
	st.top=0;						//初始化栈顶指针,为了让皇后从第1行开始,不用下标0
	st.top++; st.q[st.top]=0;		//将(1,0)进栈
	while (st.top!=0)				//栈不空时循环
	{	k=st.top;					//试探栈顶的第k个皇后
		find=0;
		for (j=st.q[k]+1;j<=n;j++)	//为第k个皇后的找一个合适的位置
			if (place(st,k,j))		//在第k行找到一个放皇后的位置(k,j)
			{	st.q[st.top]=j;		//修改第k个皇后的位置(新列号)
				find=1;				//找到一个新位置后置为1
				break;				//找到后退出for循环
			}
		if (find)					//在第k行找到一个放皇后的位置(k,j)
		{	if (k==n)				//所有皇后均放好,输出一个解
				dispasolution(st);
			else					//还有皇后未放时,将第k+1个皇后进栈
			{	st.top++;
				st.q[st.top]=0;	//新进栈的皇后从第0列开始试探起
			}
		}
		else						//若第k个皇后没有合适位置,回溯
			st.top--;				//即将第k个皇后退栈
	}
}
void main()
{	int n;							//n存放实际皇后个数
	printf("皇后问题(n<20) n=");
	scanf("%d",&n);
	if (n>20)
		printf("n值太大\n");
	else
	{	printf(" %d皇后问题求解如下：\n",n);
		Queens(n);
	}
}
