#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 200000
//问题表示
int a[MAXN];
int n,c;
int BinSearch(int low,int high,int x)	//在a[loww..high]中查找x出现的次数
{
    while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)					//找到a[mid]=x:求左右为x的个数
		{
			int count=1,i;
			i=mid-1;
			while(i>=low && a[i]==x)	//在a[mid]左边找x的次数
			{
				count++;
				i--;
			}
			i=mid+1;
			while(i<=high && a[i]==x)	//在a[mid]右边找x的次数
			{
				count++;
				i++;
			}
			return count;
		}
		else if(x>a[mid])				//x>a[mid]:在右区间中查找
			low=mid+1;
		else							//x<a[mid]:在左区间中查找
            high=mid-1;
    }
    return 0;							//没有查找返回0
}
int main()
{
	scanf("%d%d", &n, &c);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);						//对数组a递增排序
	int ans=0;
	for(int j=0;j<n-1;j++)
		ans+=BinSearch(j+1,n-1,a[j]+c);
	printf("%d\n",ans);
	return 0;
}
