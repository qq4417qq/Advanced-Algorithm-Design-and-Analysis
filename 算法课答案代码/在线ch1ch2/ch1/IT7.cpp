#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Elem
{  int d;			//����
   int num;			//���ִ���
   bool operator<(const Elem &s)
   {
      bool result;
      if(s.num==num)		//������ͬ��dԽСԽ������ǰ��
	  result = s.d>d;
      else			//������ͬ��numԽ��Խ������ǰ��
         result = s.num<num;
      return result;
   }
};

int main()
{  int n;
   cin >> n;
   map<int,int> mymap;
   map<int,int>::iterator it;
   for(int i=0;i<n;i++)			//�ۼ�x�Ĵ��� 
   {  int x;
      cin >> x;
      ++mymap[x];
   }
   vector<Elem> myv;
   for (it=mymap.begin();it!=mymap.end();++it)
   {  Elem e;				//��mymap����myv
      e.d=it->first;
      e.num=it->second;
      myv.push_back(e);
   }
   sort(myv.begin(),myv.end());	 	//myvԪ������ 
   for (int j=0; j<myv.size(); j++)	 //���myv	
      cout << myv[j].d << " "<< myv[j].num << endl;
   return 0;
} 
