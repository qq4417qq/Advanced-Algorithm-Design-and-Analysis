#include <stdio.h>
#include <vector>
using namespace std;
//�����ʾ
int n=5,r=3;							//ȫ�ֱ���
void disppath(vector<int> path)			//���һ�����
{	for (int j=0;j<path.size();j++)
		printf("  %d",path[j]);
	printf("\n");
}
void dfs(vector<int> path,int i,int num)	//����㷨
{
	if (num==r)
		disppath(path);
	for (int j=i;j<=n;j++)
	{
		path.push_back(j);			//ѡ��Ԫ��i
		dfs(path,j+1,num+1);		
		path.pop_back();			//����:��ѡ��Ԫ��i
	}
}
void main()
{
	vector<int> path;				//���һ����
	printf("n=%d,r=%d�������������:\n",n,r);
	dfs(path,1,0);
}
