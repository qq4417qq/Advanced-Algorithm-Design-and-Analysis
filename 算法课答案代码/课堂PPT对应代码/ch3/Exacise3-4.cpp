//练习题4
#include <stdio.h>
bool ok(int a[],int k,int i)	//ok用于判别重复元素
{
	int t;
	if (i>k)
		for(t=k;t<i;t++)
			if (a[t]==a[i]) return false;
	return true;
}
void Perm(int a[],int k,int n)
{
	int i,tmp;
	if (k==n)
	{
		for(i=0;i<n;i++)
			printf("%3d",a[i]);
		printf("\n");
	}
	else
	{
		for (i=k;i<n;i++)
			if (ok(a,k,i))
			{
				tmp=a[k]; a[k]=a[i]; a[i]=tmp;
				Perm(a,k+1,n);
				tmp=a[k]; a[k]=a[i]; a[i]=tmp;
			}
	}
}
void main()
{
	int a[]={1,1,2,3},n=4;
	Perm(a,0,n);
}
