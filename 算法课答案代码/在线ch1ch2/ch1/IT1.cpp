#include<iostream>
#include<string>
#include<vector>
using namespace std;
//求解问题表示
vector<string> vec;		//存储主数据
int n;					//输入的字符串个数
bool islexicalorder()		//判断vec是否按照字典序排序
{	int i=0;
    	while (i<vec.size()-1)
	{	if(vec[i].compare(vec[i+1])>0)
            return false;
        i++;
    }
    return true;
}
bool islengthorder()		//判断vec是否按照字符串大小排序
{	int i=0;
    	while(i<vec.size()-1)
	{	if(vec[i+1].size()<vec[i].size())
			return false;
        	i++;
    	}
    	return true;
}
int main()
{	string s;
    	bool flag1,flag2;
    	cin >> n;				//输入n
	for (int i=0;i<n;i++)
	{	cin >> s;			//输入一个字符串
        	vec.push_back(s);	//添加到vec字符串向量中
    	}
    	flag1=islexicalorder();
    	flag2=islengthorder();
	if(flag1 && flag2)
        cout << "both";
    else if(flag1)
        cout << "islexicalorder";
    else if(flag2)
        cout << "lengths";
    else
        cout << "none";
    return 0;
}
