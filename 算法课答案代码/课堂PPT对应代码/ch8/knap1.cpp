//�������ȶ���ʽ��֦�޽編������0/1����������㷨
#include <stdio.h>
#define MAXN 20					//��������Ʒ��
#define MAXQ 50					//���ȶ��У��ѣ���С
double maxv;					//�������ֵ,ȫ�ֱ���
int maxx[MAXN];					//������Ž�,ȫ�ֱ���
int count=1;					//�����ռ��н�����ۼ�,ȫ�ֱ���
typedef struct
{	int no;						//�����
	int i;						//�ý���������ռ��еĲ��
	int w;						//������
	double v;					//�ܼ�ֵ
	int x[MAXN];				//������
	double ub;					//�Ͻ�
} ElemType;						//���еĽ������
typedef struct
{	ElemType data[MAXQ];		//���н����±�1��ʼ���
	int num;					//���н�����
} HeapType;						//������
void copyx(int x[],int y[],int i)//��������x���Ƶ�y
{	int j;
	for (j=1;j<=i;j++)
		y[j]=x[j];
}
void elemcopy(ElemType a,ElemType &b)	//���н��a���Ƶ�b
{	b.no=a.no;
	b.i=a.i;	b.ub=a.ub;
	b.w=a.w;	b.v=a.v;
	copyx(a.x,b.x,a.i);
}
//--------����������㷨-----------------------
void swap(ElemType &a,ElemType &b)		//a��b��㽻��
{	ElemType tmp;
	elemcopy(a,tmp);
	elemcopy(b,a);
	elemcopy(tmp,b);
}
void initHeap(HeapType &heap)			//����ѳ�ʼ��
{
	heap.num=0;							//�նѽ�����Ϊ0
}
int emptyHeap(HeapType heap)			//�ж��Ƿ�Ϊ�ն�
{
	return heap.num==0;
}
void delHeap(HeapType &heap,ElemType &e)	//ɾ���Ѷ����e������Ϊ��
{	int i,j;
	bool done=false;
	elemcopy(heap.data[1],e);				//ȡ�Ѷ����
	elemcopy(heap.data[heap.num],heap.data[1]);//�����һ������ƶ��Ѷ�
	heap.num--;								//����һ���ѽ��
	i=1;j=2*i;
	while (!done && j<=heap.num)
	{	if (j<heap.num && heap.data[j].ub<heap.data[j+1].ub)
			j++;							//���Һ��ӽϴ�,��jָ���Һ���
		if (heap.data[i].ub<heap.data[j].ub)
		{	swap(heap.data[i],heap.data[j]);//��˫�׽�㽻��
			i=j;							//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else done=true;						//��������
	}
}
void insertHeap(HeapType &heap,ElemType e,int n)	//����һ����㲢����Ϊ�����
{	bool done=false;
	int j;
	if (e.i==n)								//����Ҷ�ӽ��,������
	{	if (e.v>maxv)						//�Ƚ������Ž�
		{	maxv=e.v;						//�������Ž���ܼ�ֵ
			copyx(e.x,maxx,n);				//�������Ž�Ľ�����
		}
	}
	else									//��ΪҶ�ӽ��,����
	{	heap.num++; 						//���н�������1
		elemcopy(e,heap.data[heap.num]);	//Ԫ��e���뵽β��
		j=heap.num;
		if (j!=1)							//�����������������ʱ����Ҫ����
		{	while (!done && j!=1)			//���д������ϵ���
			{	if(heap.data[j].ub>heap.data[j/2].ub)	//���ӽ�����˫��
					swap(heap.data[j],heap.data[j/2]);	//����
				else
					done=true;				//������������Ҫ��,��������
				j=j/2;
			}
		}
	}
}
//--------����������㷨����--------------------
void bound(int w[],int v[],int W,int n,ElemType &e)	 //�����֦���e���Ͻ�
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
void knap(int w[],int v[],int W,int n)	//��0/1������������Ž�
{	int j;						//iΪ�����ռ�Ĳ��,�ӵ�0�㿪ʼ
	int ew=0,ev=0;
	HeapType heap;				//����һ����
	initHeap(heap);				//�ѳ�ʼ��
	ElemType e,e1,e2;
	e.i=0;						//������ó�ֵ
	e.w=0; e.v=0;
	e.no=count++; 
	for (j=1;j<=n;j++)
		e.x[j]=0;
	bound(w,v,W,n,e);			//��������Ͻ�
	insertHeap(heap,e,n);		//��������
	while (!emptyHeap(heap))	//�Ӳ���ѭ��
	{	delHeap(heap,e);		//���ӽ��e
		if (e.w+w[e.i+1]<=W)	//������ӽ��
		{	e1.no=count++; 
			e1.i=e.i+1;			//�������ӽ��
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1.i];
			copyx(e.x,e1.x,e.i);
			e1.x[e1.i]=1;
			bound(w,v,W,n,e1);	//�����ӽ����Ͻ�
			insertHeap(heap,e1,n);
		}
		e2.no=count++; 
		e2.i=e.i+1;				//�����Һ��ӽ��
		e2.w=e.w; e2.v=e.v;
		copyx(e.x,e2.x,e.i);
		e2.x[e2.i]=0;
		bound(w,v,W,n,e2);		//���Һ��ӽ����Ͻ�
		if (e2.ub>maxv)			//���ҽ�����,���ҽ�����
			insertHeap(heap,e2,n);
	}
}
void dispknap(int n)			//������Ž�
{	int i;
	printf("��֦�޽編���0/1��������:\nX=[");
	for(i=1;i<=n;i++)
		printf("%2d",maxx[i]);	//�������X[n]����
	printf("]��װ���ܼ�ֵ%g\n",maxv);
}
void main()
{	int n,W;
	int w[]={0,16,15,15}; n=3;
	int v[]={0,45,25,25}; W=30;
	knap(w,v,W,n);				//�������ȶ���ʽ��֦�޽編��0/1��������
	dispknap(n);				//������Ž�
}
