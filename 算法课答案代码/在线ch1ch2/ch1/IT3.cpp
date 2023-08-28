#include <iostream>
#include <string>
using namespace std;
//问题表示
int n;
string str;
void swap(char &x,char &y)			//交换x和y
{	char tmp=x;
	x=y; y=tmp;
}
int Move(string &s)					//移动字符串s中的'*'字符
{
	int i=s.length(),j=s.length()-1;
	while (j>=0)					//j扫描所有元素
	{
		if (s[j]!='*')				//找到不为'*'的元素s[j]
		{
			i--;					//扩大不为*的区间
			if (i!=j)
				swap(s[i],s[j]);	//将s[j]交换到不为'*'区间的前面
		}
		j--;						//继续扫描
	}
	return i;
}
int main()
{
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> str;
		int j=Move(str);
		cout << str << endl;
		cout << j << endl;
	}
	return 0;
}
