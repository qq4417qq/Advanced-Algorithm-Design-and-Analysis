#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
using namespace std;
#define MAXN 55
#define MAXM 105
/*****���ַ���a��������ans***************/
int ans;								 //ȫ�ֱ���,�ۼ�������
void Merge(char a[],int low,int mid,int high) //������������ι鲢
{	int i=low;
	int j=mid+1;
	int k=0;
	char *tmp=(char *)malloc((high-low+1)*sizeof(int));
	while(i<=mid && j<=high) 			//��·�鲢��a[low..mid]��a[mid+1..high]=>tmp
	{	if(a[i]>a[j])
		{	tmp[k++]=a[j++];
			ans+=mid-i+1;
		}
		else tmp[k++]=a[i++];
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=high) tmp[k++]=a[j++];
	for(int k1=0;k1<k;k1++)			//tmp[0..k-1]=>a[low..high]
        a[low+k1]=tmp[k1];
	free(tmp);
}
void MergeSort(char a[],int low,int high)  //�ݹ��·�鲢����
{	if(low<high)
	{	int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
int Inversion(char a[],int n)			//��·�鲢�����ַ���a��������
{	ans=0;
	MergeSort(a,0,n-1);
	return ans;
}
/*************************************/
typedef struct
{	int v;							//���str[i]��������
	int i;							//����ַ������±�i
} ElemType;						//��������b��Ԫ������
struct Cmp						//���������ϵ����
{	bool operator()(const ElemType &s,const ElemType &t) const
	{	return s.v<t.v;	}			//ָ������������������
};
int main()
{	int i,n,m;
	char str[MAXM][MAXN];
	ElemType b[MAXM];
	memset(b,0,sizeof(b));
	char tmp[MAXN];
	scanf("%d%d",&n,&m);			//����n��m
	for (i=0;i<m;i++)				//����m���ַ���
		scanf("%s",str[i]);
	for (i=0;i<m;i++)				//�������ַ�����������
	{	strcpy(tmp,str[i]);			//���ڱ���ԭ���в���,��ʱ���Ƶ�tmp��
		b[i].v=Inversion(tmp,n);	//��tmp������Ը���
		b[i].i=i;					//��¼ԭ�����±�
	}
	stable_sort(b,b+m,Cmp());		//�����ȶ��������㷨
	for (i=0;i<m;i++)				//������
		printf("%s\n",str[b[i].i]);
	return 0;
}
