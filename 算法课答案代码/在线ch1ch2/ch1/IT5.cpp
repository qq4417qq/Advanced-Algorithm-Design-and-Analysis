#include <iostream>
#include <string>
using namespace std;
//问题表示
int n;
string s,t;
bool solve(string s,string t)	//判断s和t是否为变形词
{
	string ss=s+s;
	if (ss.find(t,0)!=-1)	//在ss中找到子串t
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