//求解最长公共子序列问题的算法
#include <stdio.h>
#include <string.h>
#define N 30							//序列中最多的字符个数
int lcslength(char *a,char *b,int c[][N])	//求c[m][n]即最长公共子序列的长度
{	int m=strlen(a),n=strlen(b);		//m为a的长度，n为b的长度
	int i,j;
	for (i=0;i<=m;i++)					//将c[i][0]和c[0][i]置为0,情况①
		c[i][0]=0;
	for (i=0;i<=n;i++)
		c[0][i]=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)				//两重for循环处理a、b的所有字符
		{	if (a[i-1]==b[j-1])		//处理情况②
				c[i][j]=c[i-1][j-1]+1;
			else						//处理情况③
			{	if (c[i-1][j]>=c[i][j-1])
					c[i][j]=c[i-1][j];
				else c[i][j]=c[i][j-1];
			}
		}
	return c[m][n];
}
char *buildlcs(char *a,char *b)		//求a、b的最长公共子序列
{	int k,i=strlen(a),j=strlen(b);
	int c[N][N];
	k=lcslength(a,b,c);			//k为a和b的最长公共子序列长度
	static char s[N];				//s存放a和b的最长公共子序列
	s[k]='\0';					//先在s中添加一个结束符
	while (k>0)					//在s中放入s个字符
		if (c[i][j]==c[i-1][j]) i--;
		else if (c[i][j]==c[i][j-1]) j--;
		else
		{	s[--k]=a[i-1];
			i--; j--;
		}
	return s;						//返回a和b的最长公共子序列
}
void main()
{	char X[]="abcbdb";
	char Y[]="acbbabdbb";
	printf("X:%s\n",X);
	printf("Y:%s\n",Y);
	printf("X、Y的最长公共子序列为%s\n",buildlcs(X,Y));
}
