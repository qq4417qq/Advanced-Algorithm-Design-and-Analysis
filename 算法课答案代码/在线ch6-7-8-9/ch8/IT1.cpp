#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
const int N=100;
double D[N];
double dp[N];
int n;
double sum=1.0;						//��Ż��ι�·���ܳ���
void preprocess()					//��dp[i]��sum
{
	dp[0]=D[0];
	for (int i=1;i<n;i++)
	{	dp[i]=dp[i-1]+D[i];			//��dp[i]
		sum+=D[i];					//��sum
	}
}
double Distance(int i,int j)		//��֤j>i
{	double pathsum1=dp[j-1]-dp[i-1];
	double pathsum2=sum-pathsum1;
	return min(pathsum1,pathsum2);
}
int main()
{
	int a,b;
	scanf("%d",&n);					//����n
	D[0]=1.0;
	for(int i=1;i<n;i++)			//����D[1..n-1]
		scanf("%lf",&D[i]);
	preprocess();
	scanf("%d%d",&a,&b);
	if (a<b)
		printf("%g\n",Distance(a,b));
	else
		printf("%g\n",Distance(b,a));
    return 0;
}
