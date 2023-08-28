#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> nums;
	int n;
	int shu = 1;//初始化
	cin>>n;
	vector<int> dp(n,1);//[1.....1]
	for (int i = 0; i < n; i++)
	{
		int num;
		cin>>num;
		nums.push_back(num);//输入nums数据
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(nums[j]>nums[i]){
				dp[i] = max(dp[j]+1,dp[i]);//寻找最长下降子序列
			}
		}
		shu = max(shu,dp[i]);	
	}
	cout<<shu;	
	system("pause");
	return 0;
}