#include <iostream>
#include <queue>
#include <map>
const long MOD = 1000000007L;
using namespace std;
int bfs(long x0)
{	if (x0<1 || x0 >1000000006L)
		return -1;
	x0 %= MOD;
	queue<long> qu;							//����һ������
	map<long, int> mymap;					//���xģֵ���ƶ�����
	qu.push(x0);							//x0����
	mymap[x0] = 0;							//��ʼʱx+0��Ӧ���ƶ�����Ϊ0
	while(!qu.empty())						//�Ӳ���ѭ��
	{	long e=qu.front();					//����Ԫ��e
		qu.pop();
		if (0==e)							//�ҵ����ǣ����ش���
			return mymap[e];
		if(mymap[e]<=100000)				//�ƶ�����С�ڵ���100000
		{	long x1=(4*e+3) % MOD;			//xһ���ƶ�
			if(mymap.find(x1)==mymap.end())	//mymap��û���ҵ�
			{	mymap[x1]=mymap[e]+1;		//��������1
				qu.push(x1);				//�ƶ��������
			}
			long x2=(8*e+7) % MOD;			//xһ������
			if(mymap.find(x2)==mymap.end())	//mymap��û���ҵ�
			{	mymap[x2]=mymap[e]+1;		//��������1
				qu.push(x2);				//�ƶ��������
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