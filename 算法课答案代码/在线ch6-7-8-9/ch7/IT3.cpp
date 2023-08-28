#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 10010
//�����ʾ
int t,n;
struct NodeType
{
    int l;
    int w;
    friend bool operator < (NodeType a, NodeType b)
	{
        if (a.l!=b.l)			//���Ȳ���ͬ�����ȵ�������
            return a.l < b.l;
        return a.w<b.w;			//������ͬ��������������
    }
} s[MAXN];
//�������ʾ
int ans;						//����ʱ��
bool flag[MAXN];				//���ݻ��־
void solve()
{
	sort(s+1,s+n+1);
	memset(flag,0,sizeof(flag));
	ans=0;
	for (int j=1;j<=n;j++)
	{
		if (!flag[j])
		{
			flag[j]=true;
			int preend=j;			//ǰһ�����ݻ���±�
			for (int i=preend+1;i<=n;i++)
			{
				if (s[i].w>=s[preend].w && !flag[i])
				{
					preend=i;
					flag[i]=true;
				}
			}
			ans++;					//����һ�������ݻ�Ӽ�
		}
	}
}
int main()
{
    cin >> t;
    while (t--)
	{
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> s[i].l >> s[i].w;
		solve();
		cout << ans << endl;
    }
    return 0;
}
