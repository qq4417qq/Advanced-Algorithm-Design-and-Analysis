#include <stdio.h>
#include <math.h>
#define N 10  
bool used[N+1];					//used[i]=true��ʾ����i����ʹ��
int a[9];						//���3��3������
int count=0;					//ͳ�ƽ����
int Checkmatrix[][3]={ {-1},{0,-1},{1,-1},{0,-1},{1,3,-1},
				 {2,4,-1},{3,-1},{4,6,-1},{5,7,-1} };  
void dispasolution(int a[])			//���һ����
{	int i,j;
	printf("��%d\n",++count);
	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
			printf("%3d",a[3*i+j]);
		printf("\n");
	}
}
bool isPrime(int m)				//�ж�m�Ƿ�Ϊ����
{	bool flag=true;
	for (int i=2;i<=sqrt(m);i++)
		if (m%i==0)
			return false;
	return true;
} 
bool Check(int pos)				//���a��posλ�õ��������������ڵ�����֮���Ƿ�Ϊ����
{	int i,j;
	if (pos<0) return 0;
	for (i=0;(j=Checkmatrix[pos][i])>=0;i++)
		if (!isPrime(a[pos]+a[j]))	//��һ����������,�򷵻�false
			return false;
	return true; 
}
int selectnum(int start)			//��startλ�ÿ�ʼѡ��һ��û��ʹ�õ�����
{	for (int j=start;j<=N;j++)
		if (used[j]) return j;
	return 0;					//û�к��ʵ����ַ���0
} 
int extend(int pos)				//��չ:Ϊposλ��ѡ��һ��û��ʹ�õ�����,pos++
{	a[++pos]=selectnum(1);		//��չ���̶��Ǵ�1��ʼѡ�����ֵ�
	used[a[pos]]=0;  			//��־��������ʹ��
	return pos;  
}
int change(int pos)				//��������pos��ʼ����
{	int j;
	//Ϊposλ��ѡ������һ������,Ϊ�˱����ظ�,�Ǵ�ԭ���ֵ���һ�����ֿ�ʼѡȡ��
	//������Ϊposѡ��һ������,�����,���ָ�a[pos]Ϊ����ʹ�õ�,��ִ��pos--
	while (pos>=0 && (j=selectnum(a[pos]+1))==0)
		used[a[pos--]]=true;
	if (pos<0) return -1;			//ȫ���������,����-1�㷨����
	used[a[pos]]=true;			//Ϊposλ���ҵ�һ��û��ʹ�õ�����j
	a[pos]=j;					//posλ�÷�������j
	used[j]=false;				//��ʶ����j�Ѿ�ʹ�ù�
	return pos;					//���ظû��ݵ���λ��  
}
void solve()					//����㷨
{	bool ok=true;				//��ǰ�����Ƿ���Ч
	int pos=0;					//��λ��0��ʼ
	a[pos]=1;					//��posλ������1
	used[a[pos]]=0;				//��־����1�Ѿ�ʹ�ù�
	do
	{	if (ok)
		{	if (pos==8)
			{	dispasolution(a);
				pos=change(pos);
			}
			else pos=extend(pos); 
		}
		else
			pos=change(pos);
		ok=Check(pos);
	} while (pos>=0);
}
void main() 
{	for (int i=1;i<=N;i++)			//��ʼ��,�������־�����ʹ��
		used[i]=true;
	solve();
	printf("count=%d\n",count);	//������������
}
