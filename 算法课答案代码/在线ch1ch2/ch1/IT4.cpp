#include <iostream>
#include <string>
using namespace std;
#define N 10002
//�����ʾ
string str1,str2;
int a[N],b[N];
//�������ʾ
int r[N];
void solve(int a[],int b[],int n,int m)		//��a��b��˵Ľ��r
{
	memset(r,0,sizeof(r));			//��ʼ��r������Ԫ��Ϊ0
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<m; j++)
        {
            int k=i+j;				//��Ӧλ�������
            r[k] += a[i] * b[j];
            while(r[k]>9)			//�н�λ
            {
                r[k+1]+=r[k]/10;
                r[k] %= 10;
                k++;
            }
        }
	}
}
int main()
{
	int i;
    while (cin >> str1 >> str2)			//��������������
    {
        for(i=0;i<str1.size();i++)		//str1ת��Ϊ��������a
			a[i]=str1[str1.size()-1-i]-'0';
        for (i=0;i<str2.size();i++)		//str2ת��Ϊ��������b
			b[i]=str2[str2.size()-1-i]-'0';
        solve(a,b,str1.size(),str2.size());
		int high=str1.size()+str2.size()-1;
		while (r[high]== 0 && high>0)	//�����߷�0λ
			high--;
		for (i=high;i>=0; i--)			//������
			cout << r[i];
		cout << endl;
    }
    return 0;
}
