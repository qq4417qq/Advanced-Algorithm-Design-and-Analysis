//���û��ݷ��ݹ�������Թ�������㷨
#include <stdio.h>
#define M 6
#define N 6
#define MaxSize 20					//�Թ�·���е���෽����
typedef struct
{	int i;							//��ǰ������к�
	int j;							//��ǰ������к�
} Box;								//����һ�����������
typedef struct
{	Box data[MaxSize];
	int length;						//·������
} PathType;							//����һ��·��������
void dispapath(PathType path)		//���һ���Թ�·��
{	static int count=0;				//��̬��������ͳ���Թ�·������
	int k;
	printf("��%d���Թ�·��:\n",++count);
	for (k=0;k<path.length;k++)
		printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
	printf("\n");
}
void mgpath(int mg[M][N],int xi,int yi,int xe,int ye,PathType path)
//��(xi,yi)->(xe,ye)�������Թ�·��
{	int di,i,j;
	if (xi==xe && yi==ye)			//�ҵ��˳���,���·��
	{	path.data[path.length].i=xi;//�����ڷ���·����
		path.data[path.length].j=yi;
		path.length++;
		dispapath(path);			//���һ��·��
	}
	else							//(xi,yi)���ǳ���
	{	if (mg[xi][yi]==0)			//��(xi,yi)��һ�����߷���
		{	di=0;
			while (di<4)			//��(xi,yi)�����ܵ����ڷ���(i,j)
			{	path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;		//·��������1
				switch(di)			//��һ�����ڷ���(i,j)
				{
				case 0:i=xi-1; j=yi;   break;
				case 1:i=xi;   j=yi+1; break;
				case 2:i=xi+1; j=yi;   break;
				case 3:i=xi;   j=yi-1; break;
				}
				mg[xi][yi]=-1;		//�����ظ���·��
				mgpath(mg,i,j,xe,ye,path);
				mg[xi][yi]=0;		//�ָ�(xi,yi)Ϊ���ߵ�
				path.length--;		//����һ�����飬·�����ȼ�1
				di++;				//��(xi,yi)����һ����λ�����ڷ���
			}
		}
	}
}
void main()
{	PathType path;
	int mg[M][N]={ {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
			 {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1} };
	path.length=0;					//�Թ�·�����ȳ�ʼ��
	mgpath(mg,1,1,4,4,path);		//�����(1,1)������(4,4)�������Թ�·��
}
