#include<stdio.h>
#define MAXN 102
#define MAXM 102
//�����ʾ
int n;					//������
int m;					//��Ӧ����
int cost;				//�޶��۸�
int w[MAXN][MAXM];		//w[i][j]Ϊ��i������ڵ�j����Ӧ�̵�����
int c[MAXN][MAXM];		//c[i][j]Ϊ��i������ڵ�j����Ӧ�̵ļ۸�
//�������ʾ
int bestx[MAXN];
int x[MAXN];
int cw=0,cc=0;
int bestw=999999;
void dfs(int i)					//����㷨
{
    if(i>n)						//������Ҷ�ӽ��
    {
		if (cw<bestw)			//�Ƚϲ������Ž�
		{
			bestw=cw;			//��ǰ��С����
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
		}
    }
    else
    {
        for(int j=1;j<=m;j++)		//��̽ÿһ����Ӧ��
        {
            if(cc+c[i][j]<=cost && cw+w[i][j]<bestw)	//��֦
            {
                x[i]=j;					//��i������ѡ���j����Ӧ��
                cc+=c[i][j];
                cw+=w[i][j];
                dfs(i+1);
                cc-=c[i][j];			//cc����
                cw-=w[i][j];			//cw����
            }
        }
    }
}
int main()
{
    int i,j;
	scanf("%d%d%d",&n,&m,&cost);	//���벿����,��Ӧ����,�޶��۸�
    for(i=1; i<=n; i++)				//������������ڲ�ͬ��Ӧ�̵�����
        for(j=1; j<=m; j++)
            scanf("%d",&w[i][j]);
    for(i=1; i<=n; i++)				//������������ڲ�ͬ��Ӧ�̵ļ۸�
        for(j=1; j<=m; j++)
            scanf("%d",&c[i][j]);
    dfs(1);							//i��1��ʼ����
    for(i=1;i<=n;i++)				//���ÿ�������Ĺ�Ӧ��
        printf("%d ",bestx[i]);
	printf("\n%d\n",bestw);			//�����С����
    return 0;
}
