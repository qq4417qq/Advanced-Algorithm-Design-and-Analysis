#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//�����ʾ
int n=4;							//�ʺ����
//�������ʾ
int Count=1;						//�ۼƶ����еĽ�����,ȫ�ֱ���
struct NodeType						//���������еĽ������
{
	int no;							//�����
	int row;						//��ǰ������к�
	vector<int> cols;				//����Ѿ����ûʺ���к� 
};
void dispnode(NodeType e)			//���һ���������
{
	if (e.row!=-1)
		printf("���:%d, ��Ӧλ��(%d,%d)\n",e.no,e.row,e.cols[e.row]);
	else
		printf("���:%d, ��Ӧλ��(%d,*)\n",e.no,e.row);
}
bool Valid(vector<int> cols,int i,int j)  	//����(i,j)λ���ܷ�ڷŻʺ�
{	int k=0;
	while (k<i)       				//k=0��i-1���ѷ����˻ʺ�
	{	if ((cols[k]==j) || (abs(cols[k]-j)==abs(k-i)))
		    return false;				//�г�ͻʱ���ؼ�
	    k++;
	}
	return true;						//û�г�ͻʱ������
}
void solve()						//��ʺ������
{	int i,j;
	NodeType e,e1;					//����2�����
	queue<NodeType> qu;				//����һ������qu
	e.no=Count++;					//���������
	e.row=-1;						//�кų�ʼ��Ϊ-1
	qu.push(e);						//��������
	printf("  ����: "); dispnode(e);
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e=qu.front(); qu.pop();		//���ӽ��e��Ϊ��ǰ���
		printf("  ����: "); dispnode(e);
		if (e.row==n-1)				//�ﵽҶ���
		{
			printf("  ����һ����: ");
			for (i=0;i<n;i++)			//�С��кŴ�1��ʼ
				printf("[%d,%d] ",i+1,e.cols[i]+1);
			printf("\n");
			return;
		}
		else						//e����Ҷ���
		{	for (j=0; j<n; j++)		//��������к�
			{	i=e.row+1;			//�����i���ʺ�
				if (Valid(e.cols,i,j))	//��չ��e��������лʺ�û�г�ͻ���ӽ��
				{
					e1.no=Count++;
					e1.row=i;
					e1.cols=e.cols;
					e1.cols.push_back(j);
					qu.push(e1);
					printf("     �����ӽ��: "); dispnode(e1);
				}
			}
		}
	}
}
int main()
{	printf("%d�ʺ�����������:\n",n);
	solve();
	return 0;
}
