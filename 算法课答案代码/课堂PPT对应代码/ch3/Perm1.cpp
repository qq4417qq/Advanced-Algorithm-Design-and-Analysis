//���ȫ��������
#include <stdio.h>
#define Maxn 10						//����nֵ
#define MaxSize 1000
typedef struct						//����ջԪ������
{	struct
	{	int a[Maxn];					//���һ������
		int m;						//��Ÿ������Ԫ�ظ���
	} data[MaxSize];
	int top;							//ջ��ָ��
} StackType;
void insert(int a[],int m,int j,int k)	//��a[1..m]��a[j]������k
{	int i;
	for (i=m+1;i>j;i--)				//��a[j..m]Ԫ�غ���
		a[i]=a[i-1];
	a[j]=k;
}
void disp(int a[],int m)				//���a[1..m]��Ԫ��
{	int i;
	for (i=1;i<=m;i++)
		printf("%d",a[i]);
	printf(" ");
}
void copy(int a[],int b[],int m)			//��a[1..m]���Ƶ�b[1..m]
{	int i;
	for (i=1;i<=m;i++)
		b[i]=a[i];
}
void perm(int n)							//���1��n������ȫ����
{	int j,m;
	int b[Maxn],c[Maxn];					//������ʱ���һ������
	StackType st;							//����һ��˳��ջ
	st.top=-1;							//��ʼ��˳��ջ
	st.top++;								//��1��ջ
	st.data[st.top].a[1]=1; st.data[st.top].m=1;
	while (st.top!=-1)						//ջ����ѭ��
	{	m=st.data[st.top].m;				//ȡջ��Ԫ�ص�mֵ
		if (m==n)							//�ҵ�һ��ȫ����,�������ջ
		{	disp(st.data[st.top].a,n);
			st.top--;						//��ջ
		}
		else								//�ҵ�һ�ֲ�������
		{	copy(st.data[st.top].a,c,m);	//ȡ��ջ�����е�c��
			st.top--;						//��ջ
			for (j=1;j<=m+1;j++)
			{	copy(c,b,m);				//��c[1..m]�в��������Ƶ�b��
				insert(b,m,j,m+1);			//��m+1���뵽b[j]��
				st.top++;					//��b��ջ
				copy(b,st.data[st.top].a,m+1);
				st.data[st.top].m=m+1;
			}
		}
	}
}
void main()
{	int n=3;
	printf("1��%d��ȫ��������:",n);
	perm(n); printf("\n");
}

