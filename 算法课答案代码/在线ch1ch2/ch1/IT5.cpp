#include <iostream>
#include <string>
using namespace std;
//�����ʾ
int n;
string s,t;
bool solve(string s,string t)	//�ж�s��t�Ƿ�Ϊ���δ�
{
	string ss=s+s;
	if (ss.find(t,0)!=-1)	//��ss���ҵ��Ӵ�t
		return true;
	else
		return false;
}
int main()
{
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> s >> t;
		if (solve(s,t))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}