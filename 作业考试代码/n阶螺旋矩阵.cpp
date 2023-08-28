#include <stdio.h>
#define MAXN 51
int s[MAXN][MAXN];					//存放螺旋矩阵
int n;								//存放螺旋矩阵的大小
void Spiral(int x,int y,int start,int n)	//递归创建螺旋矩阵
{	int  i, j;
	if (n<=0)						//递归结束条件
		return;
	if (n==1)						//矩阵大小为1时
	{	s[x][y] = start;
		return;
	}
	for (i= x; i<x+n-1; i++)			//上一行
		s[y][i]=start++;
	for (j=y; j<y+n-1; j++)				//右一列
		s[j][x+n-1]= start++;
	for (i=x+n-1; i>x; i--)				//下一行
		s[y+n-1][i]= start++;
	for (j=y+n-1; j>y; j--)				//左一列
		s[j][x]=start++;
	Spiral(x+1,y+1,start,n-2);			//递归调用
}
void dispmatrix()			//输出螺旋矩阵		
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
}

int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0) break;
		Spiral(0,0,1,n);
		dispmatrix();
	}
	return 0;
}

