#include <stdio.h>
#define MAXN 51
int s[MAXN][MAXN];					//�����������
int n;								//�����������Ĵ�С
void Spiral(int x,int y,int start,int n)	//�ݹ鴴����������
{	int  i, j;
	if (n<=0)						//�ݹ��������
		return;
	if (n==1)						//�����СΪ1ʱ
	{	s[x][y] = start;
		return;
	}
	for (i= x; i<x+n-1; i++)			//��һ��
		s[y][i]=start++;
	for (j=y; j<y+n-1; j++)				//��һ��
		s[j][x+n-1]= start++;
	for (i=x+n-1; i>x; i--)				//��һ��
		s[y+n-1][i]= start++;
	for (j=y+n-1; j>y; j--)				//��һ��
		s[j][x]=start++;
	Spiral(x+1,y+1,start,n-2);			//�ݹ����
}
void dispmatrix()			//�����������		
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
}

int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0) break;
		Spiral(0,0,1,n);
		dispmatrix();
	}
	return 0;
}

