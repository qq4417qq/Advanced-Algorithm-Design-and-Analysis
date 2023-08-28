#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>	
using namespace std;
#define MAXL 15
//�����ʾ
char str[MAXL];				//������ַ���
int n;						//���������
int m;						//str�ĳ���
char x[5];					//���һ����
bool flag;					//�ж��Ƿ��н�
void swap(char &a,char &b)	//���������ַ�
{
	char tmp=a;
	a=b; b=tmp;
}

int fn(char a,int n)	//���д��ĸa��n�η�
{
	if (n==1)
		return a-'A'+1;
	return (a-'A'+1)*fn(a,n-1);
}
void dfs(int i)
{
	if (i==5)
	{
		if (fn(x[0],1)-fn(x[1],2)+fn(x[2],3)-fn(x[3],4)+fn(x[4],5)==n)
		{
			flag=true;
			for (int j=0; j<5; j++)		//�����
				cout << x[j];
			cout << endl;
		}
		return;
	}
	if (flag) return;	//��ʾ�Ѿ��н����
	for (int j=i;j<m;j++)
	{
		swap(str[i],str[j]);
		x[i]=str[i];
		dfs(i+1);
		swap(str[i],str[j]);
	}
}
int main()
{
	while (true)
	{
		cin >> n;							//����n
		if (n==0) break;					//n=0����
		cin >> str;							//�����ַ���
		m=strlen(str);						//����䳤��
		flag=false;							//�������޽��־
		sort(str,str+m,greater<char>());	//���ֵ���ݼ�����
		dfs(0);								//��0��ʼ����
		if (!flag)
			cout << "no solution" << endl;
	}
	return 0;
}
