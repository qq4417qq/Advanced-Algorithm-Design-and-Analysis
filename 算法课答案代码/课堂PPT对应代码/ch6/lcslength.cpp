//��������������������㷨
#include <stdio.h>
#include <string.h>
#define N 30							//�����������ַ�����
int lcslength(char *a,char *b,int c[][N])	//��c[m][n]������������еĳ���
{	int m=strlen(a),n=strlen(b);		//mΪa�ĳ��ȣ�nΪb�ĳ���
	int i,j;
	for (i=0;i<=m;i++)					//��c[i][0]��c[0][i]��Ϊ0,�����
		c[i][0]=0;
	for (i=0;i<=n;i++)
		c[0][i]=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)				//����forѭ������a��b�������ַ�
		{	if (a[i-1]==b[j-1])		//���������
				c[i][j]=c[i-1][j-1]+1;
			else						//���������
			{	if (c[i-1][j]>=c[i][j-1])
					c[i][j]=c[i-1][j];
				else c[i][j]=c[i][j-1];
			}
		}
	return c[m][n];
}
char *buildlcs(char *a,char *b)		//��a��b�������������
{	int k,i=strlen(a),j=strlen(b);
	int c[N][N];
	k=lcslength(a,b,c);			//kΪa��b������������г���
	static char s[N];				//s���a��b�������������
	s[k]='\0';					//����s�����һ��������
	while (k>0)					//��s�з���s���ַ�
		if (c[i][j]==c[i-1][j]) i--;
		else if (c[i][j]==c[i][j-1]) j--;
		else
		{	s[--k]=a[i-1];
			i--; j--;
		}
	return s;						//����a��b�������������
}
void main()
{	char X[]="abcbdb";
	char Y[]="acbbabdbb";
	printf("X:%s\n",X);
	printf("Y:%s\n",Y);
	printf("X��Y�������������Ϊ%s\n",buildlcs(X,Y));
}
