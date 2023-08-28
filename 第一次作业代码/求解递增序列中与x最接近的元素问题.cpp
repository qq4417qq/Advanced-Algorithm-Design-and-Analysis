#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; ++i){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	for (int i = 0; i < m; ++i){
		int temp;
		cin>>temp;
		vector<int>::iterator it1 = lower_bound(a.begin(),a.end(),temp);
		vector<int>::iterator it2 = upper_bound(a.begin(),a.end(),temp);
		if(*it1<*it2) b.push_back(*it1);
		else b.push_back(*(it1-1));
	}
		vector<int>::iterator it;
		for (it = b.begin(); it!= b.end(); ++it)
		{
			cout<<*it<<endl;//遍历得到的数组
		}
		system("pause");
		return 0;
	}
	