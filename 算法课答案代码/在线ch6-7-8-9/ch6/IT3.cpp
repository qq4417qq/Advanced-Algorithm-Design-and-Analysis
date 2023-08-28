#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 10
#define MAXM 10
//�����ʾ
int n;									//������
int m;									//��Ӧ����
int cost;								//�޶��۸�
int w[MAXN][MAXM];						//w[i][j]Ϊ��i�������ڵ�j����Ӧ�̵�����
int c[MAXN][MAXM];						//c[i][j]Ϊ��i�������ڵ�j����Ӧ�̵ļ۸�
typedef struct 
{	int no;								//�����
	int i;								//��ǰ����ڽ�ռ��еĲ��
	int w;								//��ǰ����������
	int c;								//��ǰ�����ܼ۸�
	int x[MAXN];						//x[i]��ʾ����i��Ӧ�Ĺ�Ӧ�̣���������
	int y[MAXN];						//y[j]��ʾ��Ӧ��j�Ƿ��й�����y[j]=0��ʾû�й���
} NodeType;
struct Cmp								//�����й�ϵ�ȽϺ���
{	bool operator()(const NodeType &s,const NodeType &t)
	{	return (s.w>t.w) || (s.w==t.w && s.c>t.c);
		//wԽСԽ����,��w��ͬʱvԽСԽ����
	}
};
//�������ʾ
int bestw=INF;							//���ŷ�����������
int bestc=INF;							//���ŷ������ܼ۸�
int bestx[MAXN];							//���ŷ���,bestx[i]��ʾ����i����Ĺ�Ӧ��
int Count=1;								//�����ռ��н�����ۼ�,ȫ�ֱ���
void solve()								//����С����������Ƶ����Ž�
{	NodeType e,e1;						//����2�����
	priority_queue<NodeType,vector<NodeType>,Cmp > qu;	//����һ�����ȶ���qu
	e.no=Count++;							//���ý����
	e.i=0;								//������μ�Ϊ0,Ҷ�����Ϊn
	e.w=0;
	e.c=0;
	memset(e.x,0,sizeof(e.x));			//��ʼ�������Ľ�����
	memset(e.y,0,sizeof(e.y));			//��ʼ��������y
	qu.push(e);							//��������
	while (!qu.empty())					//�Ӳ���ѭ��
	{	e=qu.top(); qu.pop();				//���ӽ��e��Ϊ��ǰ���
		if (e.i==n)						//e��һ��Ҷ���
		{	if (e.c<=cost && e.c<bestc && e.w<bestw)	//�Ƚ������Ž�
			{	//ѡ���ܼ۸�<cost,��С��������С�۸�ķ���
				bestw=e.w;				//����bestw
				bestc=e.c;				//����bestc
				for (int j=1;j<=n;j++)	//���ƽ�����e.x->bestx
					bestx[j]=e.x[j];
			}
		}
		else								//e����Ҷ���
		{	for (int j=1; j<=m; j++)			//ÿһ�������й�Ӧ��j
			{

				if (e.y[j]==0)				//��Ӧ��j��û�й���
				{	if (e.c+c[e.i+1][j]<=cost && e.c+c[e.i+1][j]<bestc 
						&& e.w+w[e.i+1][j]<bestw)
					{	/*��֦��ѡ���ܼ۸�<=cost,������С����С������
							   �ܼ۸�С����С�۸������չ*/
						e1.no=Count++;			//���ý����
						e1.i=e.i+1;				//�������ӽ��
						e1.w=e.w+w[e1.i][j];		//�޸�e.w
						e1.c=e.c+c[e1.i][j];		//�޸�e.c
						for (int k=0; k<=n; k++) //���ƽ�����e.x->e1.x
							e1.x[k]=e.x[k];
						for (int k1=0; k1<=n; k1++) //����e.y->e1.y
							e1.y[k1]=e.y[k1];
						e1.x[e1.i]=j;		//Ϊ����ѡ��ѡ��Ӧ��j
						e1.y[j]=1;
						qu.push(e1);		//���ӽ��e1����
					}
				}
			}
		}
	}
}
int main()
{	int i,j;
	scanf("%d%d%d",&n,&m,&cost);	//���벿����,��Ӧ����,�޶��۸�
	for(i=1; i<=n; i++)				//������������ڲ�ͬ��Ӧ�̵�����
		for(j=1; j<=m; j++)
			scanf("%d",&w[i][j]);
	for(i=1; i<=n; i++)				//������������ڲ�ͬ��Ӧ�̵ļ۸�
		for(j=1; j<=m; j++)
			scanf("%d",&c[i][j]);
	solve();
	for(i=1;i<=n;i++)				//���ÿ�������Ĺ�Ӧ��
		printf("%d ",bestx[i]);
	printf("\n%d\n",bestw);			//�����С����
	return 0;
}
