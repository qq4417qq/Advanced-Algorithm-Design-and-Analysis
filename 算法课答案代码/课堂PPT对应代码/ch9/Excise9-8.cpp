//练习题8
#include<stdio.h>
#include<memory.h>
#define MAX 31
int a[][2]={0,1,1,0,0,-1,-1,0};			//右、下、左、上四个方位
int n,biao,d;
char b[MAX][MAX];
int v[MAX][MAX];
void DFS(int x,int y)
{	if(biao==1)
		return ;
	int i,xx,yy;
	for (i=0;i<4;i++)					//找(x,y)的四个方位(xx,yy)
	{	xx=x+a[i][0];
		yy=y+a[i][1];
		if (xx>=0 && xx<=n && yy>=0 && yy<=n && v[xx][yy]!=-1)
		{	if (b[xx][yy]=='a')			//遇到Amaze,结束
			{	biao=1;
				break;
			}
			else if (b[xx][yy]=='r')	//遇到道路
			{	if(d==0)
				{	v[xx][yy]=-1;		//将(xx,yy)位置元素置为-1,避免重复搜索
					DFS(xx,yy);
				}
				else if (d==1 && v[xx][yy]==0)
				{	v[xx][yy]=1;		//元素值置为1时表示访问过该位置
					DFS(xx,yy);			//从(xx,yy)出发继续搜索
				}
			}
			else if (b[xx][yy]=='d')	//遇到野狗
			{	if (d==0)
				{	v[xx][yy]=-1;		//将(xx,yy)位置元素置为-1,避免重复搜索
					d++;				//遇到野狗的次数增1
					DFS(xx,yy);			//从(xx,yy)出发继续搜索
					d--;				//回溯
				}
			}
		}
	}
}
int main()
{	int t,i,j,x,y;
	scanf("%d",&t);					//输入t
	while (t--)
	{	biao=0;
		d=0;
		memset(v,0,sizeof(v));		//置v的所有元素为ASCII为0字符
		scanf("%d",&n);				//输入n
		for(i=0;i<n;i++)			//输入一个测试用例
			scanf("%s",b[i]);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{	if(b[i][j]=='p')	//找到Magicpig的位置(x,y)
				{	x=i;
					y=j;
				}
			if(b[i][j]=='k')		//将金刚位置的元素置为-1
				v[i][j]=-1;
			}
		v[x][y]=-1;					//将Magicpig的位置(x,y)的元素值为-1,避免重复搜索
		DFS(x,y);					//从(x,y)开始搜索
		if(biao==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
