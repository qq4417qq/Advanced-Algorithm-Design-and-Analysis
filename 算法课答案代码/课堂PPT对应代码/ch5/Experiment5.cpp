//�ϻ�ʵ����5
#include <stdio.h>
#include <string.h>
#define MAXN 20
void delek(char a[],int k)	//������a��ɾ��k������
{
	int i,m=strlen(a);
	if (k>=m)				//k>=mʱȫ��ɾ��
	{
		a="";
		return;
	}
	while (k>0)				//��a��ɾ��kλ
	{
		for (i=0;i<m-1 && a[i]<=a[i+1];i++);
		strcpy(a+i,a+i+1);		//ɾ��a[i]
		k--;
		m--;
	}
	while (m>1 && a[0]=='0')	//ɾ��ǰ��0
		strcpy(a,a+1);
}
void longtostr(long d,char a[])	//��d�ĸ�λ����a������
{
	int i,n=0;
	char tmp;
	while (d>0)
	{
		a[n++]='0'+d%10;
		d/=10;
	}
	a[n]='\0';
	for (i=0;i<n/2;i++)			//���ã�ʹa[0]���d�ĸ�λ
	{
		tmp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tmp;
	}
}
long strtolong(char a[])		//��aת��Ϊ������
{
	int i,m=strlen(a);
	long d=0;
	for (i=0;i<m;i++)
		d=d*10+(a[i]-'0');
	return d;
}
void main()
{
	char a[MAXN];
	long d=5004321;
	int k=3;
	longtostr(d,a);
	printf("ɾ��ǰ:%ld\n",d);
	delek(a,k);
	d=strtolong(a);
	printf("ɾ��%d�����ֺ�:%ld\n",k,d);
}