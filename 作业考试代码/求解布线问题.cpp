#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXQ 101
#define MAXN 10
#define MAXM 10
int H[4] = {0, 1, 0, -1};					//ˮƽƫ����,�±��Ӧ��λ��0��3
int V[4] = {-1, 0, 1, 0};					//��ֱƫ����
struct Position								//��������
{	int x,y;
	Position() {}
	Position(int i,int j)						//���캯��
	{	x=i;
		y=j;
	}
};
//�����ʾ
int n=7;
int m=7;
int grid[MAXN][MAXM]={
	{0,0,1,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0},
	{0,0,0,1,1,0,0},
	{1,0,0,0,1,0,0},
	{1,1,1,0,0,0,0},
	{1,1,1,0,0,0,0} };
Position a(2,1),b(3,5);						//��ʼλ��a��Ŀ��λ��b
//�������ʾ
int bestlen=INF;								//����·����·������
vector<Position> bestpath;						//����·��
int Count=0;								//�����ռ��н�����ۼ�,ȫ�ֱ���
//---------------�Լ���Ʒǻ��ζ���--------------
typedef struct 
{	int no;								//����ڶ��������е��±�
	Position p;								//��ǰ����С��к�
	int length;								//��ǰ����·������
	int pre;								//��ǰ���ĵ�ǰ������ڶ����е��±�
} NodeType;
class QUEUE								//�����ǻ��ζ�����
{
private:
	NodeType data[MAXQ];
	int front,rear;							//��ͷ��βָ��
public:
	QUEUE()								//���캯��
	{
		front=rear=-1;
	}	
	bool empty()							//�����㷨Ϊ��
	{
		return front==rear;
	}
	void push(NodeType e)					//���e����
	{	rear++;
		data[rear]=e;
	}
	NodeType pop()							//���ӽ��e
	{	front++;
		return data[front];
	}
	void GetPath(int s,vector<Position> &path)		//��s����һ����·��path
	{	int k=s;
		while (k!=-1)						//������preΪ-1
		{	path.push_back(data[k].p);
			k=data[k].pre;					//�����Ƶ�·��
		}
	}
};
//----------------------------------------------------------
void solve()								//������������Ž�
{	NodeType e,e1;						//����2�����
	Position p,p1;
	QUEUE qu;							//����һ������qu
	e.no=Count++;							//���ý��λ��
	e.pre=-1;
	e.p=a;								//��ʼ��
	e.length=0;
	qu.push(e);								//��������
	while (!qu.empty())						//�Ӳ���ѭ��
	{	e=qu.pop();						//���ӽ��e��Ϊ��ǰ���
		p=e.p;
		if (p.x==b.x && p.y==b.y)				//e��һ��Ҷ���
		{	if (e.length<bestlen)				//�Ƚ������Ž�
			{	bestlen=e.length;				//�������·������
				bestpath.clear();
				qu.GetPath(e.no,bestpath);		//�������·��
			}
		}
		else								//e����Ҷ���
		{	for (int j=0; j<4; j++)				//���e����Χ4�����
			{	p1.x=p.x+H[j];				//���p��һ�����ڽ��p1
				p1.y=p.y+V[j];
				if (p1.x>=0 && p1.x<n && p1.y>=0 && p1.y<m && grid[p1.x][p1.y]==0)
				{	//p1�����ǿ����ߵĽ��
					if (e.length+1<bestlen)	 	//��֦
					{	e1.no=Count++;		//���ý����
						e1.length=e.length+1;	//·��������1
						e1.pre=e.no;
						e1.p=p1;
						qu.push(e1);		//���ӽ�����
						grid[p1.x][p1.y]=-1;	//������������
					}
				}
			}
		}
	}
}
int main()
{	solve();
	printf("��ѷ���:\n");
	printf("  ·������=%d\n", bestlen);
	vector<Position>::reverse_iterator it;
	printf("  ·��: ");
	for (it=bestpath.rbegin();it!=bestpath.rend();++it)
		printf("[%d,%d] ",it->x,it->y);
	printf("\n");
	return 0;
}
