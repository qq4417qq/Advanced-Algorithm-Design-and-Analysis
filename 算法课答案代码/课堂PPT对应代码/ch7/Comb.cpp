//求解组合问题的算法
#include <stdio.h>
#define MAXK 10
void dispcomb(int a[],int k)		//输出一个组合
{	int i;
	for (i=0;i<k;i++)
		printf("%3d",a[i]);
	printf("\n");  
}
void comb(int a[],int n,int k) 		//求1..n中k个整数的组合
{	int i=0;						//i指出处理的组合位,从0开始
	a[i]=1;							//置初值最小值1
	while (1) 						//重复试探
	{	if (a[i]-i<=n-k+1)			//a[i]元素合法,即满足②
		{	if (i==k-1)				//找到一个解,输出之
			{	dispcomb(a,k);		//输出一个解
				a[i]++;				//将a[i]增1,继续试探下一个解
			}
			else					//尚未找到一个解，确定下一个位置元素
			{	i++;
				a[i]=a[i-1]+1;		//下一位置元素值为前一元素值增1,使其满足①
			}
		}
		else						//a[i]元素不合法,即不满足②,则回溯
		{	if (i==0) break;		//若回溯超界即所有回溯完成，算法结束
			a[--i]++;				//回溯到前一个元素，将其增1
		}
	}
} 
void main()
{	int a[MAXK];
	int n=5,k=3;
	printf("1..%d中%d个的整数的所有组合:\n",n,k);
	comb(a,n,k);
}
