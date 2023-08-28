//Hanoi����ǵݹ��㷨
#include <stdio.h>
#define MaxSize 100
struct
{	int n;			//����nֵ
	char x,y,z;		//����f(n)ֵ
	int tag;		//��ʶ�Ƿ����f(n)ֵ,1:δ���,0:�����
} St[MaxSize];		//����ջ
int top=-1;			//ջָ���ʼ��
void Hanoi1(int n,char x,char y,char z)
{	int n1,x1,y1,z1;
	if (n<=0)
	{	printf("��������\n");
		return;
	}
	else if (n==1)
	{	printf("��%c�ϵ�1����Ƭֱ���ƶ���%c\n",x,z);
		return;
	}
	top++;
	St[top].n=n;							//��ֵ��ջ
	St[top].x=x; St[top].y=y; St[top].z=z; St[top].tag=1;
	while (top>-1)						//ջ����ѭ��
	{	if (St[top].tag==1 && St[top].n>1)	//������ֱ�Ӳ���ʱ
		{	n1=St[top].n;					//��ջhanoi(n,x,y,z)
			x1=St[top].x; y1=St[top].y; z1=St[top].z;
			top--;
			top++;						//��Hanoi(n-1,y,x,z)��ջ
			St[top].n=n1-1; St[top].x=y1; St[top].y=x1; St[top].z=z1;
			if (n1-1==1)					//ֻ��һ����Ƭʱֱ�Ӳ���
				St[top].tag=0;
			else
				St[top].tag=1;
			top++;						//����n��Բ�̴�x�Ƶ�z;
			St[top].n=n1; St[top].x=x1; St[top].z=z1; St[top].tag=0;
			top++;						//��Hanoi(n-1,x,z,y)��ջ
			St[top].n=n1-1; St[top].x=x1; St[top].y=z1; St[top].z=y1;
			if (n1-1==1)					//ֻ��һ����Ƭʱֱ�Ӳ���
				St[top].tag=0;
			else
				St[top].tag=1;
		}
		else if	(St[top].tag==0)			//������ֱ�Ӳ���ʱ
		{	printf("\t����%d����Ƭ��%c�ƶ���%c\n",St[top].n,St[top].x,St[top].z);
			top--;						//�ƶ���Ƭ����ջ
		}
	}
}
void main()
{
	int n=3;
	printf("n=%dʱHanoi�Ĳ�������:\n",n);
	Hanoi1(3,'x','y','z');
}