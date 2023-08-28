#include <iostream>
#include <queue>
#include <map>
const long MOD = 1000000007L;
using namespace std;
int bfs(long x0)
{	if (x0<1 || x0 >1000000006L)
		return -1;
	x0 %= MOD;
	queue<long> qu;							//定义一个队列
	map<long, int> mymap;					//存放x模值的移动次数
	qu.push(x0);							//x0进队
	mymap[x0] = 0;							//开始时x+0对应的移动次数为0
	while(!qu.empty())						//队不空循环
	{	long e=qu.front();					//出队元素e
		qu.pop();
		if (0==e)							//找到贝壳，返回次数
			return mymap[e];
		if(mymap[e]<=100000)				//移动次数小于等于100000
		{	long x1=(4*e+3) % MOD;			//x一次移动
			if(mymap.find(x1)==mymap.end())	//mymap中没有找到
			{	mymap[x1]=mymap[e]+1;		//次数增加1
				qu.push(x1);				//移动结果进队
			}
			long x2=(8*e+7) % MOD;			//x一次运算
			if(mymap.find(x2)==mymap.end())	//mymap中没有找到
			{	mymap[x2]=mymap[e]+1;		//次数增加1
				qu.push(x2);				//移动结果进队
			}
		}
    }
    return -1;
}
int main()
{
	long x0;
   	while(cin >> x0)
       	cout << bfs(x0) << endl;
	return 0;
}