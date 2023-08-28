//��ϰ��10
#include <stdio.h>  
#define N 10
int b[N+1];			//b[i]=1,��ʾ����i��û��ѡȡ,����i��ѡȡ
int a[10];			//�������ķ���,��һά������
int checkmatrix[][3]={{-1},{0,-1},{1,-1},	//������ÿ��λ�õ�����λ��
	{0,-1},{1,3,-1},{2,4,-1},{3,-1},{4,6,-1},{5,7,-1}};  
int count=0;
void dispasolution(int a[])	//���һ����
{	int i,j;
	count++;
	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
			printf("%3d",a[3*i+j]);
		printf("\n");
	}
	printf("\n");
}  
int isprime(int m)			//�ж�m�Ƿ�Ϊ����
{	int i;
	if (m==1 || m%2==0) return 0;
	for (i=3;i*i<=m;i+=2)
		if (m%i==0) return 0;
	return 1;
}
int selectnum(int start)	//��start��ʼѡȡһ����û�����������
{	int j;
	for (j=start;j<=N;j++)
		if (b[j]) return j;
	return 0;
}
int check(int pos)			//���a��posλ�õ����Ƿ�����Ҫ��
{	int i,j;
	if (pos<0) return 0;
	for (i=0;(j=checkmatrix[pos][i])>=0;i++)
		if (!isprime(a[pos]+a[j]))
			return 0;
	return 1;  
}
int extend(int pos)			//Ϊpos�ĺ�һ��λ��ѡһ��������
{	a[++pos]=selectnum(1);
	b[a[pos]]=0;
	return pos;
}
int change(int pos)			//���ݵ�pos��ǰһ��λ��
{	int j;
	while (pos>=0 && (j=selectnum(a[pos]+1))==0)
		b[a[pos--]]=1;
	if (pos<0) return -1;
	b[a[pos]]=1;
	a[pos]=j;
	b[j]=0;
	return pos;  
}
void find()					//�����н�
{	int ok=0,pos=0;
	a[pos]=1;
	b[a[pos]]=0;
	do
	{	if (ok)
		{	if (pos==8)		//������������
			{	dispasolution(a);
				pos=change(pos);
			}
			else pos=extend(pos);
		}
		else pos=change(pos);
		ok=check(pos);
	} while (pos>=0);
} 
void main() 
{	int i;
	for (i=1;i<=N;i++)		//b�����ó�ֵ
		b[i]=1;
	find();
	printf("����%d����\n",count);
} 
