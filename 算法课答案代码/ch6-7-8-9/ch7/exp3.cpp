#include <stdio.h>
//�����ʾ
int d=7;
int n=4;
int a[]={2,7,3,6};
//��������ʾ
int bestn=0;
void solve()				//���������������
{	int i,sum;
	for(i=0; i<n; i++)
	{	if(a[i]>d)			//ֻҪ��һ���������d��û�н�
		{	printf("û�н�\n");
            	return;
        	}
    	}
    	for(i=0,sum=0; i<n; i++)
	{	sum += a[i];		//�ۼ���ʻ��i�ż���վ�ľ���
		if(sum>d)			//���ܵ�i�ż���վ,����i-1�ż���վ����
		{	printf("    ��%d�ż���վ����\n",i-1);
			bestn++;
			sum=a[i];		//�ۼƴ�i-1�ż���վ��i�ż���վ�ľ���
        }
    }
	printf("  �ܼ��ʹ���: %d\n",bestn);
}
int main()
{	printf("�����\n");
	solve();
	return 0;
}
