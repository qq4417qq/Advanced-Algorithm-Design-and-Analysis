#include<stdio.h>
#include<queue>
using namespace std;
#define MAXN 10
#define MAXM 10
int H[4] = {0,1,0,-1};					//水平偏移量,下标对应方位号0～3
int V[4] = {-1,0,1,0};					//垂直偏移量
//问题表示
char map[MAXN][MAXM]={"...#..","......","#*##..","..##.#","..X...",".@#..."};
int N=6,M=6;  
int terminal_x, terminal_y ;  
  
bool flag[10][10][10][10] ;  
int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0} ;  
  
typedef struct Node  
{  
    int x1, y1 ;  
    int x2, y2 ;  
    int step ;  
    Node()
		: x1(0), y1(0), x2(0), y2(0), step(0) {}  
}NODE ;  
  
NODE now ;  
queue <NODE> que ;  
  
bool bounds(int x,int y)  
{  
    if(x < 0 || y < 0 || x >= N || y >= M || map[x][y]=='#')  
        return true ;  
    return false ;  
}  
  
int bfs()  
{  
    NODE Temp ;  
    NODE NOW ;  
    while(!que.empty())  
    {  
        Temp = que.front() ;  
        que.pop() ;  
          
        for(int i = 0; i < 4; i ++)  
        {  
            int x = Temp.x1 + direction[i][0] ;   
            int y = Temp.y1 + direction[i][1] ;  
            if(bounds(x, y)) continue ;  
              
            if(x == Temp.x2 && y == Temp.y2) //找到'*'
            {  
                if(!bounds(x + direction[i][0], y + direction[i][1])   
                    && flag[x][y][x + direction[i][0]][y + direction[i][1]])  
                {  
                    flag[x][y][x + direction[i][0]][y + direction[i][1]] = false ;  
                    NOW.x1 = x ;  
                    NOW.y1 = y ;  
                    NOW.x2 = x + direction[i][0] ;  
                    NOW.y2 = y + direction[i][1] ;  
                    NOW.step = Temp.step + 1 ;  
                    que.push(NOW) ;  
                }  
            }  
            else  
            {  
                if(flag[x][y][Temp.x2][Temp.y2])  
                {  
                    flag[x][y][Temp.x2][Temp.y2] = false ;  
                    NOW.x1 = x ;  
                    NOW.y1 = y ;  
                    NOW.x2 = Temp.x2 ;  
                    NOW.y2 = Temp.y2 ;  
                    NOW.step = Temp.step + 1 ;  
                    que.push(NOW) ;  
                }  
            }  
              
            if(NOW.x2 == terminal_x&& NOW.y2 == terminal_y)  
                return NOW.step ;  
        }  
    }  
    return -1 ;  
}  
  
int main()  
{
	memset(flag, true, sizeof(flag));
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			if(map[i][j] == 'X')
			{
				now.x1 = i;
				now.y1 = j;
			}
			else if(map[i][j] == '*')
			{
				now.x2 = i;
				now.y2 = j ;
			}
			else if(map[i][j] == '@')
			{
				terminal_x = i ;
				terminal_y = j ;
			}
        }
	}
	flag[now.x1][now.y1][now.x2][now.y2]=false ;  
    que.push(now);  
    printf("%d\n",bfs()); 
    return 0 ;  
}

