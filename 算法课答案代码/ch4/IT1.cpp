#include <stdio.h>
//�����ʾ
double a,b,c,d;
 
void solve()
{
	double x;
	for (int i=-10000;i<=10000;i++)	 //ö��
	{
		x=i/100.0;
		double fx=a*x*x*x+b*x*x+c*x+d;
		if (fx>-0.0001 && fx<0.0001)
			printf("%6.2f ",x);
	}
	printf("\n");
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	solve();
	return 0;
}
