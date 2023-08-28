//���ö���ʽ��֦�޽編���0/1����������㷨
#include <stdio.h>
#define MAXN 20						//��������Ʒ��
#define MAXQ 50						//���д�С
int maxv;							//�������ֵ,ȫ�ֱ���
int maxx[MAXN];						//������Ž�,ȫ�ֱ���
int count=1;						//�����ռ��н�����ۼ�,ȫ�ֱ���
typedef struct
{	int no;							//�����
	int i;							//��ǰ����������ռ��еĲ��
	int w;							//��ǰ����������
	double v;						//��ǰ�����ܼ�ֵ
	int x[MAXN];					//��ǰ�������Ľ�����
	double ub;						//�Ͻ�
} ElemType;							//�����еĽ������
typedef struct
{	ElemType data[MAXQ];
	int front,rear;					//��ͷ��βָ��
} QueueType;						//��������
void copyx(int x[],int y[],int i) 	//������x���Ƶ�y
{	int j;
	for (j=1;j<=i;j++)
		y[j]=x[j];
}
void elemcopy(ElemType a,ElemType &b) //���н��a���Ƶ�b
{	b.no=a.no; b.i=a.i;
	b.ub=a.ub; b.w=a.w;
	b.v=a.v;
	copyx(a.x,b.x,a.i);				//���ƽ�����
}
//------------���л�������-----------------------
void initQueue(QueueType &q)		//���г�ʼ��
{
	q.front=q.rear=0;
}
int emptyQueue(QueueType q)			//�жӿ�
{
	return q.front==q.rear;
}
int enQueue(QueueType &q,ElemType e,int n)	//���e����
{	if ((q.rear+1)%MAXQ==q.front)	//����
		return 0;
	else
	{	if (e.i==n)					//����Ҷ�ӽ��,������
		{	if (e.v>maxv)			//�Ƚ������Ž�
			{	maxv=e.v;
				copyx(e.x,maxx,n);
			}
		}
		else						//����������
		{	q.rear=(q.rear+1)%MAXQ;
			elemcopy(e,q.data[q.rear]);
		}
		return 1;
	}
}
int deQueue(QueueType &q,ElemType &e)//���e����
{	if (emptyQueue(q))				//�ӿ�
		return 0;
	else
	{	q.front=(q.front+1)%MAXQ;
		elemcopy(q.data[q.front],e);
		return 1;
	}
}
//------------���л����������-------------------
void bound(int w[],int v[],int W,int n,ElemType &e) //�����֦���e���Ͻ�
{	int i=e.i+1;
	int sumw=e.w;
double sumv=e.v;
	while ((sumw+w[i]<=W) && i<=n)
	{	sumw+=w[i];				//���㱳����װ������
		sumv+=v[i];				//���㱳����װ���ֵ
		i++;
	}
	if (i<=n)	
		e.ub=sumv+(W-sumw)*v[i]/w[i];
	else
		e.ub=sumv;
}
//----------------------------------
void knap(int w[],int v[],int W,int n)	//��0/1���������Ž�
{	int j;
	QueueType q;					//����һ������
	initQueue(q);					//���г�ʼ��
	ElemType e,e1,e2;				//����3�����
	e.i=0;							//������ó�ֵ�����μ�Ϊ0
	e.w=0; e.v=0;
	e.no=count++; 
	for (j=1;j<=n;j++)
		e.x[j]=0;
	bound(w,v,W,n,e);				//��������Ͻ�
	enQueue(q,e,n);					//��������
	while (!emptyQueue(q))			//�Ӳ���ѭ��
	{	deQueue(q,e);				//���ӽ��e
		if (e.w+w[e.i+1]<=W)		//������ӽ��
		{	e1.no=count++; 
			e1.i=e.i+1;				//�������ӽ��
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1.i];
			copyx(e.x,e1.x,e.i);
			e1.x[e1.i]=1;
			bound(w,v,W,n,e1);		//�����ӽ����Ͻ�
			enQueue(q,e1,n);
		}
		e2.no=count++; 
		e2.i=e.i+1;					//�����Һ��ӽ��
		e2.w=e.w; e2.v=e.v;
		copyx(e.x,e2.x,e.i);
		e2.x[e2.i]=0;
		bound(w,v,W,n,e2);			//���Һ��ӽ����Ͻ�
		if (e2.ub>maxv)				//���Һ��ӽ�����,�����,���򱻼�֦
			enQueue(q,e2,n);
	}
}
void dispknap(int n)				//������Ž�
{	int i;
	printf("��֦�޽編���0/1��������:\n  X=[");
	for(i=1;i<=n;i++)
		printf("%2d",maxx[i]);		//�������X[n]����
	printf("]��װ���ܼ�ֵΪ%d\n",maxv);
}
void main()
{	int n=3,W=30;
	int w[]={0,16,15,15};			//�����������±�0��Ԫ��
	int v[]={0,45,25,25};  			//��ֵ�������±�0��Ԫ��
	knap(w,v,W,n);					//���ö���ʽ��֦�޽編��0/1��������
	dispknap(n);					//������Ž�
}
