#include <iostream>
#include <map>
using namespace std;
#define MAX 1001
int main()
{  int n,x;
   int a[MAX];
   map<int,int> mp;
   cin >> n;
   for(int i=0;i<n;i++)
   {  cin >> x;
      ++mp[x];		//累计x出现的次数
      a[i]=mp[x];
   }
   for(int j=0;j<n;j++)
      cout << a[j] << " ";
   cout << endl;
   return 0;
} 
