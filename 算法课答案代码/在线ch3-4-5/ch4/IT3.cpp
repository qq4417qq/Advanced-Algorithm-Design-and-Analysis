#include <stdio.h>
#define MAX 51
//�����ʾ
int fishSize[MAX];
int n;
int minSize,maxSize;
//�������ʾ
int ans=0;
void solve()					//����ж����ִ�С������Է���������
{	bool flag;
	for (int i=minSize; i<=maxSize; ++i)
	{	flag=true;
        	for (int j=0; j<n; ++j)
        	{	if ((i>=fishSize[j]*2 && i<=fishSize[j]*10) 
				||(fishSize[j]>=i*2 && fishSize[j]<=i*10))
			{	flag=false;		//���ܷ���
				break;
			}
        	}
		if (flag) ans++;			//�ܹ�����
	}
}
int main()
{	scanf("%d%d",&minSize,&maxSize);
	scanf("%d",&n);
    	for (int i=0; i<n; ++i)
		scanf("%d",&fishSize[i]);
	solve();
	printf("%d\n",ans);
    	return 0;
}
