#include <stdio.h>
#define INF 0x3f3f3f3f			//�����
#define MAXV 101
int A[MAXV][MAXV];			//�ڽӾ���
int n,m;
int s,t;
int dist[MAXV];
void BellmanFord(int v)			//������-�����㷨
{	int i,k,u;
	for (i=0;i<n;i++)
		dist[i]=A[v][i];		//��dist0[i]��ʼ��
	for (k=1;k<n;k++)			//��dist0[u]���Ƴ�dist2[u], ��,distn-1[u]ѭ��n-2��
	{	for (u=0;u<n; u++)		//�޸����зǶ���v��dist[]ֵ
		{	if (u!=v)
			{	for (i=0;i<n;i++)	
				{	if (A[i][u]<INF && dist[u]>dist[i]+A[i][u])
						dist[u]=dist[i]+A[i][u];
				}
			}
		}
	}
}
int main()
{	int i,j;
	int a,b,l;
	scanf("%d%d",&n,&m);		//����n��m
	for (i=0;i<n;i++)				//��ʼ���ڽӾ���
		for (j=0;j<n;j++)
			if (i==j)
				A[i][j]=0;
			else
				A[i][j]=INF;
	for (i=0;i<m;i++)			//�����
	{	scanf("%d%d%d",&a,&b,&l);
		A[a][b]=-l;
	}
	scanf("%d%d",&s,&t);		//����s��t
	BellmanFord(s);				//����BellmanFord�㷨��s���������·��
	printf("%d\n",-dist[t]);		//������
	return 1;
}
