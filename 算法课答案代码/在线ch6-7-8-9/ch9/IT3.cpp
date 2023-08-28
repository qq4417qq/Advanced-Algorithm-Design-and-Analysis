#include <iostream>    
#include <queue>    
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define N 101    
#define M 101 
#define INF 0x3f3f3f3f    
//�����ʾ
int m,n,s,t;    
char map[M][N];				//��������ͼ    
struct man					//��¼С�˵�����    
{    
    int x,y;    
} man[N];    
struct house				//��¼���ӵ�����    
{    
    int x,y;    
} house[N];
struct Edge					//������
{	int from,to;				//һ����(from,to)
	int flow;					//�ߵ�����
	int cap;					//�ߵ�����
	int cost;					//�ߵĵ���������
};
vector<Edge> edges;				//������������б�
vector<int> G[N];				//�ڽӱ�G[i][j]��ʾ����i�ĵ�j������edges�����е��±�
//�������ʾ
int mincost;					//���������С����
bool visited[N];
int pre[N],a[N],dist[N];
void Init()						//��ʼ��
{
	for (int i=0; i<n; i++)		//ɾ�����������
		G[i].clear();
	edges.clear();				//ɾ�����б�
}
void AddEdge(int from,int to,int cap,int cost)	//���һ����
{	Edge temp1 = {from,to,0,cap,cost};	//ǰ��ߣ���ʼ����Ϊ0
	Edge temp2 = {to,from,0,0,-cost };	//����ߣ���ʼ����Ϊ0
	edges.push_back(temp1);				//���ǰ���
	G[from].push_back(edges.size()-1);	//ǰ��ߵ�λ��
	edges.push_back(temp2);				//��ӷ����
	G[to].push_back(edges.size()-1);	//����ߵ�λ��
}
bool SPFA()								//SPFA�㷨��cost��С��·��
{	for (int i=0; i<=t;i++)				//��ʼ��dist����
		dist[i]=INF;
	dist[s]=0;
	memset(visited,0,sizeof(visited));
	memset(pre, -1, sizeof(pre));
	pre[s]=-1;						//����ǰ��Ϊ-1
	queue<int> qu;					//����һ������
	qu.push(s);
	visited[s]=1;
	a[s]=INF;
	while (!qu.empty())				//���в���ѭ��
	{	int u=qu.front(); qu.pop();
		visited[u]=0;
		for (int i=0; i<G[u].size();i++)		//���Ҷ���u�����й�����
		{	Edge &e=edges[G[u][i]];			//������e=(u,G[u][i])
			if (e.cap>e.flow && dist[e.to]>dist[u]+e.cost)	//�ɳ�
			{	dist[e.to]=dist[u]+e.cost;
				pre[e.to]=G[u][i];			//����e.to��ǰ������ΪG[u][i]
				a[e.to]=min(a[u], e.cap-e.flow);
				if (!visited[e.to])		//e.to���ڶ�����
				{	qu.push(e.to);		//��e.to����
					visited[e.to]=1;
				}
			}
 		}
	}
	if (dist[t]==INF)						//�Ҳ����յ㣬����false
		return false;
	mincost += dist[t]*a[t];				//�ۼ���С����
	for (int j=t; j!=s; j=edges[pre[j]].from)	//��������·������
	{
		edges[pre[j]].flow += a[t];			//ǰ�������a[t]
		edges[pre[j]+1].flow -= a[t];		//����߼���a[t]
	}
	return true;							//�ҵ��յ㣬����true
}
void MinCost()							//���s��t����С����
{
	while (SPFA());						//SPFA�㷨���������
}
void CreateG()						//��������G
{    
    int mcase=0,hcase=0;			//��¼�ж��ٸ�С�˺ͷ���    
    int i,j;    
    for(i=1; i<=m; i++)
    {    
        for(j=1; j<=n; j++)
        {    
            cin >> map[i][j];    
            if(map[i][j]=='m')		//��¼С�˵�����
            {    
                mcase++;
                man[mcase].x=i;    
                man[mcase].y=j;    
            }    
            if(map[i][j]=='H')		//��¼���ӵ�����
            {    
                hcase++;    
                house[hcase].x=i;    
                house[hcase].y=j;    
            }    
        }    
    }
    s=0;
    t=mcase+hcase+1;					//�������0���յ�t�����������ṹ
    for(i=1; i<=mcase; i++)				//�������е�С��
    {    
		AddEdge(0,i,1,0);				//��㵽����С��֮��ĵ�����Ϊ1,����Ϊ0
        for(j=1; j<=hcase; j++)		//�������еķ���
        {    
            int w=abs(house[j].x-man[i].x)+abs(house[j].y-man[i].y);//����С�˵�ÿ������֮��ľ���
			AddEdge(i,mcase+j,1,w);		//С�˺ͷ���֮�������Ϊ1,����ȡΪw
		}    
    }
	for (j=1;j<=hcase; j++)
		AddEdge(mcase+j,t,1,0);			//�������ӵ��յ�֮�������Ϊ1,����ȡΪ0
}
int main()
{    
    while(true)
	{
		cin >> m >> n;					//����m,n
		if (m==0 || n==0) break;
		mincost=0;						//��ʼ����С����Ϊ0
		Init();
		CreateG();
        MinCost();						//��������0���յ�t֮����������С����    
        cout << mincost << endl;    
    }    
    return 0;
}