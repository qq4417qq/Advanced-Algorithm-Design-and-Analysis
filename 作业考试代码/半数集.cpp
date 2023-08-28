#include <stdio.h>
#define N 100000
#define abs(x) ((x)>0?(x):-(x))		  //���������ֵ�ĺ�
int a[N];
int BinSearch(int low,int high,int x)  //���ֲ�����x��ӽ���Ԫ��
{
	int mid;
	while(low<high)
	{	mid=(low+high)/2;
		if(a[mid]>x)
			high=mid;
		else
			low=mid;
		if(low+1==high)
		{	if(abs(x-a[low])>abs(x-a[high]))
				low=high;
			else
				high=low;
		}
    }
    return low;
}
int main()
{   int n,m,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	while (m--)
	{	scanf("%d",&x);
		printf("%d\n",a[BinSearch(0,n-1,x)]);
	}
	return 0;
}
