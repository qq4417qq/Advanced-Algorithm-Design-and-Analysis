#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 201
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
int n;								//�γ�����
struct NodeType
{	int a;							//�γ�i��ƽʱ�ɼ�
	int b;							//�γ�i����һ��Ҫ���ĸ�ϰʱ��
	bool operator<(const NodeType &s)
	{								//���ڰ���λ��ϰʱ���������
		return b<s.b;
	}
};
NodeType A[MAXN];
double avg;							//СvҪ�ﵽ��ƽ���ɼ�
int r;								//�γ�����
//�������ʾ
int effort=0;						//Сv��Ҫ�ĸ�ϰʱ��
void solve()						//��⽱ѧ������
{	int Sums=(int)n*avg;				//Сv�ﵽ�������ܷ�
	int sum=0;						//Сv�����пγ̵��ܷ�
	for (int i=0;i<n;i++)
		sum+=A[i].a;
	sort(A,A+n);					//����λ��ϰʱ���������
	for (int j=0;j<n;j++)
	{	if (sum>=Sums)				//�Ѿ��ﵽҪ��
			break;
		sum+=min(Sums-sum,r-A[j].a);			//�ۼƿγ�i�ﵽҪ��ķ���
		effort+=A[j].b*min(Sums-sum,r-A[j].a);	//�ۼƿγ�i�ﵽҪ��ĸ�ϰʱ��
	}
}
int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0;i<n;i++)
			scanf("%d%d",&A[i].a,&A[i].b);
		scanf("%d%lf",&r,&avg);
		solve();
		printf("%d\n",effort);
	}
   	return 0;
}
