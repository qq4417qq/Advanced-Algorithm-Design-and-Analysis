//��ٷ����TSP����
#include "Graph.cpp"
int minpath[MAXV];		//�������·��
int minpathlen=INF;		//�������·������
int count=0;
int getpathlen(MGraph g,int apath[])		//��apath�б����·����·������
{
	int i;
	int sum=g.edges[0][apath[0]];			//�����0����һ����ľ���
	for (i=1;i<g.n-1;i++)
		sum+=g.edges[apath[i-1]][apath[i]];
	sum+=g.edges[apath[i-1]][0];			//�ټ������һ���㵽0��ľ���
	return sum;
}
void Enumerate(MGraph g,int apath[],int i)	//������ٷ������·��
{
	int k,j,tmp;
	if (i==g.n-2)							//��apath�а��������м䶥��ʱ
	{
		if (g.edges[i][0]!=0 && g.edges[i][0]!=INF)	//�ҵ�һ����·
		{
			printf("  ·��%d: ",++count);
			printf("0��");
			for (k=0;k<g.n-1;k++)					//������·��
				printf("%d��",apath[k]);
			printf("%d",0);							//������
			printf(":\t%d\n",getpathlen(g,apath));
			if (minpathlen>getpathlen(g,apath))		//·�����ȱȽ�
			{
				minpathlen=getpathlen(g,apath);		//�������·������
				for (j=0;j<g.n-1;j++)				//�������·��
					minpath[j]=apath[j];
			}
		}
	}
	else										//��apath��û�а��������м䶥��ʱ
	{
		for (k=i;k<g.n-1;k++)					//�ҴӶ���i����������·��
		{
			tmp=apath[i];						//����apath[k]��apath[i]����
			apath[i]=apath[k];apath[k]=tmp;
			Enumerate(g,apath,i+1);
			tmp=apath[i];						//����apath[k]��apath[i]����
			apath[i]=apath[k];apath[k]=tmp;
		}
	}
}
void TSP(MGraph g)					//����ٷ����TSP����
{
	int i;
	int apath[MAXV];				//apath��Ŵ����0�����0�Ļ�·�е��м䶥��
	for (i=1;i<g.n;i++)				//������1��3����apath����Ϊ��ʼ·��
		apath[i-1]=i;
	minpathlen=getpathlen(g,apath);	//��ʼ��·���ĳ���
	Enumerate(g,apath,0);			//��·����ӡ�����Լ�·������
	printf("  ���·������=%d\n",minpathlen); 
	printf("  ���·��:");
	printf("0��");
	for (i=0;i<g.n-1;i++)				//������·��
		printf("%d��",minpath[i]);
	printf("%d\n",0);
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
}
