#include<iostream>
#include<algorithm>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 101
//问题表示
struct Action
{	int no;							//作业编号
	int deadline;						//最后提交的时间
	int score;						//逾期的扣分
    	bool operator < (const Action t) const
    	{	if (score==t.score)			//扣分相同按提交时间递增排序
			return deadline<t.deadline;
		else
			return score>t.score;		//按逾期扣分递减排序
    }
};
int n;
Action A[MAX];
//求解结果表示
bool flag[MAX];						//空时间标志
int bests=0;							//最少的扣分
void solve()							//求解赶作业问题
{	int i,j;							//累计做过作业的时间
	for (i=0;i<n;i++)
	{	for (j=A[i].deadline;j>0;j--)	//在当前作业最后提交时间之前找空时间
		{	if (flag[j]==false)		//找到了空时间
			{	printf("%d ",A[i].no);	//选择做作业A[i].no
				flag[j]=true;
				break;
			}
		}
		if (j==0)						//当前作业最后提交时间之前找不到空时间
			bests+=A[i].score;			//不选择做作业A[i].no
	}
}
int main()
{	int i;
	while(true)
	{	scanf("%d",&n);
		if (n==0) break;
		for (i=0;i<n;i++)				//输入作业的最后提交时间 
		{	A[i].no=i+1;
			scanf("%d",&A[i].deadline);
		}
		for (i=0;i<n;i++)				//输入作业的逾期扣分 
			scanf("%d",&A[i].score);
		solve();
		printf("\n%d\n",bests);			//输出最少扣分
	}
	return 0;
}

