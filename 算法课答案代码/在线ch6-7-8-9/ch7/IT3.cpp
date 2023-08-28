#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 10010
//问题表示
int t,n;
struct NodeType
{
    int l;
    int w;
    friend bool operator < (NodeType a, NodeType b)
	{
        if (a.l!=b.l)			//长度不相同按长度递增排序
            return a.l < b.l;
        return a.w<b.w;			//长度相同按重量递增排列
    }
} s[MAXN];
//求解结果表示
int ans;						//最少时间
bool flag[MAXN];				//兼容活动标志
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
			int preend=j;			//前一个兼容活动的下标
			for (int i=preend+1;i<=n;i++)
			{
				if (s[i].w>=s[preend].w && !flag[i])
				{
					preend=i;
					flag[i]=true;
				}
			}
			ans++;					//增加一个最大兼容活动子集
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
