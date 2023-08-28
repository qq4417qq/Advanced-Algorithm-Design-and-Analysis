//���û��ݷ��ǵݹ�������Թ�������㷨
#include <stdio.h>
#define M 6
#define N 6
#define MaxSize 20					//ջ���Ԫ�ظ���
typedef struct
{	int i;							//��ǰ������к�
	int j;							//��ǰ������к�
	int di;							//��ǰ�������һ�����߷���ķ�λ
} Box;								//����һ�����������
typedef struct
{	Box data[MaxSize];				//���ջ�з���
	int top;						//ջ��ָ��
} StackType;						//����˳��ջ����
void dispapath(StackType st)		//���һ���Թ�·��
{	static int count=0;				//��̬��������ͳ���Թ�·������
	int k;
	printf("��%d���Թ�·��:\n",++count);
	for (k=0;k<=st.top;k++)
		printf("(%d,%d)  ",st.data[k].i,st.data[k].j);
	printf("\n");
}
void mgpath(int mg[M][N],int xi,int yi,int xe,int ye)
//��(xi,yi)->(xe,ye)�������Թ�·��
{	int i,j,i1,j1,di,find;
	StackType st;					//����һ��˳��ջ
	st.top=-1;						//ջ��ָ���ʼ��
	st.top++;						//��ڽ�ջ
	st.data[st.top].i=xi;  st.data[st.top].j=yi;
	st.data[st.top].di=-1;	mg[xi][yi]=-1;
	while (st.top>-1)				//ջ����ʱѭ��
	{	i=st.data[st.top].i; j=st.data[st.top].j;
		di=st.data[st.top].di;		//ȡջ������
		if (i==xe && j==ye)			//�ҵ��˳���,�����·��
		{	dispapath(st);			//�ҵ�һ��·���������ջ�Ա�����һ��·��
			mg[i][j]=0;				//����:�ó��ڱ�Ϊ����·�����߷���
			st.top--;				//������ջ
			i=st.data[st.top].i; j=st.data[st.top].j;
			di=st.data[st.top].di;	//ȡջ������
		}
		find=0;
		while (di<4 && find==0)		//��(i,j)�����һ�����ڿ��߷���
		{	di++;
			switch(di)
			{
			case 0:i1=st.data[st.top].i-1;j1=st.data[st.top].j;break;
			case 1:i1=st.data[st.top].i;  j1=st.data[st.top].j+1;break;
			case 2:i1=st.data[st.top].i+1;j1=st.data[st.top].j;break;
			case 3:i1=st.data[st.top].i,  j1=st.data[st.top].j-1;break;
			}
			if (mg[i1][j1]==0) find=1;
		}
		if (find==1)				//�ҵ���һ�����ڿ��߷���(i1,j1)
		{	st.data[st.top].di=di;	//�޸�ԭջ��Ԫ�ص�diֵ
			st.top++;
			st.data[st.top].i=i1; st.data[st.top].j=j1;
			st.data[st.top].di=-1;	//�����ڿ��߷���(i1,j1)�����ջ
			mg[i1][j1]=-1;			//�����ظ��ߵ��÷���
		}
		else						//(i,j)��û��·������,����ջ
		{	mg[i][j]=0;				//����:�ָ�(i,j)����Ϊ���߷���
			st.top--;				//��ջ
		}
	}
}
void main()
{	int mg[M][N]={ {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
			 {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1} };
	mgpath(mg,1,1,4,4);	//�����(1,1)������(4,4)�������Թ�·��
}
