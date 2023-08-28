#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1001					//����������
//�����ʾ
int n=8;							//ʵ���������
int C=53;							//��ͷ��ʼλ��
struct NodeType						//�������
{	int no;						//������
	int place;						//����λ��
};
NodeType A[MAX]={{1,98},{2,183},{3,37},{4,122},
				{5,14},{6,124},{7,65},{8,67}  };
//�������ʾ
int ans=0;							//����ܴ�ͷ�ƶ���
bool flag[MAX];						//��ʾ�����Ƿ����
bool cmp(NodeType a,NodeType b)		//����ȽϺ���
{   if (a.place<b.place) return true;
    return false;						//���ڰ�����λ�õ�������
}
void find(int i,int &minp,int &mind)	//�������û�з��ʵ�λ��minp
{	int minleftp, minleftd=INF;
	int minrightp,minrightd=INF;
	int j=i-1,k=i+1;
	while (j>=0 && flag[j]==true)
		j--;						//����߲���һ��û�з��ʵ�λ��j
	if (j>=0)						//���ҳɹ�
	{
		minleftp=j;
		minleftd=A[i].place-A[j].place;
	}
	while (k<=n && flag[k]==true)
		k++;						//���Ҳ���һ��û�з��ʵ�λ��k
	if (k<=n)						//���ҳɹ�
	{
		minrightp=k;
		minrightd=A[k].place-A[i].place;
	}
	if (minleftd<minrightd)			//�Ƚϲ��������û�з��ʵ�λ��
	{	mind=minleftd;
		minp=minleftp;
	}
	else
	{	mind=minrightd;
		minp=minrightp;
	}
}
int solve()							//�����̵���
{	sort(A,A+n+1,cmp);			//������λ�õ�������
	for (int i=0; i<=n; i++)				//���Ҵ�ͷ��ʼλ��i
		if (A[i].place==C)
			break;
	flag[i]=true;
	printf("   ��ǰλ��%d[������:%d]\n",A[i].place,A[i].no);
	for (int k=0; k<n; k++)				//ִ��n��
	{	int minp,mind;
		find(i,minp,mind);
		printf("   �ƶ���λ��%d[������:%d],�ƶ�����:%d\n",
				A[minp].place,A[minp].no,mind);
		flag[minp]=true;				//����minp����
		ans+=mind;				//�ۼƴ�ͷ�ƶ���
		i=minp;					//��minp��ʼ��������
	}
	return ans;
}  
int main()
{	A[n].no=0;  A[n].place=C;			//�����ͷ��ʼλ��
	printf("�����\n");
	memset(flag,0,sizeof(flag));		//��ʼ��flag
	printf("SSTF�㷨��ͷ�ƶ�����: %d\n",solve());
	return 0;
}
