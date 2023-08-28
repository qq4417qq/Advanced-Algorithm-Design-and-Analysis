#include <iostream>
#include <string>
using namespace std;
#define MAXN 101
#define INF 0x3f3f3f3f							//��
#define min(x,y) ((x)<(y)?(x):(y))
int Minbrack(string str)							//��ʹstrƥ��������ӵ���С������
{	int dp[MAXN][MAXN];
	memset(dp,0,sizeof(dp));						//dp����Ԫ�س�ʼ��Ϊ0
	int n=str.size();
	for(int i=0; i<n; ++i)							//һ��������Ҫ���1��ƥ�������
		dp[i][i]=1;
	for(int len=1; len<n; ++len)						//���ǳ���Ϊlen��������
		for(int i=0; i<=n-len; ++i)					//����[i..j]��������
		{	int j=len+i;
			dp[i][j]=INF;						//��������Ϊ��
			if ((str[i]=='(' && str[j]==')') || (str[i]=='[' && str[j]==']')
			   || (str[i]=='{' && str[j]=='}') )			//�������(1)
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			else if (str[i]=='(' || str[i]=='[' || str[i]=='{')	//�������(2)
				dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
			else if (str[j]==')' || str[j]==']' || str[j]=='}') 	//�������(3)
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			for (int k=i;k<j;++k)					//�ϲ�
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	return dp[0][n-1];
}
void main()
{
	string str="(}(}";
	cout << "�����" << endl;
	cout << "    �ַ���: " << str << endl;
	cout << "    ���������������: " << Minbrack(str) << endl;
	str="({)}()]";
	cout << "    �ַ���: " << str << endl;
	cout << "    ���������������: " << Minbrack(str) << endl;
}
