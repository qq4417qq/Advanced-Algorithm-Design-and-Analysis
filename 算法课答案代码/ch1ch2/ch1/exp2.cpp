#include <stdio.h>
#include <queue>
using namespace std;
int thk(int a[],int n,int k)		//��a�е�kС��Ԫ��
{	int i,e;
	priority_queue<int,vector<int>,greater<int> > pq;
	for (i=0;i<n;i++)				//����Ԫ�ؽ���
		pq.push(a[i]);
	for (i=0;i<k;i++)
	{	e=pq.top();
		pq.pop();
	}
	return e;
}
void main()
{	int a[]={1,2,4,5,3};
	int n=sizeof(a)/sizeof(a[0]);
	printf("ʵ����\n");
	for (int k=1;k<=n;k++)
		printf("  ��%dС��Ԫ��: %d\n",k,thk(a,n,k));
}
