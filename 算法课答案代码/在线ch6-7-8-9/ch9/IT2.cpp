#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INF 0x3f3f3f3f					//����������
int root[MAX];							//root[i]=j��ʾ����i������ͨ�����ĸ�Ϊ����j
int find(int i)							//���Ҷ���i���ڵ���ͨ�������
{
    return i==root[i] ? i:find(root[i]);
}
int main()
{	int A[MAX][MAX],S[MAX],dist[MAX];
	int i,j,a,b,cost;
    	int n,m;
    	while (scanf("%d %d",&n,&m)!=EOF)	//��ȡ�ڽӾ���A
    	{	for (i=0;i<n;i++)
        	{	root[i]=i;
            	S[i]=0;
        	}
        	for (i=0;i<n;i++)					//��ʼ���ڽӾ���A
        	{	for (j=0;j<n;j++)
                A[i][j]=INF;
            A[i][i]=0;
        	}
		cost=1;						//�߳��ȴ�1��ʼ
        	for (i=0;i<m;i++)
        	{	scanf("%d %d",&a,&b);
            	int x=find(a);
            	int y=find(b);
            	if (x!=y)					//��Ч��
            	{	root[x]=y;				//y��Ϊx�ĸ�
                	A[a][b]=A[b][a]=cost;		//����ͼ���ǶԳƵ�
            	}
            	cost=cost*2 % 100000;		//cost��������
        	}
    	}
	for (i=0;i<n;i++)						//Dijkstra�㷨
		dist[i]=A[0][i];
    	S[0]=1;
    	for (i=0;i<n;i++)
    	{	int min=INF,u;
        	for (j=0;j<n;j++)
        	{	if (S[j]==0 && dist[j]<INF)
            	{	u=j;
                	min=dist[j];
            	}
        	}
        	S[u]=1;
        	for (j=1;j<n;j++)
        	{	if (S[j]==0)
				if (A[u][j]<INF && dist[u]+A[u][j]<dist[j])
					dist[j]=dist[u]+A[u][j];
        	}
    	}
    	for (i=1;i<n;i++)						//������
		if (dist[i]==INF)					//û��·��
			printf("-1\n");
		else							//����·��
			printf("%d\n",dist[i] % 100000);
    	return 0;
}
