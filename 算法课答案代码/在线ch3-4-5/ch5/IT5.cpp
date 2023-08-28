#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 21
#define MAXM 21
int dx[4]={1,2,2,1};
int dy[4]={-2,-1,1,2};
//�����ʾ
int n,m;
//�������ʾ
int cnt;
int visited[MAXM][MAXN];
void solve(int x,int y)						//����㷨
{
	visited[x][y]=1;
	if (x==n && y==m)						//�ҵ�Ŀ��λ��
		cnt++;								//·����������1
	for (int i=0;i<=3;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if (x1<1 || x1>n || y1<1 || y1>m)	//����Խ��λ��
			continue;
		if (visited[x1][y1]==0)				//��������û�з��ʵ�λ��
			solve(x1,y1);
	}
	visited[x][y]=0;						//����
}
int main()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) break;
		cnt=0;
		memset(visited,0,sizeof(visited));
		solve(1,1);
		printf("%d\n",cnt);
	}
	return 0;
}



