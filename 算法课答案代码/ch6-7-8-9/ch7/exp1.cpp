#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1001
//�����ʾ
int a[MAX]={10,1,10,20,30,20};
int n=6;
//�������ʾ
int bestd;					//���ִ���������С��
int maxn=0;					//�������Ĵ���
void solve()					//�����ִ���������
{	sort(a,a+n);				//������ֵ��������
	int pred=a[0];
	int num=1;
	int i=1;
	while (i<n)
	{	while (i<n && a[i]==pred)
		{	num++;
			i++;
		}
		if (num>maxn)			//�Ƚ���maxn
		{	bestd=pred;
			maxn=num;
		}
		pred=a[i];				//a[i]!=pred�����
		num=1;
		i++;
	}
}
int main()
{	//���������������Ĵ���
	solve();
	printf("%d\n",bestd);		//���10
	return 0;
}
