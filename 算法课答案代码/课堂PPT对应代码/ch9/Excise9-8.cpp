//��ϰ��8
#include<stdio.h>
#include<memory.h>
#define MAX 31
int a[][2]={0,1,1,0,0,-1,-1,0};			//�ҡ��¡������ĸ���λ
int n,biao,d;
char b[MAX][MAX];
int v[MAX][MAX];
void DFS(int x,int y)
{	if(biao==1)
		return ;
	int i,xx,yy;
	for (i=0;i<4;i++)					//��(x,y)���ĸ���λ(xx,yy)
	{	xx=x+a[i][0];
		yy=y+a[i][1];
		if (xx>=0 && xx<=n && yy>=0 && yy<=n && v[xx][yy]!=-1)
		{	if (b[xx][yy]=='a')			//����Amaze,����
			{	biao=1;
				break;
			}
			else if (b[xx][yy]=='r')	//������·
			{	if(d==0)
				{	v[xx][yy]=-1;		//��(xx,yy)λ��Ԫ����Ϊ-1,�����ظ�����
					DFS(xx,yy);
				}
				else if (d==1 && v[xx][yy]==0)
				{	v[xx][yy]=1;		//Ԫ��ֵ��Ϊ1ʱ��ʾ���ʹ���λ��
					DFS(xx,yy);			//��(xx,yy)������������
				}
			}
			else if (b[xx][yy]=='d')	//����Ұ��
			{	if (d==0)
				{	v[xx][yy]=-1;		//��(xx,yy)λ��Ԫ����Ϊ-1,�����ظ�����
					d++;				//����Ұ���Ĵ�����1
					DFS(xx,yy);			//��(xx,yy)������������
					d--;				//����
				}
			}
		}
	}
}
int main()
{	int t,i,j,x,y;
	scanf("%d",&t);					//����t
	while (t--)
	{	biao=0;
		d=0;
		memset(v,0,sizeof(v));		//��v������Ԫ��ΪASCIIΪ0�ַ�
		scanf("%d",&n);				//����n
		for(i=0;i<n;i++)			//����һ����������
			scanf("%s",b[i]);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{	if(b[i][j]=='p')	//�ҵ�Magicpig��λ��(x,y)
				{	x=i;
					y=j;
				}
			if(b[i][j]=='k')		//�����λ�õ�Ԫ����Ϊ-1
				v[i][j]=-1;
			}
		v[x][y]=-1;					//��Magicpig��λ��(x,y)��Ԫ��ֵΪ-1,�����ظ�����
		DFS(x,y);					//��(x,y)��ʼ����
		if(biao==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
