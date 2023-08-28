#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
//�����ʾ
int w[12];
string a[3]={"ABCD","ABCI","ABIJ"};
string b[3]={"EFGH","EFJK","EFGH"};
string c[]={"even","up","even"};
bool Balanced()					//�ж��Ƿ�����ؽ��ƥ��
{
	for (int i=0;i<3;i++)		//3�γ���
	{
		int leftw=0;
		int rightw=0;
		for (int j=0;j<a[i].size();j++)
		{
			leftw+=w[a[i][j]-'A'];
			rightw+=w[b[i][j]-'A'];
		}
		if (leftw<rightw && c[i]!="down")
			return false;
		if (leftw==rightw && c[i]!="even")
			return false;
		if (leftw>rightw && c[i]!="up")
			return false;
	}
	return true;
}
void solve(int &x,int &y)					//��ٱ�
{
	for (int i=0;i<12;i++)
	{
		w[i]=1;				//��i��Ӳ��Ϊ�ٱң�������������
		if (Balanced())
		{
			x=i;
			y=1;
			return;
		}
		w[i]=-1;			//��i��Ӳ��Ϊ�ٱң�������������
		if (Balanced())
		{
			x=i;
			y=-1;
			return;
		}
		w[i]=0;				//���ݣ��ָ���i��Ӳ��Ϊ���
	}
}
void main()
{
	memset(w,0,sizeof(w));	//��ʼ������Ӳ��Ϊ���
	int x,y;
	solve(x,y);
	printf("�����\n");
	printf("   �ٱ���%c\n",x+'A');
	if (y==1)
		printf("   ��Ӳ�ҽ����������\n");
	else
		printf("   ��Ӳ�ҽ����������\n");
}

