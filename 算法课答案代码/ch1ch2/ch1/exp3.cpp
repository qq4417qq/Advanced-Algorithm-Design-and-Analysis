#include <stdio.h>
#include <queue>
using namespace std;
int solve(queue<int> &qu,int k)	//���ӵ�k��Ԫ��
{	queue<int> tmpqu;
	int e;
	for (int i=0;i<k-1;i++)		//����qu��k-1��Ԫ�ز���tmpqu��
	{	tmpqu.push(qu.front());
		qu.pop();
	}
	e=qu.front();				//����qu�ĵ�k��Ԫ��
	qu.pop();
	while (!qu.empty())		//��qu��ʣ��Ԫ�س��Ӳ�����tmpqu
	{	tmpqu.push(qu.front());
		qu.pop();
	}
	qu=tmpqu;					//��tmpqu���Ƹ�qu
	return e;
}
void disp(queue<int> &qu)		//����qu������Ԫ��
{	while (!qu.empty())
	{	printf("%d ",qu.front());
		qu.pop();
	}
	printf("\n");
}
void main()
{
	printf("ʵ����\n");
	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	printf("  Ԫ��1,2,3,4���ν���qu\n");
	int k=3;
	int e=solve(qu,k);
	printf("  ���ӵ�%d��Ԫ����: %d\n",k,e);
	printf("  qu������Ԫ�س���˳��: ");
	disp(qu);
}
