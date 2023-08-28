//��֦�޽編���TSP����
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <vector>
#include <queue>
using namespace std;
//�����Խ���ĳ���
struct Node					//�����ռ�����
{
public:
     int no;				//��ǰ����ı��
     int level;				//��ǰ������������
     vector<int> path;		//��ǰ·��
	 int pathlen;			//��ǰ·������
     Node(){};
     Node(int no1,int level1,vector<int> path1,int pathlen1)	//���캯��
	 {
		 no=no1;
		 level=level1;
		 path=path1;
		 pathlen=pathlen1;
	 };
     bool operator< (const Node &s) const	//���������
     {
          return pathlen>s.pathlen;
     }
};
void disp(int pathlen,vector<int> path)	//���·�����䳤��
{
	int i;
	printf("·������=%d\t",pathlen);
	printf("·��:");
	printf("%d",path[0]);
	for (i=1;i<path.size();i++)
		printf("��%d",path[i]);
	printf("\n");
}
vector<int> minpath;				//������·��
int minpathlen=INF;					//������·������
void TSP(MGraph g)
{
	bool find;
	int i,j,no,level1;				//һ���Ž��ֵ����ʱ����
	vector<int> path1,path;
	int pathlen1;
	priority_queue<Node> qu;		//�������ȶ���qu
	path.push_back(0);
	Node firstNode(0,0,path,0);		//�������0��Ӧ�Ľ��
	qu.push(firstNode);             //���0����
	Node node;
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		node=qu.top();				//ȡ��ͷ����node
		qu.pop();					//����
		printf("���Ӷ���:%d\n",node.no);
		for (i=1;i<g.n;i++)			//�Ӷ���1��n-1ѭ��
		{
			if (g.edges[node.no][i]!=0 && g.edges[node.no][i]!=INF)	//��ǰ���㵽����i�б�
			{
				find=false;
				for (j=0;j<node.path.size();j++)		//�ж϶���i�Ƿ���·����
					if (i==node.path[j])				//·�����ж���i
					{
						find=true;
						break;
					}
				if (!find)				//����i����·����
				{
					no=i;
					level1=node.level+1;
					path1=node.path;
					path1.push_back(i);
					pathlen1=node.pathlen+g.edges[node.no][i];
					printf("no=%d,level1=%d,",no,level1); disp(pathlen1,path1);
					if (level1>=g.n-1)
					{
						if (g.edges[no][0]!=0 && g.edges[no][0]!=INF)	//Ҷ�Ӷ��㵽���0�б�
						{
							pathlen1+=g.edges[no][0];			//�����no�����0��·��
							path1.push_back(0);					//·���м������0
							printf("Ҷ�ӽ��: "); disp(pathlen1,path1);
							if (pathlen1<minpathlen)
							{
								minpathlen=pathlen1;
								minpath=path1;
							}
						}
					}
					else
					{
						if (pathlen1<minpathlen)
						{
							Node snode(no,level1,path1,pathlen1);
							qu.push(snode);
						}
					}
				}
			}
		}
	}
}
void main()
{
	MGraph g;
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);	//����ڽӾ���g
	printf("���Ϊ0�Ľ�:\n");TSP(g);
	printf("���·�����䳤��:\n");
	disp(minpathlen,minpath);
}
