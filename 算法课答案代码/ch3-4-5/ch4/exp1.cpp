#include <stdio.h>
int SQRT(int n)
{
	int m=1;
	while (m*m<=n)		//ö��m
		m++;
	return m-1;
}
void main()
{
	printf("�����:\n");
	for (int n=1;n<=20;n++)
	{
		printf("\tSQRT(%d)=%d",n,SQRT(n));
		if (n%2==0) printf("\n");
	}
}
