//�ϻ�ʵ����3
#include <stdio.h>
void fun(int n) 
{	int x,y,z;
	int count=0;
	for (z=0;z<=n/5;z++)
		for (y=0;y<=(n-z*5)/2;y++)
			if (5*z+2*y<=n)
			{	x=n-5*z-2*y;
				printf("�ҷ�%d: ",++count);
				if (z!=0) printf("5��Ӳ��%d�� ",z);
				if (y!=0) printf("2��Ӳ��%d�� ",y);
				if (x!=0) printf("1��Ӳ��%d��",x);
				printf("\n");
			}
	printf("����%d�ֶҷ�\n",count); 
} 
void main() 
{	int n=10;
	fun(n);
}
