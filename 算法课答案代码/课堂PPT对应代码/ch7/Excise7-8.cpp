//��ϰ��8
#include <stdio.h>
#define MAXN 20
#define MAXM 10
int m,n;
int x[MAXM];
int used[MAXN];
void fun(int i)					//��n��Ԫ����m��Ԫ�ص�ȫ����
{	int j;
	if (i>m)
	{	for (j=1;j<=m;j++)
			printf("%d ",x[j]);	//���һ������
		printf("\n");
	}
	else
	{	for (j=1;j<=n;j++)
		{	if (!used[j])
			{	used[j]=1;		//�޸�used[i]
				x[i]=j;			//��¼x[i]
				fun(i+1);		//�����������е���һ��Ԫ��
				used[j]=0;		//���ݣ���ԭused[i]
			}
		}
	}
}
void main()
{	m=3,n=5;
	int i;
	for (i=0;i<=n;i++)
		used[i]=0;				//used[i]Ϊ1������i��Ԫ���ڵ�ǰ�����У���֮��Ȼ
	fun(1);
}
