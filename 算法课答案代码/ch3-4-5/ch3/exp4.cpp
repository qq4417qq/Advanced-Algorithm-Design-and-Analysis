#include <stdio.h>
#define MAXN 201
int fset(int n)			//��set(n)��Ԫ�ظ���
{	int ans=1;
	if(n>1)
		for(int i=1;i<=n/2;i++)
			ans+=fset(i);
	return ans;
}
void main()
{
	int n=6;
	printf("�����\n");
	printf("  n=%dʱ������Ԫ�ظ���=%d\n",n,fset(n));
}

