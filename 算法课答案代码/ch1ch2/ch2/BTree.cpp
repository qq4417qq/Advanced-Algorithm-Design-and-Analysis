//�������Ļ��������㷨
#include <malloc.h>
#include <stack>
#include <vector>
#include <string>
using namespace std;
typedef int ElemType;
typedef struct node 
{	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ�����ӽ��
	struct node *rchild;		//ָ���Һ��ӽ��
} BTNode;						//�������������

BTNode *CreateBTree(ElemType a[],ElemType b[],int n)	//��Ӧ��2.8���㷨
//����������a[0..n-1]����������b[0..n-1]����������
{
	int k;
	if (n<=0) return NULL;
	ElemType root=a[0];			//�����ֵ
	BTNode *bt=(BTNode *)malloc(sizeof(BTNode));
	bt->data=root;
	for (k=0;k<n;k++)			//��b�в���b[k]=root�ĸ����
		if (b[k]==root)
			break;
	bt->lchild=CreateBTree(a+1,b,k);			//�ݹ鴴��������
	bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1);	//�ݹ鴴��������
	return bt;
}
void DispBTree(BTNode *bt)				//�������ű�ʾ���������bt
{
	if (bt!=NULL)
	{	printf("%d",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBTree(bt->lchild);				//�ݹ鴦��������
			if (bt->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBTree(bt->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
void DestroyBTree(BTNode *&bt)		//��Ӧ��2.9���㷨
//�ͷ���btΪ�����Ķ�����
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
