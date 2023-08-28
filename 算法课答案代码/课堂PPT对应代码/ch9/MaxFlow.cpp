//��������ĸ���-������ѷ�㷨
#include <stdio.h>
#include <memory.h>
#define INF 32767						//��
#define MAXV 20
int p[MAXV],a[MAXV],visited[MAXV];		//ȫ�ֱ���
int s,t,n;								//ȫ�ֱ���
void Dispnetwork(int a[][MAXV])			//�����ά����a
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i][j]==INF)
				printf("��\t");
			else if (i!=j)
				printf("%d\t",a[i][j]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}
void DFS(int c[][MAXV],int f[][MAXV],int n,int u)		//��һ��������
{
	int v;
	if (visited[t]==1)
		return;
	visited[u]=1;
	printf("%d  ",u);
	for (v=1;v<=t;v++)		//����ǰ���
	{
		if (c[u][v]>0 && c[u][v]!=INF && visited[v]==0 && c[u][v]>f[u][v])
		{
			a[v]=c[u][v]-f[u][v];
			p[v]=u;
			//printf("ǰ���(%d,%d),a[%d]=%d,p[%d]=%d\t",u,v,v,a[v],v,p[v]);
			DFS(c,f,n,v);
		}
	}
	for (v=1;v<=t;v++)		//���������
	{
		if (c[v][u]>0 && c[v][u]!=INF && visited[v]==0 && f[v][u]>0)
		{
			a[v]=f[v][u];
			p[v]=-u;
			//printf("�����(%d,%d),a[%d]=%d,p[%d]=%d\t",v,u,v,a[v],v,p[v]);
			DFS(c,f,n,v);
		}
	}
}
void argument(int f[][MAXV],int p[],int a[],int n)		//��������
{
	int u,v,min=INF;
	for (v=s;v<=t;v++)
		if (a[v]!=0 && a[v]<min)
			min=a[v];
	printf("  ��С������=%d\n",min);
	u=t; v=p[u];
	while (true)
	{
		if (v>=0)
		{
			f[v][u]+=min;
			printf("  ������f(%d,%d)=%d\n",v,u,f[v][u]);
			u=v;

		}
		else
		{
			f[u][-v]-=min;
			printf("  ������f(%d,%d)=%d\n",u,-v,f[u][-v]);
			u=-v;
		}
		if (u==s) break;
		v=p[u];
	}
}
int Maxflow(int c[][MAXV],int f[][MAXV],int n)	//�������
{
	int count=0,v,maxf=0;
	while (true)
	{
		memset(visited,0,sizeof(visited));
		memset(p,0,sizeof(p));
		memset(a,0,sizeof(a));
		printf("��%d�ε���:\n",++count);
		p[s]=0; a[s]=INF;
		printf("  ��һ�����������ʶ�������:");
		DFS(c,f,n,s); printf("\n");
		printf("  ��������:");
		for (int i=0;i<n;i++)
			if (a[i]==INF)
				printf("%d:(%d,��)  ",i,p[i]);
			else
				printf("%d:(%d,%d)  ",i,p[i],a[i]);
		printf("\n");
		if (visited[t]==0)		//û�б���յ�ʱ�˳�ѭ��
		{
			printf("���ٴ���������\n");
			break;
		}
		argument(f,p,a,n);
		printf("f:\n"); Dispnetwork(f);
	}
	for (v=1;v<=t;v++)
		if (c[s][v]!=0 && c[s][v]!=INF)
			maxf+=f[s][v];
	return maxf;
}


void main()
{
	int f[][MAXV]={					//һ��������
		{0,6,10,INF,INF,INF,INF},
		{INF,0,INF,3,6,INF,INF},
		{INF,3,0,0,INF,7,INF},
		{INF,INF,INF,0,1,1,3},
		{INF,INF,INF,INF,0,INF,7},
		{INF,INF,INF,1,INF,0,6},
		{INF,INF,INF,INF,INF,INF,0}};
	int c[][MAXV]={					//һ������������
		{0,8,14,INF,INF,INF,INF},
		{INF,0,INF,3,6,INF,INF},
		{INF,5,0,3,INF,8,INF},
		{INF,INF,INF,0,4,3,10},
		{INF,INF,INF,INF,0,INF,7},
		{INF,INF,INF,3,INF,0,6},
		{INF,INF,INF,INF,INF,INF,0}};
	n=7; s=0; t=n-1;
	printf("�������=%d\n",Maxflow(c,f,n));
	printf("�����f:\n"); Dispnetwork(f);	//������������
}
