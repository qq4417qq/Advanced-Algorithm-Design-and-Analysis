//采用回溯法递归框架求解迷宫问题的算法
#include <stdio.h>
#define M 6
#define N 6
#define MaxSize 20					//迷宫路径中的最多方块数
typedef struct
{	int i;							//当前方块的行号
	int j;							//当前方块的列号
} Box;								//声明一个方块的类型
typedef struct
{	Box data[MaxSize];
	int length;						//路径长度
} PathType;							//声明一条路径的类型
void dispapath(PathType path)		//输出一条迷宫路径
{	static int count=0;				//静态变量用于统计迷宫路径总数
	int k;
	printf("第%d条迷宫路径:\n",++count);
	for (k=0;k<path.length;k++)
		printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
	printf("\n");
}
void mgpath(int mg[M][N],int xi,int yi,int xe,int ye,PathType path)
//求(xi,yi)->(xe,ye)的所有迷宫路径
{	int di,i,j;
	if (xi==xe && yi==ye)			//找到了出口,输出路径
	{	path.data[path.length].i=xi;//将出口放入路径中
		path.data[path.length].j=yi;
		path.length++;
		dispapath(path);			//输出一条路径
	}
	else							//(xi,yi)不是出口
	{	if (mg[xi][yi]==0)			//若(xi,yi)是一个可走方块
		{	di=0;
			while (di<4)			//找(xi,yi)的四周的相邻方块(i,j)
			{	path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;		//路径长度增1
				switch(di)			//找一个相邻方块(i,j)
				{
				case 0:i=xi-1; j=yi;   break;
				case 1:i=xi;   j=yi+1; break;
				case 2:i=xi+1; j=yi;   break;
				case 3:i=xi;   j=yi-1; break;
				}
				mg[xi][yi]=-1;		//避免重复找路径
				mgpath(mg,i,j,xe,ye,path);
				mg[xi][yi]=0;		//恢复(xi,yi)为可走的
				path.length--;		//回退一个方块，路径长度减1
				di++;				//找(xi,yi)的下一个方位的相邻方块
			}
		}
	}
}
void main()
{	PathType path;
	int mg[M][N]={ {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
			 {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1} };
	path.length=0;					//迷宫路径长度初始化
	mgpath(mg,1,1,4,4,path);		//求入口(1,1)到出口(4,4)的所有迷宫路径
}
