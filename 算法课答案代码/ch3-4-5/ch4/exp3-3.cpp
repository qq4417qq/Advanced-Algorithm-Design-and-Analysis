#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
//�����ʾ
vector<vector<char> > board;			//������
int m;									//���m��
int n;									//���n��
struct Position							//λ�ýṹ��
{
    int x;
    int y;
    Position(int x1,int y1): x(x1), y(y1) {} //���캯��
};
void dispboard()						//������
{
	for(int i=0; i<m; i++)
	{
		printf("   ");
		for(int j=0; j<n;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
void BFS(int i,int j,int m,int n)		//������ȱ���
{
	queue<Position *> qu;
	Position *pos = new Position(i,j);
	qu.push(pos);						//��ʼλ�ý���
	board[i][j]='*';					//����λ�õ�ֵ��Ϊ'*',�����ظ�����
	while(!qu.empty())					//�Ӳ���ѭ��
	{
		Position *curp=qu.front();
		qu.pop();						//����λ��curp
		if (curp->x>0 && board[curp->x-1][curp->y]=='O')
		{
			Position *up=new Position(curp->x-1,curp->y);
			qu.push(up);
			board[up->x][up->y]='*';
		}
		if(curp->x<m-1 && board[curp->x+1][curp->y]=='O')
		{
			Position *down = new Position(curp->x+1,curp->y);
			qu.push(down);
			board[down->x][down->y]='*';
		}
		if(curp->y>0 && board[curp->x][curp->y-1]=='O')
		{
			Position *left = new Position(curp->x,curp->y-1);
			qu.push(left);
			board[left->x][left->y]='*';
		}
		if(curp->y<n-1 && board[curp->x][curp->y+1]=='O')
		{
			Position *right = new Position(curp->x,curp->y+1);
			qu.push(right);
			board[right->x][right->y]='*';
		}
		delete curp;					//�ͷ�curpָ��Ľ��
    }
}
void solve()						//��������㷨
{
	int i,j;
	for(i=0; i<m; i++)
		for(j=0; j<n;j++)
			if(board[i][j]=='O')
			{
				if(i==0 || i==m-1 || j==0 || j==n-1)
					BFS(i,j,m,n);
			}
	printf("BFS������:\n"); dispboard();
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
