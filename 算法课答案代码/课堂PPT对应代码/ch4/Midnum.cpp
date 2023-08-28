//寻找两个等长有序序列的中位数的算法
#include <stdio.h>
void prepart(int &s,int &t)			//求a[s..t]序列的前半子序列
{	int m=(s+t)/2;
	t=m;
}
void postpart(int &s,int &t)		//求a[s..t]序列的后半子序列
{	int m=(s+t)/2;
	if ((s+t)%2==0)				//序列中有奇数个元素
		s=m;
	else							//序列中有偶数个元素
		s=m+1;
}
int midnum(int a[],int s1,int t1,int b[],int s2,int t2)
{	//求两个有序序列a[s1..t1]和b[s2..t2]的中位数
	int m1,m2;
	if (s1==t1 && s2==t2)	//两序列只有一个元素时返回较小者
		return a[s1]<b[s2]?a[s1]:b[s2];
	else
	{	m1=(s1+t1)/2;				//求a的中位数
		m2=(s2+t2)/2;				//求b的中位数
		if (a[m1]==b[m2])			//两中位数相等时返回该中位数
			return a[m1];
		if (a[m1]<b[m2])			//当a[m1]<b[m2]时
		{	postpart(s1,t1);		//a取后半部分
			prepart(s2,t2);		//b取前半部分
			return midnum(a,s1,t1,b,s2,t2);
		}
		else						//当a[m1]>b[m2]时
		{	prepart(s1,t1);		//a取前半部分
			postpart(s2,t2);		//b取后半部分
			return midnum(a,s1,t1,b,s2,t2);
		}
	}
}
void main()
{	int a[]={11,13,15,17,19};
	int b[]={2,4,6,8,20};
	printf("中位数:%d\n",midnum(a,0,4,b,0,4));
}
