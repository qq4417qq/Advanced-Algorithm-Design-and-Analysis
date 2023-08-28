#include <stdio.h>
#define MAX 51
//问题表示
int fishSize[MAX];
int n;
int minSize,maxSize;
//求解结果表示
int ans=0;
void solve()					//求解有多少种大小的鱼可以放入这个鱼缸
{	bool flag;
	for (int i=minSize; i<=maxSize; ++i)
	{	flag=true;
        	for (int j=0; j<n; ++j)
        	{	if ((i>=fishSize[j]*2 && i<=fishSize[j]*10) 
				||(fishSize[j]>=i*2 && fishSize[j]<=i*10))
			{	flag=false;		//不能放入
				break;
			}
        	}
		if (flag) ans++;			//能够放入
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
