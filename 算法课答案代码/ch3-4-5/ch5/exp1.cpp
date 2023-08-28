#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
//问题表示
int w[12];
string a[3]={"ABCD","ABCI","ABIJ"};
string b[3]={"EFGH","EFJK","EFGH"};
string c[]={"even","up","even"};
bool Balanced()					//判断是否与称重结果匹配
{
	for (int i=0;i<3;i++)		//3次称重
	{
		int leftw=0;
		int rightw=0;
		for (int j=0;j<a[i].size();j++)
		{
			leftw+=w[a[i][j]-'A'];
			rightw+=w[b[i][j]-'A'];
		}
		if (leftw<rightw && c[i]!="down")
			return false;
		if (leftw==rightw && c[i]!="even")
			return false;
		if (leftw>rightw && c[i]!="up")
			return false;
	}
	return true;
}
void solve(int &x,int &y)					//求假币
{
	for (int i=0;i<12;i++)
	{
		w[i]=1;				//第i个硬币为假币，并且重量较重
		if (Balanced())
		{
			x=i;
			y=1;
			return;
		}
		w[i]=-1;			//第i个硬币为假币，并且重量较轻
		if (Balanced())
		{
			x=i;
			y=-1;
			return;
		}
		w[i]=0;				//回溯，恢复第i个硬币为真币
	}
}
void main()
{
	memset(w,0,sizeof(w));	//初始化所有硬币为真币
	int x,y;
	solve(x,y);
	printf("求解结果\n");
	printf("   假币是%c\n",x+'A');
	if (y==1)
		printf("   该硬币较真币重量重\n");
	else
		printf("   该硬币较真币重量轻\n");
}

