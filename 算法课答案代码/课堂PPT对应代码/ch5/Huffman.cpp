//��������������㷨
#include <stdio.h>
#define MAXN 20				//�����ַ�����
typedef struct
{	char data;				//���ֵ
	double weight;			//Ȩ��
	int parent;				//˫�׽��
	int lchild;				//���ӽ��
	int rchild;				//�Һ��ӽ��
} HTNode;					//���������Ľ������
typedef struct
{	char cd[MAXN];			//��ŵ�ǰ���Ĺ�������
	int start;				//cd[0..start]��Ź�������
} HCode;					//���������������
void CreateHTree(HTNode ht[],int n)	//�����������
{	int i,j,lnode,rnode;
	double min1,min2;
	for (i=0;i<=2*n-2;i++)			//���н���������ó�ֵ-1
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n;i<=2*n-2;i++)			//�����������
	{	min1=min2=32767;			//lnode��rnodeΪ��СȨֵ�����������±�
		lnode=rnode=-1;
		for (j=0;j<=i-1;j++)		//��ht[]����Ȩֵ��С���������
			if (ht[j].parent==-1)	//ֻ�ڸ�����в���
			{	if (ht[j].weight<min1)
				{	min2=min1; rnode=lnode;
					min1=ht[j].weight; lnode=j;
				}
				else if (ht[j].weight<min2)
				{	min2=ht[j].weight; rnode=j;	}
			}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;	//ht[i]��Ϊ˫�׽��
		ht[lnode].parent=i; ht[rnode].parent=i;
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n) //���ݹ������������������
{	int i,f,c;
	for (i=0;i<n;i++)				//����ÿ��Ҷ�ӽ��Ĺ���������
	{	hcd[i].start=n-1;			//�����������cd��n-1�±꿪ʼ����
		c=i;						//c��ֵָҪ��������Ľ��
		f=ht[i].parent;
		while (f!=-1)				//ѭ��ֱ����˫�׽�㼴�����������
		{	if (ht[f].lchild==c)	//��ǰ�����˫�׽������ӽ��
				hcd[i].cd[hcd[i].start--]='0';
			else					//��ǰ�����˫�׽����Һ��ӽ��
				hcd[i].cd[hcd[i].start--]='1';
			c=f;f=ht[f].parent;		//�ٶ�˫�׽�����ͬ���Ĳ���
		}
		hcd[i].start++;				//startָ������������ʼ�Ķ�����λ
	}
}
void dispHCode(HTNode ht[],HCode hcd[],int n)	//�������������
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
	ht[0].data='a'; ht[0].weight=4;		//�ó�ֵ��n��Ҷ�ӽ��
	ht[1].data='b'; ht[1].weight=2;  
	ht[2].data='c'; ht[2].weight=1;  
	ht[3].data='d'; ht[3].weight=7;  
	ht[4].data='e'; ht[4].weight=3;  
	CreateHTree(ht,n);					//������������
	CreateHCode(ht,hcd,n);				//�����������
	printf("�����Ĺ�������������:\n");
	dispHCode(ht,hcd,n);				//�������������
}
