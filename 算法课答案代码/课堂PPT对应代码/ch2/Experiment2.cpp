//�ϻ�ʵ����2
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef struct node
{	char data;					//����Ԫ��
	struct node *lchild;			//ָ�����ӽ��
	struct node *rchild;			//ָ���Һ��ӽ��
} BTNode;							//�������洢�ṹ������Ͷ���
//�������ø����ָ��b��Ψһ��ʶ
void CreateBTNode(BTNode * &b,char *str)	//�����ű�ʾ������������
{	BTNode *St[MaxSize],*p;
	int top=-1,k,j=0;
	char ch;
	b=NULL;						//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')				//ѭ��ɨ��str��ÿ���ַ�
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//��ʼ�������ӽ��
		case ')':top--;break;
		case ',':k=2; break;				//��ʼ�����Һ��ӽ��
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)				//����δ���������
					b=p;					//*pΪ�������ĸ����
				else						//�ѽ��������������
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
void DestroyBTNode(BTNode *&b)	//�ͷ���*bΪ�����Ķ�����
{	if (b!=NULL)
	{	DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
void DispBTNode(BTNode *b)		//���������
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
//����ֵΪx�Ľ��,pΪ���ҵ�����˫��,��ֵΪNULL,tag=1��ʾ*bΪ*p������,tag=2��ʾ*bΪ*p���Һ���
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
//����ֵΪx�Ľ�㲢����,����Ϊ����㣬����˫�׵���Ӧָ������ΪNULL
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
bool Delete(BTNode *&b,char x)	//ɾ�����ͷ�ֵx�Ľ�������
{
	BTNode *p;
	p=Find(b,x);
	if (p!=NULL)
	{
		if (p==b)	//pָ������
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
	printf("��str�����������洢�ṹb\n");
	CreateBTNode(b,str);
	printf("b:"); DispBTNode(b); printf("\n");
	if (Delete(b,x))
	{
		printf("ɾ����%cΪ����������\n",x);
		printf("b:"); DispBTNode(b); printf("\n");
		printf("���ٶ�����\n");
		DestroyBTNode(b);
	}
	else
		printf("ɾ�����ö�����\n");
}
