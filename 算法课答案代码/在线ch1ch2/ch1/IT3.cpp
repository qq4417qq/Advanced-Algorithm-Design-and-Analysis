#include <iostream>
#include <string>
using namespace std;
//�����ʾ
int n;
string str;
void swap(char &x,char &y)			//����x��y
{	char tmp=x;
	x=y; y=tmp;
}
int Move(string &s)					//�ƶ��ַ���s�е�'*'�ַ�
{
	int i=s.length(),j=s.length()-1;
	while (j>=0)					//jɨ������Ԫ��
	{
		if (s[j]!='*')				//�ҵ���Ϊ'*'��Ԫ��s[j]
		{
			i--;					//����Ϊ*������
			if (i!=j)
				swap(s[i],s[j]);	//��s[j]��������Ϊ'*'�����ǰ��
		}
		j--;						//����ɨ��
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
