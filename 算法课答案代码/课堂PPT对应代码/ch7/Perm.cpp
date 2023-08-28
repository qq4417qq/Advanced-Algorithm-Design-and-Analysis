//求解全排列问题的算法
#include <stdio.h>
void perm(char s[],int k,int n)
{	int i;
	char tmp;
	if (k==n-1)							//输出一个排列
	{	for (i=0;i<n;i++)
			printf("%c ",s[i]);
		printf("\n");
	}
	else
	{	for (i=k;i<n;i++)
		{	tmp=s[k];s[k]=s[i];s[i]=tmp; //交换s[k]与s[i]
			perm(s,k+1,n);
			tmp=s[k];s[k]=s[i];s[i]=tmp; //交换s[k]与s[i],恢复环境即回溯
		}
	}
}
void main()
{	int n=3;
	char s[]="123";
	perm(s,0,n);
}
