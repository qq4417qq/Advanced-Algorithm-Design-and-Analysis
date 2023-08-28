//练习题10
#include <stdio.h>  
#define N 10
int b[N+1];			//b[i]=1,表示整数i还没有选取,否则i已选取
int a[10];			//填入数的方阵,用一维数组存放
int checkmatrix[][3]={{-1},{0,-1},{1,-1},	//方阵中每个位置的相邻位置
	{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1}};  
int count=0;
void dispasolution(int a[])	//输出一个解
{	int i,j;
	count++;
	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
			printf("%3d",a[3*i+j]);
		printf("\n");
	}
	printf("\n");
}  
int isprime(int m)			//判断m是否为素数
{	int i;
	if (m==1 || m%2==0) return 0;
	for (i=3;i*i<=m;i+=2)
		if (m%i==0) return 0;
	return 1;
}
int selectnum(int start)	//从start开始选取一个还没有填入的整数
{	int j;
	for (j=start;j<=N;j++)
		if (b[j]) return j;
	return 0;
}
int check(int pos)			//检查a中pos位置的数是否满足要求
{	int i,j;
	if (pos<0) return 0;
	for (i=0;(j=checkmatrix[pos][i])>=0;i++)
		if (!isprime(a[pos]+a[j]))
			return 0;
	return 1;  
}
int extend(int pos)			//为pos的后一个位置选一个新整数
{	a[++pos]=selectnum(1);
	b[a[pos]]=0;
	return pos;
}
int change(int pos)			//回溯到pos的前一个位置
{	int j;
	while (pos>=0 && (j=selectnum(a[pos]+1))==0)
		b[a[pos--]]=1;
	if (pos<0) return -1;
	b[a[pos]]=1;
	a[pos]=j;
	b[j]=0;
	return pos;  
}
void find()					//求所有解
{	int ok=0,pos=0;
	a[pos]=1;
	b[a[pos]]=0;
	do
	{	if (ok)
		{	if (pos==8)		//填入所有整数
			{	dispasolution(a);
				pos=change(pos);
			}
			else pos=extend(pos);
		}
		else pos=change(pos);
		ok=check(pos);
	} while (pos>=0);
} 
void main() 
{	int i;
	for (i=1;i<=N;i++)		//b数组置初值
		b[i]=1;
	find();
	printf("共有%d个解\n",count);
} 
