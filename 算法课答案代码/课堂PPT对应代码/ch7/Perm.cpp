//���ȫ����������㷨
#include <stdio.h>
void perm(char s[],int k,int n)
{	int i;
	char tmp;
	if (k==n-1)							//���һ������
	{	for (i=0;i<n;i++)
			printf("%c ",s[i]);
		printf("\n");
	}
	else
	{	for (i=k;i<n;i++)
		{	tmp=s[k];s[k]=s[i];s[i]=tmp; //����s[k]��s[i]
			perm(s,k+1,n);
			tmp=s[k];s[k]=s[i];s[i]=tmp; //����s[k]��s[i],�ָ�����������
		}
	}
}
void main()
{	int n=3;
	char s[]="123";
	perm(s,0,n);
}
