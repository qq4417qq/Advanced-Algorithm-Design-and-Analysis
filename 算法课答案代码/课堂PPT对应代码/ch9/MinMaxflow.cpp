//����С����������㷨
#include <stdio.h>
#define MAXV 10
#define INF 32767
int s,t,n;						//ȫ�ֱ���,�ֱ��ʾ��㡢�յ�Ͷ������
void disp(int a[][MAXV])		//���һ������
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (a[i][j]!=INF)
				printf("%4d",a[i][j]);
			else
				printf("%4s","��");
			printf("\n");
	}
}
void Createw(int c[][MAXV],int f[][MAXV],int b[][MAXV],int w[][MAXV])	//����һ����Ȩͼw
{
	int i,j;
	for (i=0;i<n;i++)			//w����Ԫ�س�ʼ��
		for (j=0;j<n;j++)
			w[i][j]=INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			if (c[i][j]!=0 && c[i][j]<INF)
			{
				if (f[i][j]<c[i][j])
					w[i][j]=b[i][j];
				else if (f[i][j]==c[i][j])
					w[i][j]=INF;
				if (f[i][j]>0)
					w[j][i]=-b[i][j];
				else if (f[i][j]==0)
					w[j][i]=INF;
			}
			else if (i==j)
				w[i][j]=0;
		}
}
bool BellmanFord(int w[][MAXV],int v,int path[])	//��w���s��t�����·��path
{
	int i,k,u;
	int dist[MAXV];
	for (i=0;i<n;i++)
	{
		dist[i]=w[v][i];			//��dist(1)[i]��ʼ��
		if (i!=v && dist[i]<INF) 
			path[i]=v;				//��path(1)[i]��ʼ��
		else 
			path[i]=-1;
	}
	for (k=2;k<n;k++)
	{
		for (u=0;u<n; u++)			//�޸�ÿ�������dist[u]��path[u]
		{
			if (u!=v)
			{
				for (i=0;i<n;i++)	//��������ÿ������
				{
					if (w[i][u]<INF && dist[u]>dist[i]+w[i][u])
					{
						dist[u]=dist[i]+w[i][u];
						path[u]=i;
					}
				}
			}
		}
	}
	if (path[t]==-1)
		return false;	//��û�д���㵽�յ�����·��,����false
	else
		return true;	//�����ڴ���㵽�յ�����·��,����true
}
int Getarg(int c[][MAXV],int f[][MAXV],int path[])	//��path��ʾ�ĵ�������min
{
	int i,j,min=INF;
	printf("path:");
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
	j=t,i=path[j];
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//ǰ���
		{
			printf("%d  ",c[i][j]-f[i][j]);
			if (c[i][j]-f[i][j]<min)
				min=c[i][j]-f[i][j];
		}
		if (c[j][i]>0 && c[j][i]<min)		//�����
		{
			printf("%d ",f[i][j]);
			if (f[i][j]<min)
				min=f[i][j];
		}
		if (i==-1) break;					//���������ʱ�˳�ѭ��
		j=i;
		i=path[j];
	}
	//printf("������� MIN=%d\n",min);
	return min;
}
void argument(int c[][MAXV],int f[][MAXV],int path[],int min)	//���ݵ�������min�����������е���
{
	int i,j;
	j=t,i=path[j];
	printf("��������\n");
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//ǰ���
		{
			f[i][j]+=min;
			printf("f[%d][%d]����Ϊ%d\n",i,j,f[i][j]);
		}
		if (c[j][i]>0 && c[j][i]<min)		//�����
		{
			f[j][i]-=min;
			printf("f[%d][%d]����Ϊ%d\n",j,i,f[j][i]);
		}
		if (i==-1) break;					//���������ʱ�˳�ѭ��
		j=i;
		i=path[j];
	}
}
void Minmaxflow(int c[][MAXV],int b[][MAXV],int f[][MAXV])	//����С���������f
{
	int k=0;
	int path[MAXV],min;
	int w[MAXV][MAXV];	//��Ȩ����ͼ
	while (true)
	{
		printf("k=%d\n",k++);
		Createw(c,f,b,w);
		printf("w:\n"); disp(w);
		if (BellmanFord(w,s,path))
		{
			min=Getarg(c,f,path);
			printf("min=%d\n",min);
			argument(c,f,path,min);
			printf("f:\n");	disp(f);
		}
		else break;
	}
}
void main()
{
	n=6; s=0; t=n-1;
	int f[][MAXV]={				//��һ����������
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}};
	int c[][MAXV]={				//һ������������
		{0,4,5,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,2,INF},
		{INF,INF,INF,0,INF,5},
		{INF,1,INF,3,0,2},
		{INF,INF,INF,INF,INF,0}};
	int b[][MAXV]={				//һ����������λ��������
		{0,1,3,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,4,INF},
		{INF,INF,INF,0,INF,2},
		{INF,2,INF,1,0,4},
		{INF,INF,INF,INF,INF,0}};
	Minmaxflow(c,b,f);
	printf("��С�������������:\n");
	disp(f);
}
