//������ջ���n�ʺ�������㷨
#include <stdio.h>
#include <stdlib.h>
const int MAXN=20;				//���ʺ����
int q[MAXN];					//��Ÿ��ʺ����ڵ��к�,Ϊȫ�ֱ���
void dispasolution(int n)   	//���һ����
{	static int count=0;			//��̬��������ͳ�ƽ����
	int i;
	printf("  ��%d����:",++count);
	for (i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
int place(int k)				//���Ե�k�е�q[k]�����ܷ�ڷŻʺ�
{	int i=1;
	while (i<k)					//i=1��k-1���ѷ����˻ʺ����
	{	if ((q[i]==q[k]) || (abs(q[i]-q[k])==abs(i-k))) 
			//�ûʺ��Ƿ�����ǰ�ʺ�ͬ�У�λ��(i,q[i])��(k,q[k])�Ƿ�ͬ�Խ���
			return 0;
		i++;
	}
	return 1;
}
void Queens(int n)					//���n�ʺ�����
{	int k=1;						//k��ʾ��ǰ��,Ҳ��ʾ���õ�k���ʺ�
	q[k]=0;							//q[k]�ǵ�ǰ��,��0�м���ͷ��̽
	while (1)						//�ظ���̽
	{	q[k]=q[k]+1;				//��̽��һ�е�λ��,��Ϊ��ʼ�д�0��ʼ
		while (q[k]<=n && !place(k))//��̽һ��λ��(k,q[k])
			q[k]=q[k]+1;
		if (q[k]<=n)				//Ϊ��k���ʺ��ҵ���һ������λ��(k,q[k])
		{	if (k==n)				//�����������лʺ�,���һ����
				dispasolution(n);
			else					//�ʺ�û�з�����
			{	k++;				//ת����һ��,����ʼ��һ���ʺ�ķ���
				q[k]=0;				//ÿ�η�һ���»ʺ�,���Ӹ��е���ͷ������̽
			}
		}
		else						//����k���ʺ��Ҳ������ʵ�λ��,����ݵ���һ���ʺ�
		{	if (k==1) exit(0);		//�����ݳ��缴���л�����ɣ��㷨����
			k--;					//���ݵ���һ���ʺ�
		}
	}
}
void main()
{	int n;				//n���ʵ�ʻʺ����
	printf("�ʺ�����(n<20) n:");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��\n");
	else
	{	printf("%d�ʺ������������:\n",n);
		Queens(n);
	}
}
