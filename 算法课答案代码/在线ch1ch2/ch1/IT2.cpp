#include <iostream>
#include <string>
#include <map>
using namespace std;
void Delete(string stra,string strb)					//从stra中删除strb中的字符
{
	map<char,int> mymap;
	for (int i=0;i<strb.length();i++)
		mymap[strb[i]]++;
	for (int j=0;j<stra.length();j++)
		if (mymap[stra[j]]==0)
			cout << stra[j];
}
int main()
{
	string stra;
	string strb;
	while(getline(cin,stra))
	{
        getline(cin,strb);
        Delete(stra,strb);
		cout << endl;
    }
	return 0;
}
