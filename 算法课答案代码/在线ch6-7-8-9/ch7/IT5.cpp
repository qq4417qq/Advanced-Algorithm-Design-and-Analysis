#include<iostream>
#include<algorithm>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 101
//�����ʾ
struct Action
{	int no;							//��ҵ���
	int deadline;						//����ύ��ʱ��
	int score;						//���ڵĿ۷�
    	bool operator < (const Action t) const
    	{	if (score==t.score)			//�۷���ͬ���ύʱ���������
			return deadline<t.deadline;
		else
			return score>t.score;		//�����ڿ۷ֵݼ�����
    }
};
int n;
Action A[MAX];
//�������ʾ
bool flag[MAX];						//��ʱ���־
int bests=0;							//���ٵĿ۷�
void solve()							//������ҵ����
{	int i,j;							//�ۼ�������ҵ��ʱ��
	for (i=0;i<n;i++)
	{	for (j=A[i].deadline;j>0;j--)	//�ڵ�ǰ��ҵ����ύʱ��֮ǰ�ҿ�ʱ��
		{	if (flag[j]==false)		//�ҵ��˿�ʱ��
			{	printf("%d ",A[i].no);	//ѡ������ҵA[i].no
				flag[j]=true;
				break;
			}
		}
		if (j==0)						//��ǰ��ҵ����ύʱ��֮ǰ�Ҳ�����ʱ��
			bests+=A[i].score;			//��ѡ������ҵA[i].no
	}
}
int main()
{	int i;
	while(true)
	{	scanf("%d",&n);
		if (n==0) break;
		for (i=0;i<n;i++)				//������ҵ������ύʱ�� 
		{	A[i].no=i+1;
			scanf("%d",&A[i].deadline);
		}
		for (i=0;i<n;i++)				//������ҵ�����ڿ۷� 
			scanf("%d",&A[i].score);
		solve();
		printf("\n%d\n",bests);			//������ٿ۷�
	}
	return 0;
}

