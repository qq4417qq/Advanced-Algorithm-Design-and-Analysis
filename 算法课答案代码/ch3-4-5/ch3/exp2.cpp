#include <stdio.h>
//�������ʾ
int num;							//ȫ�ֱ���,�������
int maxcnt=0;						//ȫ�ֱ���,�������
void split(int a[],int low,int high,int &mid,int &left,int &right)
//��a[low..high]�м��Ԫ��Ϊ����,ȷ��Ϊ����a[mid]Ԫ�ص�����λ��left��right
{	mid=(low+high)/2;
	for(left=low;left<=high;left++)
		if (a[left]==a[mid])
			break;
	for (right=left+1;right<=high;right++)
		if (a[right]!=a[mid])
			break;
	right--;
}
void Getmaxcnt(int a[],int low,int high)
{	if (low<=high)					//a[low..high]����������1��Ԫ��
	{	int mid,left,right;
		split(a,low,high,mid,left,right);
		int cnt=right-left+1;			//���a[mid]Ԫ�ص�����
		if (cnt>maxcnt)				//�ҵ����������
		{	num=a[mid];
			maxcnt=cnt;
		}
		Getmaxcnt(a,low,left-1);		//�����еݹ鴦��
		Getmaxcnt(a,right+1,high);	//�����еݹ鴦��
	}
}
void main()
{
	int a[]={1,2,2,2,3,3,5,6,6,6,6};
    int n=sizeof(a)/sizeof(a[0]);
	printf("�����\n");
	printf("  ��������: ");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
    Getmaxcnt(a,0,n-1);
	printf("  ����: %d, ����: %d\n",num,maxcnt);
}
