#include <stdio.h>
#include <string.h>
#define MAXN 1005
//�����ʾ
int n;
int a[MAXN];
//�������ʾ
int ans;				//���Բ��������˵Ĵ�����
//�����̱�ʾ
int times[MAXN];		//times[i]��ʾԪ��t���ֵĴ���
int m;					//times������Ԫ�ظ���(��ͬ������ĸ���)
void init()
{
	int t;
	m=0;
	memset(times,0,sizeof(times));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(times[t]==0)
            a[++m]=t;
        times[t]++;
    }
}
void dfs(int i,int sum,int mult)	//�����������
{
    if (i>m) return;
    dfs(i+1,sum,mult);				//��ѡ��a[i]�������
    for(int j=1;j<=times[a[i]];j++)	//ѡ��a[i]�������ѡ��j��
    {
        sum+=a[i];
        mult*=a[i];
        if(i!=1 && mult>=sum) break;
        if(sum>mult) ans++;			//�ҵ�һ����
        dfs(i+1,sum,mult);
    }
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		init();
		ans=0;
		dfs(1,0,1);
		printf("%d\n",ans);
	}
	return 0;
}

