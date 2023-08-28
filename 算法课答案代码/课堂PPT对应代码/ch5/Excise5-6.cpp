//练习题6
#include <stdio.h>
int greedy(int a[],int n,int d)	//a中存放n个加油站的距离
{	int i,j,s=0,sum=0;
	for (j=0;j<n;j++)
		if (a[j]>d)		//无解返回-1
			return -1;
	for (i=0;i<n;i++)
	{	s+=a[i];
		if (s>d)
		{	sum++;		//加油次数增1
			s=a[i];
		}
	}
	return sum;
}
void main()
{
	int n=4,d=7;
	int a[]={2,7,3,6};
	printf("%d\n",greedy(a,n,d));
}
