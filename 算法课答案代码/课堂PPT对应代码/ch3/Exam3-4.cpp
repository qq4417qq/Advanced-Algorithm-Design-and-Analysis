//��3.4
#include <stdio.h>
int max3(int a,int b,int c)		//�����������е������
{	int d=a;
	if (d<b) d=b;
	if (d<c) d=c;
	return d;
}
void solve(int a[],int n)
{	int i,j,k,len,ma,maxlen=0;
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			for (k=j+1;k<n;k++)
			{	len=a[i]+a[j]+a[k];
				ma=max3(a[i],a[j],a[k]);
				if (ma<len-ma)		//a[i]��a[j]��a[k]�����һ��������
				{	if (len>maxlen)	//�Ƚ�������ܳ�
						maxlen=len;
				}
			}
	if (maxlen>0)
		printf("������ε��ܳ�=%d\n",maxlen);
	else
		printf("0\n");
}
void main()
{	int a[]={4,5,8,20};
	int n=4;
	solve(a,n);
}
