#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define MAXN 10
#define MAXM 10
//�����ʾ
char map[MAXN][MAXM]={"...#..","......","#*##..","..##.#","..X...",".@#..."};
int n=6,m=6;
int H[4] = {0,1,0,-1};				//ˮƽƫ����,�±��Ӧ��λ��0��3
int V[4] = {-1,0,1,0};				//��ֱƫ����
int state[MAXN][MAXM][MAXN][MAXM];	//4ά�����ʾ�˺����ӵ�λ��״̬,��ʼȫΪ0

struct NodeType
{
    int px,py;		//�˵�λ��
	int bx,by;		//���ӵ�λ��
	int step;		//�ƶ�����
};
int personx,persony,boxx,boxy,endx,endy; //�ֱ��ʾ��ǰ�˵�λ�ã����ӵ�λ�ã��յ�λ��

bool Bound(int x,int y)	//���(x,y)λ���Ƿ�Ϸ�����Ч�ҿ�����
{
    if (x<0 || y<0 || x>=n || y>=m || map[x][y]=='#')
        return true;	//���Ϸ�����true
    else
        return false;	//�Ϸ�����false
}
int BFS()
{
	NodeType rnode,curnode,subnode;
    queue<NodeType> qu;			//״̬����
	rnode.px=personx;
	rnode.py=persony;
	rnode.bx=boxx;
	rnode.by=boxy;
	rnode.step=0;
	qu.push(rnode);
    state[personx][persony][boxx][boxy] = 1;//��ǰ��ʵ״̬λ���貽��Ϊ1

    while (!qu.empty())			//���в���ѭ��
    {
        curnode=qu.front();		//��ȡ��Ԫ��
        qu.pop();				//��Ԫ�ص���
        if (curnode.bx==endx && curnode.by==endy)
            return state[curnode.px][curnode.py][curnode.bx][curnode.by]-1;//����������յ㣬���������ز���
        for (int k=0; k<4; k++)//�ĸ�����ʼ������
        {
            //�ȸ����˵�λ��
            int px=curnode.px+H[k];
            int py=curnode.py+V[k];
            if (Bound(px,py))
                continue;//������λ�÷Ƿ���̽Ѱ��������
            if (px==curnode.bx && py==curnode.by)		//�����ʱ�˵�λ�������ӵ�λ���غϣ�˵����Ӧ���ƶ�������
            {
                if (Bound(curnode.bx + H[k], curnode.by + V[k]))
                    continue;//��������ƶ���λ�ò��Ϸ���������̽Ѱ��������
                state[px][py][curnode.bx + H[k]][curnode.by + V[k]] =
                    state[curnode.px][curnode.py][curnode.bx][curnode.by] + 1;//�����ƶ������˺�����λ�øı䣬��¼��״̬
				subnode.px=px;
				subnode.py=py;
				subnode.bx=curnode.bx+H[k];
				subnode.by=curnode.by+V[k];
                qu.push(subnode);//��״̬��ջ

            }
            else//��û���ƶ�����
            {
                if (state[px][py][curnode.bx][curnode.by])//����ƶ����״̬���ֹ��������������·���
                    continue;
                state[px][py][curnode.bx][curnode.by] = state[curnode.px][curnode.py][curnode.bx][curnode.by] + 1;
                //û���߹�����·����������
				subnode.px=px;
				subnode.py=py;
				subnode.bx=curnode.bx;
				subnode.by=curnode.by;
                qu.push(subnode);				//����״̬
            }
        }
    }
    return -1;//�������λ�ö��Թ��ˣ�û���ҵ���˵��������
}
int main()
{
	memset(state,0,sizeof(state));
    for (int i = 0; i < n; i++)		//��ʼ���ˣ����ӣ��յ��λ��
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j]=='*')		//����λ��
            {
                boxx = i;
                boxy = j;
            }
            else if (map[i][j] == 'X')	//�˵�λ��
            {
                personx = i;
                persony = j;
            }
            else if (map[i][j] == '@')	//Ŀ��λ��
            {
                endx = i;
                endy = j;
            }
        }
    }
    cout << BFS() << endl;
    return 0;
}
