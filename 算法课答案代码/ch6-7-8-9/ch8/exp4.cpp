#include <vector>
#include <iostream>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
//问题表示
int n;
vector<int> length;
void solve()					//求解双核处理问题
{	int i,j;
	int sum=0;					//求所有任务长度和
	for(i=0; i<n; i++)
	{	length[i]=length[i] >> 10;	//改为以KB为单位
		sum=sum+length[i];
	}
	vector<int> dp(sum/2+1,0);	//动态规划数组,所有元素初始化为0
	for(i=0; i<n; i++)
	{	for(j=sum/2; j>=length[i]; j--)
			dp[j]=max(dp[j], dp[j-length[i]]+length[i]);
	}
	int ans=max(dp[sum/2],sum-dp[sum/2]);
	cout<< (ans << 10) << endl; 
}
int main()
{	int h;
	while(cin>>n)				//输入n
	{	length.clear();
		for(int i=0; i<n; i++)		//输入height
		{	cin >> h;
			length.push_back(h);
		}
		solve();
	}
	return 0;
}
