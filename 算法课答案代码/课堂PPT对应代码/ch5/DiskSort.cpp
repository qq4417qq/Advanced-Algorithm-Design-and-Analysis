//求解磁盘排序问题的算法
//其中使用到的两个快速排序算法如下:
//void QuickSort(int a[],int s,int t):对a[s..t]元素序列进行递增排序
//void QuickSort1(FInfo a[],int s,int t):对a[s..t]元素序列按num递增排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 32767					//表示∞
#define W 5							//应用程序的内存大小
#define FILEN 20					//最多归并段数
#define MAXK 5						//最大归并路数
typedef struct
{	int no;							//归并段编号
	int tag;						//标记:0表示未归并,1表示已归并
	int num;						//归并段中的整数个数，即长度
	char fn[10];					//归并段对应的文件名
} FInfo;							//归并段信息类型
FILE *fp[FILEN];					//文件指针数组,全局变量
int m;								//实际的归并段数,全局变量
int k;								//实际的归并路数,全局变量
//--------------------------------------------------------
int Partition(int a[],int s,int t)	//划分算法
{	int i=s,j=t;
	int tmp=a[s];				//用序列的第1个记录作为基准
	while (i!=j)				//从序列两端交替向中间扫描,直至i=j为止
	{	while (j>i && a[j]>=tmp) 
			j--;				//从右向左扫描,找第1个关键字小于tmp的a[j]
		a[i]=a[j];				//将a[j]前移到a[i]的位置
		while (i<j && a[i]<=tmp) 
			i++;				//从左向右扫描,找第1个关键字大于tmp的a[i]
		a[j]=a[i];				//将a[i]后移到a[j]的位置
	}
	a[i]=tmp;
	return i;
}
void QuickSort(int a[],int s,int t)	//对a[s..t]元素序列进行递增排序
{	int i;
	if (s<t) 				//序列内至少存在2个元素的情况
	{	i=Partition(a,s,t);
		QuickSort(a,s,i-1);	//对左子序列递归排序
		QuickSort(a,i+1,t);	//对右子序列递归排序
	}
}
int Partition1(FInfo a[],int s,int t)	//划分算法
{	int i=s,j=t;
	FInfo tmp=a[s];			//用序列的第1个记录作为基准
	while (i!=j)			//从序列两端交替向中间扫描,直至i=j为止
	{	while (j>i && a[j].num>=tmp.num) 
			j--;			//从右向左扫描,找第1个关键字小于tmp.num的a[j]
		a[i]=a[j];			//将a[j]前移到a[i]的位置
		while (i<j && a[i].num<=tmp.num) 
			i++;			//从左向右扫描,找第1个关键字大于tmp.num的a[i]
		a[j]=a[i];			//将a[i]后移到a[j]的位置
	}
	a[i]=tmp;
	return i;
}
void QuickSort1(FInfo a[],int s,int t)	//对a[s..t]元素序列进行递增排序
{	int i;
	if (s<t) 					//序列内至少存在2个元素的情况
	{	i=Partition1(a,s,t);
		QuickSort1(a,s,i-1);	//对左子序列递归排序
		QuickSort1(a,i+1,t);	//对右子序列递归排序
	}
}
//--------------------------------------------------------
void CreateFilename(char *fname,int i)	//产生一个新文件名
{	char fno[3];
	itoa(i,fno,10);						//将整数i转换成字符串fno
	strcpy(fname,"F");
	strcat(fname,fno);
	strcat(fname,".dat");				//产生文件名F0.dat、F1.dat、F2.dat等
}
void CreateFile(int a[],int n)			//建立初始文件Fin.dat文件
{	int i,e=INF;
	FILE *ifp;
	ifp=fopen("Fin.dat","wb");
	for (i=0;i<n;i++)					//将a中数据写入Fin.dat文件中
		fwrite(&a[i],sizeof(int),1,ifp);
	fclose(ifp);
}
void CreateInitFile(FInfo fi[],int n) 	//产生m个长度不超过W的归并段
{	FILE *ifp;
	int i,j,e=INF;
	int b[W];
	char fname[10];
	ifp=fopen("Fin.dat","rb");			//打开Fin.dat文件
	m=0;
	for (i=0;i<(n/W);i++)				//循环n/W次
	{	fread(b,sizeof(int),W,ifp);		//从文件读出W个整数
		QuickSort(b,0,W-1);				//将数组b排序
		CreateFilename(fname,i);		//产生一个类似F1.dat的新归并段文件名
		fp[i]=fopen(fname,"wb");		//打开新归并段的文件
		fwrite(b,sizeof(int),W,fp[i]);	//写入归并段文件中
		fwrite(&e,sizeof(int),1,fp[i]);	//末尾写入一个∞
		fclose(fp[i]);					//关闭归并段文件
		fi[m].num=W; fi[m].tag=0;		//存入新归并段的信息
		fi[m].no=m; strcpy(fi[m].fn,fname);
		m++;							//归并段个数增1
	}
	j=n-m*W;							//求最后不满W个整数的整数个数
	if (j>0)							//还存在最后不满W的j个记录
	{	fread(b,sizeof(int),j,ifp);		//从输入文件读出W个整数
		QuickSort(b,0,j-1);				//将数组b排序
		CreateFilename(fname,i);		//产生一个类似F1.dat的归并段文件名
		fp[i]=fopen(fname,"wb");		//打开一个归并段文件
		fwrite(b,sizeof(int),j,fp[i]);	//向文件中写入j个整数
		fwrite(&e,sizeof(int),1,fp[i]);	//末尾写入一个∞
		fclose(fp[i]);					//关闭文件
		fi[m].num=j; fi[m].tag=0;		//存入归并段的信息
		fi[m].no=m; strcpy(fi[m].fn,fname);
		m++;							//归并段个数增1
	}
	printf("(1)生成的初始归并段个数=%d,段号从0～%d\n",m,m-1);
	for (i=0;i<m;i++)
		printf("\t段号:%d,记录个数:%d\n",fi[i].no,fi[i].num);
	fclose(ifp);
}
int Min(int a[],int &minv)
//在k个归并段的当前值中找最小值minv,并返回所在的序号minno
{	int i,minno;
	minv=a[0]; minno=0; 				//minv置初值
	for (i=1;i<k;i++)
		if (a[i]<minv)
		{	minv=a[i];					//将更小的值放到minv中
			minno=i;					//minno保存最小值所在的序号
		}
	return minno;
}
void Insert(FInfo fi[],char *fname,int length)//将新归并段信息有序插入到fi中
{	int i=0,j;
	while (i<m && fi[i].num<length)
		i++;
	for (j=m;j>=i;j--)
		fi[j+1]=fi[j];
	fi[i].num=length; fi[i].no=m;		//存入归并段文件的信息到fi[i]中
	fi[i].tag=0; strcpy(fi[i].fn,fname);
	m++;								//归并段个数增1
}
void Merge(FInfo mergek[],FInfo fi[])	//将k个归并段文件归并为一个归并段文件
{	FILE *nfp;
	int i,minno,minv=0,length=0,e=INF;
	bool stop;
	int a[MAXK];
	char fname[10];
	CreateFilename(fname,m);			//产生一个类似F1.dat的文件名
	nfp=fopen(fname,"wb");				//新建一个归并段文件
	for (i=0;i<k;i++)					//打开要归并的所有归并段文件并且求总长度
	{	fp[i]=fopen(mergek[i].fn,"rb");
		length+=mergek[i].num;
	}
	for (i=0;i<k;i++)					//从k个归并段文件中分别读出一个整数存放在数组a中
		fread(&a[i],sizeof(int),1,fp[i]);
	while (true)						//循环归并k个归并段
	{	stop=true;						//stop为true表示归并结束,否则继续
		for (i=0;i<k;i++)				//只要有一个归并段未遍历完便继续
			if (a[i]!=INF)
			{	stop=false;
				break;
			}
		if (!stop)						//未结束时归并
		{	minno=Min(a,minv);			//找最小值minv及其所在的子序列号minno
			fwrite(&minv,sizeof(int),1,nfp);	//将minv写入新归并段文件中
			fread(&a[minno],sizeof(int),1,fp[minno]); //取出对应归并段的下一个整数
		}
		else break;						//当所有归并段归并完毕,退出while循环
	}
	fwrite(&e,sizeof(int),1,nfp);		//末尾写入一个∞
	for (i=0;i<k;i++)					//关闭所有打开的归并段文件
		fclose(fp[i]);
	fclose(nfp);						//关闭新建的归并段文件
	Insert(fi,fname,length);			//将新归并段信息有序插入到fi中
}
void EMerge(FInfo fi[])					//实现k路归并
{	int i,j,s,rm=m;						//rm为余下的未归并的归并段数,初值为m
	FInfo mergek[MAXK];					//一次要归并的k个归并段
	printf("(4)归并过程:\n");
	while (rm>1)						//归并到rm=1为止
	{	i=0; s=0;
		while (i<m && s<k)				//找长度最小的k个归并段
		{	if (fi[i].tag==0)
			{	mergek[s]=fi[i];
				s++;
				fi[i].tag=1;			//改为已归并标记 
			}
			i++;
		}
		printf("  归并的段:");
		for (j=0;j<k;j++)
			printf("%d ",mergek[j].no);
		printf("=> %d\n",m);
		rm=rm-k+1;						//余下未归并的归并段数减少k-1个
		Merge(mergek,fi);				//归并这k个归并段并产生一个新的归并段
	}
}
void AddVirFile(FInfo fi[])				//增加若干个虚归并段
{	int i,s,e=INF;
	char fname[10];
	s=(m-1)%(k-1);
	if (s!=0)
		for (i=0;i<k-1-s;i++)				//添加k-1-s个虚归并段,其长度为0
		{	CreateFilename(fname,m);		//产生一个类似F1.dat的文件名
			fp[i]=fopen(fname,"wb");		//建立归并段文件
			fwrite(&e,sizeof(int),1,fp[i]);	//仅写入一个∞
			fclose(fp[i]);					//关闭文件
			fi[m].num=0; fi[m].tag=0;		//添加虚归并段信息
			fi[m].no=m; strcpy(fi[m].fn,fname); 
			m++;
		}
	printf("(2)增加%d个虚段\n",k-1-s);
}
void dispFile(char *fname,int no)	//输出fname文件的内容
{	int e;
	FILE *efp;
	efp=fopen(fname,"rb");			//打开该文件
	printf("  %s(段号为%d):",fname,no);
	while (true)					//读出所有数据并输出
	{	fread(&e,sizeof(int),1,efp);
		if (e==INF) break;
		printf("%d ",e);
	}
	fclose(efp);
	printf("\n");
}
void main()
{	int i,n=27;
	FInfo fi[FILEN];
	int a[]={6,21,2,9,11,26,31,27,30,5,8,20,1,7,23,15,16,25,29,3,4,24,10,12,13,17,28};
	CreateFile(a,n);			//建立Fin.dat文件
	CreateInitFile(fi,n);		//建立初始输入文件
	k=3;						//采用3路归并
	AddVirFile(fi);
	QuickSort1(fi,0,m-1);		//对fi数组按num递增排序
	printf("(3)按记录个数递增排序后:\n");
	for (i=0;i<m;i++)
		printf("\t段号:%d,记录个数:%d\n",fi[i].no,fi[i].num);
	EMerge(fi);
	printf("所有归并段的文件:\n");
	for (i=0;i<m;i++)
		dispFile(fi[i].fn,fi[i].no);
}
