//穷举法求解TSP问题
#include "Graph.cpp"
int minpath[MAXV];		//保存最短路径
int minpathlen=INF;		//保存最短路径长度
int count=0;
int getpathlen(MGraph g,int apath[])		//求apath中保存的路径的路径长度
{
	int i;
	int sum=g.edges[0][apath[0]];			//先求从0到第一个点的距离
	for (i=1;i<g.n-1;i++)
		sum+=g.edges[apath[i-1]][apath[i]];
	sum+=g.edges[apath[i-1]][0];			//再加上最后一个点到0点的距离
	return sum;
}
void Enumerate(MGraph g,int apath[],int i)	//利用穷举法求最短路径
{
	int k,j,tmp;
	if (i==g.n-2)							//当apath中包含所有中间顶点时
	{
		if (g.edges[i][0]!=0 && g.edges[i][0]!=INF)	//找到一条回路
		{
			printf("  路径%d: ",++count);
			printf("0→");
			for (k=0;k<g.n-1;k++)					//输出最短路径
				printf("%d→",apath[k]);
			printf("%d",0);							//输出起点
			printf(":\t%d\n",getpathlen(g,apath));
			if (minpathlen>getpathlen(g,apath))		//路径长度比较
			{
				minpathlen=getpathlen(g,apath);		//保存最短路径长度
				for (j=0;j<g.n-1;j++)				//保存最短路径
					minpath[j]=apath[j];
			}
		}
	}
	else										//当apath中没有包含所有中间顶点时
	{
		for (k=i;k<g.n-1;k++)					//找从顶点i出发的所有路径
		{
			tmp=apath[i];						//顶点apath[k]与apath[i]交换
			apath[i]=apath[k];apath[k]=tmp;
			Enumerate(g,apath,i+1);
			tmp=apath[i];						//顶点apath[k]与apath[i]交换
			apath[i]=apath[k];apath[k]=tmp;
		}
	}
}
void TSP(MGraph g)					//用穷举法求解TSP问题
{
	int i;
	int apath[MAXV];				//apath存放从起点0到起点0的回路中的中间顶点
	for (i=1;i<g.n;i++)				//将顶点1～3放入apath中作为初始路径
		apath[i-1]=i;
	minpathlen=getpathlen(g,apath);	//初始化路径的长度
	Enumerate(g,apath,0);			//把路径打印出来以及路径长度
	printf("  最短路径长度=%d\n",minpathlen); 
	printf("  最短路径:");
	printf("0→");
	for (i=0;i<g.n-1;i++)				//输出最短路径
		printf("%d→",minpath[i]);
	printf("%d\n",0);
}
void main()
{
	MGraph g;
	int A[][MAXV]={						//一个带权有向图
		{0,8,5,36},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//创建图的邻接矩阵存储结构g
	printf("邻接矩阵:\n"); DispMat(g);	//输出邻接矩阵g
	printf("起点为0的解:\n");TSP(g);
}
