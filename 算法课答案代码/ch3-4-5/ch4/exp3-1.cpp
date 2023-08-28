//�ݹ�汾
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int H[4] = {0, 1, 0, -1};			//ˮƽƫ����,�±��Ӧ��λ��0��3
int V[4] = {-1, 0, 1, 0};			//��ֱƫ����
//�����ʾ
vector<vector<char> > board;		//������
int m;								//���m��
int n;								//���n��
void dispboard()					//������
{
	int m=board.size();
	int n=board[0].size();
	for(int i=0; i<m; i++)
	{
		printf("   ");
		for(int j=0; j<n;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
void DFS(int i,int j)				//��'O'λ��������ȱ���
{
	int ni,nj;
	board[i][j]='*';				//����̽λ��ֵ��Ϊ'*',�����ظ�����
	for (int k=0;k<4;k++)			//��̽ÿһ����λ
	{
		ni=i+V[k]; nj=j+H[k];		//�����ڵ���λ��(ni,nj)
		if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]=='O')
		{	//��(ni��nj)λ����Ч����Ϊ'O'
			board[ni][nj]='*';		//����λ��ֵ��Ϊ'*'
			DFS(ni,nj);;			//����λ�ó�������'O'
		}
	}
}
void solve()						//��������㷨
{
	int i,j;
	if(board.empty() || board[0].empty())
		return;
	for(i=0; i<m; i++)
		for(j=0; j<n;j++)
			if(board[i][j]=='O')
			{
				if(i==0 || i==m-1 || j==0 || j==n-1)
					DFS(i,j);	//�ӱ߽��ϵ�'O'��������
			}
	printf("DFS������:\n"); dispboard();
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
		{
			if(board[i][j]=='O')		//��'O'��Ϊ'X'
				board[i][j]='X';
			else if(board[i][j]=='*')	//��'*'�ָ�Ϊ'O'
				board[i][j]='O';
        }
}
void main()
{
	string str[]={"XXXX","XOOX","XXOX","XOXX"};
	m=4; n=4;
	for (int i=0;i<m;i++)
	{
		vector<char> s;
		for (int j=0;j<n;j++)
			s.push_back(str[i][j]);
		board.push_back(s);
	}
	printf("ԭʼ���:\n"); dispboard();
	solve();
	printf("������:\n"); dispboard();
}
