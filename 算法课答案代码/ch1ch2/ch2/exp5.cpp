#include <stdio.h>
int gcd1(int x, int y)	//�ݹ��㷨
{
    if(y==0)
        return x;
    return gcd1(y,x%y);
}
int gcd2(int x,int y)	//�ǵݹ��㷨
{
	int z;
	while(y!=0)			//������Ϊ0�����������ֱ������Ϊ0
	{
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}
void main()
{	printf("ʵ����:\n");
	int x=5,y=12;
	printf("  gcd1(%d,%d) = %d\n",x,y,gcd1(x,y));
	printf("  gcd2(%d,%d) = %d\n",x,y,gcd2(x,y));
	x=24; y=18;
	printf("  gcd1(%d,%d) = %d\n",x,y,gcd1(x,y));
	printf("  gcd2(%d,%d) = %d\n",x,y,gcd2(x,y));
}
