#include<stdio.h>
#include<string.h>
#include <queue>
using namespace std;
#define MAXV 200001
//�����ʾ
int A[MAXV][MAXV];		//ͼ���ڽӾ���
int n,m,k;
int sno,eno;
int visited[MAXV];
struct NodeType
{
	int vno;			//������
	int length;			//·������
};
int bfs(int sno,int eno)		//������������㷨
{
	if (sno==eno) return 0;
	NodeType e,e1;
	queue<NodeType> qu;				//�������
	e.vno=sno;
	e.length=0;
	qu.push(e);						//���e����
	visited[e.vno]=1;
	while (!qu.empty())				//���в���ѭ��
	{
		e=qu.front(); qu.pop();		//���ӽ��e
		if (e.vno==eno) 
			return e.length-1;
		for (int j=0;j<n;j++)
		{
			if (A[e.vno][j]!=0)			//������j�б�
			{
				if (visited[j]==0)
				{
					e1.vno=j;
					e1.length=e.length+1;
					qu.push(e1);
					visited[j]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d",&n,&m)==2)
	{
		int a,b,i;
		memset(A,0,sizeof(A));
		memset(visited,0,sizeof(visited));
		for (i=0;i<m;i++)		//�������뽨���ڽӾ���
		{
			scanf("%d%d",&a,&b);
			A[a][b]=1;			//����ͼ
			A[b][a]=1;
		}
		scanf("%d",&k);
		for (i=0;i<k;i++)
		{
			scanf("%d %d",&sno,&eno);
			printf("%d\n",bfs(sno,eno));
		}
	}
	return 0;
}
