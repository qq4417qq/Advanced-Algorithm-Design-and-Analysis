#include <stdio.h>
#include <string.h>
#define MAXN 51
#define MAXE 301
//�����ʾ
int n,m;					//n�����㣬m����
int a[MAXN][MAXN];
//�������ʾ
int x[MAXN];				//��ǰ��  
int cn;						//��ǰ��Ķ�����  
int bestn;					//����ŵĶ�����  
void dfs(int i)				//�������
{
	if (i>n)				//����Ҷ���
	{
		if (cn>bestn)
			bestn = cn;  
        return;  
    }
    bool complete=true;			//��鶥��i�뵱ǰ�ŵ�������ϵ
    for (int j=1; j<i; j++)
		if (x[j] && a[i][j] == 0)
		{  
			complete=false;		//����i�붥��j������
			break;  
		}  
    if (complete)				//ȫ����������������  
    {
		x[i]=1;					//ѡ�ж���i  
        cn++;
		dfs(i+1);  
        x[i]=0;					//����  
        cn--;  
    }
	if (cn+n-i >= bestn)		//��֦����������
	{
		x[i] = 0;				//��ѡ�ж���i
        dfs(i+1);  
    }  
}  
int main()  
{
	int s,t;
	while (true)
	{
		bestn=0;
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) break;
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&s,&t);
			a[s][t]=1;
			a[t][s]=1;
		}
		dfs(1);
		printf("%d\n",bestn);
	}
	return 0;
}
