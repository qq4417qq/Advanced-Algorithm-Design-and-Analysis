#include <stdio.h>
int Partition(int a[],int low,int high) //��a[low]Ϊ��׼����
{  int i=low,j=high;
   int povit=a[low];
   while (i<j)
   {
       while (i<j && a[j]>=povit)
          j--;
       a[i]=a[j];
       while (i<j && a[i]<=povit)
          i++;
       a[j]=a[i];
   }
   a[i]=povit;
   return i;
} 
int Solve(int a[],int n)		//����㷨
{  int low=0,high=n-1;
   bool flag=true;
   while (flag)
   {
      int i=Partition(a,low,high);
      if (i==n/2-1)			//��׼a[i]Ϊ��n/2��Ԫ��
         flag=false;
      else if (i<n/2-1)		//�����������
         low=i+1;
      else
         high=i-1;			//�����������
   }
   int s1=0,s2=0;
   for (int i=0;i<n/2;i++)
     s1+=a[i];
   for (int j=n/2;j<n;j++)
     s2+=a[j];
   return s2-s1;
}
void display(int a[],int low,int high)	//���a[low..high]
{
	for (int i=low;i<=high;i++)
		printf("%3d",a[i]);
	printf("\n");
}
void main()
{
	printf("ʵ����:\n");
	int a[]={1,3,5,7,9,2,4,6,8};
	int n=sizeof(a)/sizeof(a[0]);
	printf("   ��ʼ���� A:"); display(a,0,n-1);
	printf("   ����� %d\n",Solve(a,n));
	printf("   ���ֽ�� A1:"); display(a,0,n/2-1);
	printf("\t    A2:"); display(a,n/2,n-1);

	int b[]={1,3,5,7,9,10,2,4,6,8};
	int m=sizeof(b)/sizeof(b[0]);
	printf("   ��ʼ���� B:"); display(b,0,m-1);
	printf("   ����� %d\n",Solve(b,m));
	printf("   ���ֽ�� B1:"); display(b,0,m/2-1);
	printf("\t    B2:"); display(b,m/2,m-1);
}
