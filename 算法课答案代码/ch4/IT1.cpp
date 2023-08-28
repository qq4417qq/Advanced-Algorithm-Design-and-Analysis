#include <stdio.h>
//问题表示
double a,b,c,d;
 
void solve()
{
	double x;
	for (int i=-10000;i<=10000;i++)	 //枚举
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
