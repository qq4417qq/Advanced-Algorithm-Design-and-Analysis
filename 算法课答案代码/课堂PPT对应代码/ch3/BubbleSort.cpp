//ð������
#include <stdio.h>
void BubbleSort(int a[],int n)	//��a[0..n-1]�������������ð������
{	int i,j; int tmp;
	bool exchange;
	for (i=0;i<n-1;i++)		//����n-1������
	{	exchange=false;		//��������ǰ��exchangeΪfalse
		for (j=n-1;j>i;j--)	//������Ԫ�رȽ�,�ҳ���СԪ��
			if (a[j]<a[j-1])	//������Ԫ�ط���ʱ
			{	tmp=a[j];		//a[j]��a[j-1]���н���,3��Ԫ���ƶ�����СԪ��ǰ��
				a[j]=a[j-1];
				a[j-1]=tmp;
				exchange=true;//����������������exchangeΪtrue
			}
		if (exchange==false)	//����δ��������ʱ�����㷨
			return;
	}
}
void disp(int a[],int n)		//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("����ǰ:"); disp(a,n);
	BubbleSort(a,n);
	printf("�����:"); disp(a,n);
}
