#include <iostream>
#include <string.h>
#include <functional>
#include <algorithm>
using namespace std;
#define MAX 201
//�����ʾ
int n,m;
int a[MAX];
//�������ʾ
int ans;
void solve()
{
	int d[MAX];
	sort(a,a+n,greater<int>());		//�Ӵ�С��������
	for(int i=0; i<n-1;i++)			//����������
		d[i]=a[i]-a[i+1]-1;
	sort(d,d+n-1,greater<int>());	//�Ӵ�С������
	if (m>n)						//���m>n,ֱ�����n
		ans=n;
	else
	{
		int num=1;					//�ۼ��߶���
		ans=a[0]-a[n-1]+1;			//��ʼ�߶��ܳ�
		int j=0;
		while(num<m && d[j]>0)
		{
			num++;
			ans=ans-d[j];			//��ȥ���
			j++;
		}
	}
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
		solve();
		printf("%d\n", ans);
	}
    return 0;
}

