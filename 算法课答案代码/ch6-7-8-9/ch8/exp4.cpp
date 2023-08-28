#include <vector>
#include <iostream>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n;
vector<int> length;
void solve()					//���˫�˴�������
{	int i,j;
	int sum=0;					//���������񳤶Ⱥ�
	for(i=0; i<n; i++)
	{	length[i]=length[i] >> 10;	//��Ϊ��KBΪ��λ
		sum=sum+length[i];
	}
	vector<int> dp(sum/2+1,0);	//��̬�滮����,����Ԫ�س�ʼ��Ϊ0
	for(i=0; i<n; i++)
	{	for(j=sum/2; j>=length[i]; j--)
			dp[j]=max(dp[j], dp[j-length[i]]+length[i]);
	}
	int ans=max(dp[sum/2],sum-dp[sum/2]);
	cout<< (ans << 10) << endl; 
}
int main()
{	int h;
	while(cin>>n)				//����n
	{	length.clear();
		for(int i=0; i<n; i++)		//����height
		{	cin >> h;
			length.push_back(h);
		}
		solve();
	}
	return 0;
}
