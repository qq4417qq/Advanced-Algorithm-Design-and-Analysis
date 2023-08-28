#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1001					//最多请求个数
//问题表示
int n=8;							//实际请求个数
int C=53;							//磁头初始位置
struct NodeType						//结点类型
{	int no;						//请求编号
	int place;						//柱面位置
};
NodeType A[MAX]={{1,98},{2,183},{3,37},{4,122},
				{5,14},{6,124},{7,65},{8,67}  };
//求解结果表示
int ans=0;							//存放总磁头移动数
bool flag[MAX];						//表示请求是否访问
bool cmp(NodeType a,NodeType b)		//排序比较函数
{   if (a.place<b.place) return true;
    return false;						//用于按柱面位置递增排序
}
void find(int i,int &minp,int &mind)	//查找最近没有访问的位置minp
{	int minleftp, minleftd=INF;
	int minrightp,minrightd=INF;
	int j=i-1,k=i+1;
	while (j>=0 && flag[j]==true)
		j--;						//向左边查找一个没有访问的位置j
	if (j>=0)						//查找成功
	{
		minleftp=j;
		minleftd=A[i].place-A[j].place;
	}
	while (k<=n && flag[k]==true)
		k++;						//向右查找一个没有访问的位置k
	if (k<=n)						//查找成功
	{
		minrightp=k;
		minrightd=A[k].place-A[i].place;
	}
	if (minleftd<minrightd)			//比较查找最近的没有访问的位置
	{	mind=minleftd;
		minp=minleftp;
	}
	else
	{	mind=minrightd;
		minp=minrightp;
	}
}
int solve()							//求解磁盘调度
{	sort(A,A+n+1,cmp);			//按柱面位置递增排序
	for (int i=0; i<=n; i++)				//查找磁头开始位置i
		if (A[i].place==C)
			break;
	flag[i]=true;
	printf("   当前位置%d[请求编号:%d]\n",A[i].place,A[i].no);
	for (int k=0; k<n; k++)				//执行n次
	{	int minp,mind;
		find(i,minp,mind);
		printf("   移动到位置%d[请求编号:%d],移动距离:%d\n",
				A[minp].place,A[minp].no,mind);
		flag[minp]=true;				//访问minp请求
		ans+=mind;				//累计磁头移动数
		i=minp;					//从minp开始继续访问
	}
	return ans;
}  
int main()
{	A[n].no=0;  A[n].place=C;			//加入磁头初始位置
	printf("求解结果\n");
	memset(flag,0,sizeof(flag));		//初始化flag
	printf("SSTF算法磁头移动总数: %d\n",solve());
	return 0;
}
