#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > A;	//С����
priority_queue<int> B;								//�����
void Insert(int x)				//��������x
{
	if (A.size()==0)			//AΪ�գ�ֱ�Ӳ���x
		A.push(x);
	else if (x>A.top())			//x����A�Ѷ�Ԫ��,���뵽A��
	{
		A.push(x);
		if (A.size()>B.size())	//��A��Ԫ�ض���B�����Ѷ�Ԫ���ƶ���B��
		{
			int e=A.top();
			A.pop();
			B.push(e);
		}
	}
	else						//x������A�Ѷ�Ԫ��,���뵽B��
	{
		B.push(x);
		if (B.size()>A.size())	//��B��Ԫ�ض���A�����Ѷ�Ԫ���ƶ���A��
		{
			int e=B.top();
			B.pop();
			A.push(e);
		}
	}
		
}
int Middle()		//����λ��
{
	if (A.size()>B.size())
		return A.top();
	else
		return B.top();
}
void main()
{
	printf("�����\n");
	printf("  ����2,6,1\n");
	Insert(2);
	Insert(6);
	Insert(1);
	printf("  ��λ��=%d\n",Middle());
	printf("  ����3,4\n");
	Insert(3);
	Insert(4);
	printf("  ��λ��=%d\n",Middle());
	printf("  ����5,7\n");
	Insert(5);
	Insert(7);
	printf("  ��λ��=%d\n",Middle());
}






