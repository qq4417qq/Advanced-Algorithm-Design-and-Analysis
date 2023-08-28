#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 101
#define MAXE (MAX*(MAX-1)/2)
//�����ʾ
int n;								//�������
int m;								//����
struct Edge							//������
{	int a;							//�ߵ����
	int b;							//�ߵ��յ�
	int d;							//�߳���
};
Edge road[MAXE];
int tree[MAX];						//���鼯
int find_root(int a)					//�ڲ��鼯�в���a�ĸ�
{
	if (tree[a]==-1)
		return a;					//aΪ��,����a
    int tmp=find_root(tree[a]);
   	tree[a]=tmp;					//a���Ǹ�,����ָ���tmp
    return tmp;
}
bool cmp(Edge a,Edge b)				//����ȽϺ���
{    if (a.d<b.d) return true;
    return false;						//���ڰ��߳��ȵ�������
}
int solve()							//����Kruskal�㷨���
{	sort(road,road+m,cmp);			//���߳��ȵ�������
	int ans=0;						//�����ͳɱ�
	for(int i=0;i<m;i++)
	{	//��i���ߵ�����������a��b
		int ra=find_root(road[i].a);		//���Ҷ���a�ĸ�
		int rb=find_root(road[i].b);		//���Ҷ���b�ĸ�
		if(ra!=rb)					//�����ǵĸ���ͬ,ȡ�ñߵĳɱ�
		{	tree[rb]=ra;
			ans+=road[i].d;
		}
	}
	return ans;
}  
int main()
{	int f;
    	while(scanf("%d",&n)!=EOF && n!=0)
	{	m=n*(n-1)/2;
        	for(int i=0;i<=n;i++)			//��ʼ�����鼯
            	tree[i]=-1;
        	for(int j=0;j<m;j++)			//����
		{	scanf("%d%d%d%d",&road[j].a,&road[j].b,&road[j].d,&f);
			if(f==1) road[j].d=0;		//�ѽ���·�ɱ�Ϊ0
        	}
		printf("%d\n",solve());
	}
    	return 0;
}
