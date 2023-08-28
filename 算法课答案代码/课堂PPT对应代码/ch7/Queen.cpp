//不采用栈求解n皇后问题的算法
#include <stdio.h>
#include <stdlib.h>
const int MAXN=20;				//最多皇后个数
int q[MAXN];					//存放各皇后所在的行号,为全局变量
void dispasolution(int n)   	//输出一个解
{	static int count=0;			//静态变量用于统计解个数
	int i;
	printf("  第%d个解:",++count);
	for (i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
int place(int k)				//测试第k行的q[k]列上能否摆放皇后
{	int i=1;
	while (i<k)					//i=1～k-1是已放置了皇后的行
	{	if ((q[i]==q[k]) || (abs(q[i]-q[k])==abs(i-k))) 
			//该皇后是否与以前皇后同列，位置(i,q[i])与(k,q[k])是否同对角线
			return 0;
		i++;
	}
	return 1;
}
void Queens(int n)					//求解n皇后问题
{	int k=1;						//k表示当前行,也表示放置第k个皇后
	q[k]=0;							//q[k]是当前列,从0列即开头试探
	while (1)						//重复试探
	{	q[k]=q[k]+1;				//试探下一列的位置,因为初始列从0开始
		while (q[k]<=n && !place(k))//试探一个位置(k,q[k])
			q[k]=q[k]+1;
		if (q[k]<=n)				//为第k个皇后找到了一个合适位置(k,q[k])
		{	if (k==n)				//若放置了所有皇后,输出一个解
				dispasolution(n);
			else					//皇后没有放置完
			{	k++;				//转向下一行,即开始下一个皇后的放置
				q[k]=0;				//每次放一个新皇后,都从该行的列头进行试探
			}
		}
		else						//若第k个皇后找不到合适的位置,则回溯到上一个皇后
		{	if (k==1) exit(0);		//若回溯超界即所有回溯完成，算法结束
			k--;					//回溯到上一个皇后
		}
	}
}
void main()
{	int n;				//n存放实际皇后个数
	printf("皇后问题(n<20) n:");
	scanf("%d",&n);
	if (n>20)
		printf("n值太大\n");
	else
	{	printf("%d皇后问题求解如下:\n",n);
		Queens(n);
	}
}
