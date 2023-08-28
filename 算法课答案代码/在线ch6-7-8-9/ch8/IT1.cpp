#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
const int N=100;
double D[N];
double dp[N];
int n;
double sum=1.0;						//存放环形公路的总长度
void preprocess()					//求dp[i]和sum
{
	dp[0]=D[0];
	for (int i=1;i<n;i++)
	{	dp[i]=dp[i-1]+D[i];			//求dp[i]
		sum+=D[i];					//求sum
	}
}
double Distance(int i,int j)		//保证j>i
{	double pathsum1=dp[j-1]-dp[i-1];
	double pathsum2=sum-pathsum1;
	return min(pathsum1,pathsum2);
}
int main()
{
	int a,b;
	scanf("%d",&n);					//输入n
	D[0]=1.0;
	for(int i=1;i<n;i++)			//输入D[1..n-1]
		scanf("%lf",&D[i]);
	preprocess();
	scanf("%d%d",&a,&b);
	if (a<b)
		printf("%g\n",Distance(a,b));
	else
		printf("%g\n",Distance(b,a));
    return 0;
}
