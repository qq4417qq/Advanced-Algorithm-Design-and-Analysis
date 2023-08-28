//例2.8
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子结点
	struct node *rchild;		//指向右孩子结点
} BTNode;
void CreateBTNode(BTNode * &b,char *str)	//由str建立二叉链b
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;					//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')  			//str未扫描完时循环
	{	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;	//为左孩子结点
		case ')':top--;break;
		case ',':k=2; break;				//为孩子结点右结点
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)				//*p为二叉树的根结点
					b=p;
				else  					//已建立二叉树根结点
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
void DispBTNode(BTNode *b)				//采用括号表示输出二叉链b
{	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//有孩子结点时才输出(
			DispBTNode(b->lchild);				//递归处理左子树
			if (b->rchild!=NULL) printf(",");	//有右孩子结点时才输出,
			DispBTNode(b->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}
void DestroyBTNode(BTNode *&b)	//释放以*b为根结点的二叉树
{	if (b!=NULL)
	{	DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
bool Ancestor(BTNode *b,char x,char path[],int &d)	//求根结点到x结点的路径
{	if (b==NULL)								//空树返回false
		return false;
	if (b->data==x)
	{	d++; path[d]=x;
		return true;
	}
	else if (Ancestor(b->lchild,x,path,d) || Ancestor(b->rchild,x,path,d))
	{	d++;path[d]=b->data;
		return true;
	}
}
void main()
{	BTNode *b;
	char x='G';
	char path[MaxSize];
	int d=-1,i;
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");	//由括号表示串创建二叉链
	printf("二叉树b:"); DispBTNode(b); printf("\n");
	if (Ancestor(b,x,path,d))
	{	printf("在b中找到值为%c的结点\n",x);
		printf("从根结点到%c的路径:",x);
		for (i=d;i>=0;i--)
			printf("%c ",path[i]);
		printf("\n");
	}
	else	printf("在b中没有找到值为%c的结点\n",x);
	printf("销毁树b\n");
	DestroyBTNode(b);
}
