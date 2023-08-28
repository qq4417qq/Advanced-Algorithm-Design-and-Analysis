//�ǵݹ�汾
#include <stdio.h>
#include <vector>
#include <stack>
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
void dispboard()		//������
{
	for(int i=0; i<m; i++)
	{
		printf("   ");
		for(int j=0; j<n;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
void DFS(int i,int j,int m,int n)
{
	stack<Position *> st;
	Position *pos = new Position(i,j);
	st.push(pos);						//��ʼλ�ý�ջ
	board[i][j]='*';					//��ջλ�õ�ֵ��Ϊ'*',�����ظ�����
	while(!st.empty())					//ջ����ѭ��
	{
		Position *curp=st.top();		//ȡջ��λ�÷���curp
		if (curp->x>0 && board[curp->x-1][curp->y]=='O')
		{
			Position *up=new Position(curp->x-1,curp->y);
			st.push(up);
			board[up->x][up->y]='*';
			continue;
		}
		if(curp->x<m-1 && board[curp->x+1][curp->y]=='O')
		{
			Position *down = new Position(curp->x+1,curp->y);
			st.push(down);
			board[down->x][down->y]='*';
			continue;
		}
		if(curp->y>0 && board[curp->x][curp->y-1]=='O')
		{
			Position *left = new Position(curp->x,curp->y-1);
			st.push(left);
			board[left->x][left->y]='*';
			continue;
		}
		if(curp->y<n-1 && board[curp->x][curp->y+1]=='O')
		{
			Position *right = new Position(curp->x,curp->y+1);
			st.push(right);
			board[right->x][right->y]='*';
			continue;
		}
		delete curp;			//�ͷ���ջ�Ľ��
		st.pop();				//ջ������û��·��ʱ��ջ
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
					DFS(i,j,m,n);
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
