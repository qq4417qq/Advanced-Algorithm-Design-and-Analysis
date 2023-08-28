//求解哈夫曼编码的算法
#include <stdio.h>
#define MAXN 20				//最多的字符个数
typedef struct
{	char data;				//结点值
	double weight;			//权重
	int parent;				//双亲结点
	int lchild;				//左孩子结点
	int rchild;				//右孩子结点
} HTNode;					//哈夫曼树的结点类型
typedef struct
{	char cd[MAXN];			//存放当前结点的哈夫曼码
	int start;				//cd[0..start]存放哈夫曼码
} HCode;					//哈夫曼编码的类型
void CreateHTree(HTNode ht[],int n)	//构造哈夫曼树
{	int i,j,lnode,rnode;
	double min1,min2;
	for (i=0;i<=2*n-2;i++)			//所有结点的相关域置初值-1
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n;i<=2*n-2;i++)			//构造哈夫曼树
	{	min1=min2=32767;			//lnode和rnode为最小权值的两个结点的下标
		lnode=rnode=-1;
		for (j=0;j<=i-1;j++)		//在ht[]中找权值最小的两个结点
			if (ht[j].parent==-1)	//只在根结点中查找
			{	if (ht[j].weight<min1)
				{	min2=min1; rnode=lnode;
					min1=ht[j].weight; lnode=j;
				}
				else if (ht[j].weight<min2)
				{	min2=ht[j].weight; rnode=j;	}
			}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;	//ht[i]作为双亲结点
		ht[lnode].parent=i; ht[rnode].parent=i;
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n) //根据哈夫曼树求哈夫曼编码
{	int i,f,c;
	for (i=0;i<n;i++)				//产生每个叶子结点的哈夫曼编码
	{	hcd[i].start=n-1;			//哈夫曼编码从cd的n-1下标开始放置
		c=i;						//c初值指要产生编码的结点
		f=ht[i].parent;
		while (f!=-1)				//循环直到无双亲结点即到达树根结点
		{	if (ht[f].lchild==c)	//当前结点是双亲结点的左孩子结点
				hcd[i].cd[hcd[i].start--]='0';
			else					//当前结点是双亲结点的右孩子结点
				hcd[i].cd[hcd[i].start--]='1';
			c=f;f=ht[f].parent;		//再对双亲结点进行同样的操作
		}
		hcd[i].start++;				//start指向哈夫曼编码最开始的二进制位
	}
}
void dispHCode(HTNode ht[],HCode hcd[],int n)	//输出哈夫曼编码
{	int i,j;
	for (i=0;i<n;i++)
	{	printf("  %c:",ht[i].data);
		for (j=hcd[i].start;j<n;j++)
			printf("%c",hcd[i].cd[j]);
		printf("\n");
	}
}
void main()
{	int n=5;
	HTNode ht[2*MAXN-1];
	HCode hcd[MAXN];
	ht[0].data='a'; ht[0].weight=4;		//置初值即n个叶子结点
	ht[1].data='b'; ht[1].weight=2;  
	ht[2].data='c'; ht[2].weight=1;  
	ht[3].data='d'; ht[3].weight=7;  
	ht[4].data='e'; ht[4].weight=3;  
	CreateHTree(ht,n);					//建立哈夫曼树
	CreateHCode(ht,hcd,n);				//求哈夫曼编码
	printf("产生的哈夫曼编码如下:\n");
	dispHCode(ht,hcd,n);				//输出哈夫曼编码
}
