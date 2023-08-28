#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
using namespace std;
#define MAXN 55
#define MAXM 105
/*****求字符串a的逆序数ans***************/
int ans;								 //全局变量,累计逆序数
void Merge(char a[],int low,int mid,int high) //两个相邻有序段归并
{	int i=low;
	int j=mid+1;
	int k=0;
	char *tmp=(char *)malloc((high-low+1)*sizeof(int));
	while(i<=mid && j<=high) 			//二路归并：a[low..mid]、a[mid+1..high]=>tmp
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
void MergeSort(char a[],int low,int high)  //递归二路归并排序
{	if(low<high)
	{	int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
int Inversion(char a[],int n)			//二路归并法求字符串a的逆序数
{	ans=0;
	MergeSort(a,0,n-1);
	return ans;
}
/*************************************/
typedef struct
{	int v;							//存放str[i]的逆序数
	int i;							//存放字符串的下标i
} ElemType;						//声明数组b的元素类型
struct Cmp						//定义排序关系函数
{	bool operator()(const ElemType &s,const ElemType &t) const
	{	return s.v<t.v;	}			//指定按逆序数递增排序
};
int main()
{	int i,n,m;
	char str[MAXM][MAXN];
	ElemType b[MAXM];
	memset(b,0,sizeof(b));
	char tmp[MAXN];
	scanf("%d%d",&n,&m);			//输入n和m
	for (i=0;i<m;i++)				//输入m个字符串
		scanf("%s",str[i]);
	for (i=0;i<m;i++)				//求所有字符串的逆序数
	{	strcpy(tmp,str[i]);			//由于保存原序列不变,临时复制到tmp中
		b[i].v=Inversion(tmp,n);	//求tmp的逆序对个数
		b[i].i=i;					//记录原来的下标
	}
	stable_sort(b,b+m,Cmp());		//采用稳定的排序算法
	for (i=0;i<m;i++)				//输出结果
		printf("%s\n",str[b[i].i]);
	return 0;
}
