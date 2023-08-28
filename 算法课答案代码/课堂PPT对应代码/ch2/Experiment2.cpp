//上机实验题2
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef struct node
{	char data;					//数据元素
	struct node *lchild;			//指向左孩子结点
	struct node *rchild;			//指向右孩子结点
} BTNode;							//二叉链存储结构结点类型定义
//二叉链用根结点指针b来唯一标识
void CreateBTNode(BTNode * &b,char *str)	//由括号表示串创建二叉链
{	BTNode *St[MaxSize],*p;
	int top=-1,k,j=0;
	char ch;
	b=NULL;						//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')				//循环扫描str中每个字符
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//开始处理左孩子结点
		case ')':top--;break;
		case ',':k=2; break;				//开始处理右孩子结点
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)				//若尚未建立根结点
					b=p;					//*p为二叉树的根结点
				else						//已建立二叉树根结点
				{	switch(k)
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DestroyBTNode(BTNode *&b)	//释放以*b为根结点的二叉树
{	if (b!=NULL)
	{	DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
void DispBTNode(BTNode *b)		//输出二叉树
{	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");
			DispBTNode(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}
/*
BTNode *Find(BTNode *b,char x,BTNode *p,int tag)
//查找值为x的结点,p为该找到结点的双亲,初值为NULL,tag=1表示*b为*p的左孩子,tag=2表示*b为*p的右孩子
{
	BTNode *q;
	if (b==NULL)
		return NULL;
	else if (b->data==x)
	{
		if (p!=NULL)
		{
			if (tag==1)
				p->lchild=NULL;
			else
				p->rchild=NULL;
		}
		return b;
	}
	else
	{
		q=Find(b->lchild,x,b,1);
		if (q!=NULL)
			return q;
		else
			return Find(b->rchild,x,b,2);
	}
}
*/
BTNode *Find(BTNode *&b,char x)
//查找值为x的结点并返回,若不为根结点，将其双亲的相应指针域置为NULL
{
	BTNode *p;
	if (b==NULL)
		return NULL;
	else if (b->data==x)
		return b;
	else if (b->lchild!=NULL && b->lchild->data==x)
	{
		p=b->lchild;
		b->lchild=NULL;
		return p;
	}
	else if (b->rchild!=NULL && b->rchild->data==x)
	{
		p=b->rchild;
		b->rchild=NULL;
		return p;
	}
	else
	{
		p=Find(b->lchild,x);
		if (p!=NULL)
			return p;
		else
			return Find(b->rchild,x);
	}
}
bool Delete(BTNode *&b,char x)	//删除并释放值x的结点的子树
{
	BTNode *p;
	p=Find(b,x);
	if (p!=NULL)
	{
		if (p==b)	//p指向根结点
		{
			DestroyBTNode(p);
			return false;
		}
		else
		{
			DestroyBTNode(p);
			return true;
		}
	}
	else return true;
}
		
void main()
{	char *str= "A(B(D(,G)),C(E,F))";
	char x='D';
	BTNode *b;
	printf("str:%s\n",str);
	printf("由str创建二叉链存储结构b\n");
	CreateBTNode(b,str);
	printf("b:"); DispBTNode(b); printf("\n");
	if (Delete(b,x))
	{
		printf("删除以%c为根结点的子树\n",x);
		printf("b:"); DispBTNode(b); printf("\n");
		printf("销毁二叉链\n");
		DestroyBTNode(b);
	}
	else
		printf("删除整棵二叉树\n");
}
