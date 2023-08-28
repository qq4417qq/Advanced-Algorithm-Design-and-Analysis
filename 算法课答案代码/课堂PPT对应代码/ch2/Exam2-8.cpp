//��2.8
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ�����ӽ��
	struct node *rchild;		//ָ���Һ��ӽ��
} BTNode;
void CreateBTNode(BTNode * &b,char *str)	//��str����������b
{	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;					//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')  			//strδɨ����ʱѭ��
	{	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;	//Ϊ���ӽ��
		case ')':top--;break;
		case ',':k=2; break;				//Ϊ���ӽ���ҽ��
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)				//*pΪ�������ĸ����
					b=p;
				else  					//�ѽ��������������
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
void DispBTNode(BTNode *b)				//�������ű�ʾ���������b
{	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBTNode(b->lchild);				//�ݹ鴦��������
			if (b->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBTNode(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
void DestroyBTNode(BTNode *&b)	//�ͷ���*bΪ�����Ķ�����
{	if (b!=NULL)
	{	DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
bool Ancestor(BTNode *b,char x,char path[],int &d)	//�����㵽x����·��
{	if (b==NULL)								//��������false
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
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");	//�����ű�ʾ������������
	printf("������b:"); DispBTNode(b); printf("\n");
	if (Ancestor(b,x,path,d))
	{	printf("��b���ҵ�ֵΪ%c�Ľ��\n",x);
		printf("�Ӹ���㵽%c��·��:",x);
		for (i=d;i>=0;i--)
			printf("%c ",path[i]);
		printf("\n");
	}
	else	printf("��b��û���ҵ�ֵΪ%c�Ľ��\n",x);
	printf("������b\n");
	DestroyBTNode(b);
}
