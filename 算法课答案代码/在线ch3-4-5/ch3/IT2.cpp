#include <stdio.h>
#define MAXN 100000
//问题表示
int a[MAXN];
int n,m;
int BinSearch(int low,int high,int x)	//二分查找x
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			return a[mid];
		else if(a[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
	if (high<0)
		return -1;
	else
		return a[high];
}
int main()
{
	int x,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			printf("%d\n",BinSearch(0,n-1,x));
		}
	}
    return 0;
}
