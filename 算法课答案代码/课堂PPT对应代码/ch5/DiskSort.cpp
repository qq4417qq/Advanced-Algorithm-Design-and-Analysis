//����������������㷨
//����ʹ�õ����������������㷨����:
//void QuickSort(int a[],int s,int t):��a[s..t]Ԫ�����н��е�������
//void QuickSort1(FInfo a[],int s,int t):��a[s..t]Ԫ�����а�num��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 32767					//��ʾ��
#define W 5							//Ӧ�ó�����ڴ��С
#define FILEN 20					//���鲢����
#define MAXK 5						//���鲢·��
typedef struct
{	int no;							//�鲢�α��
	int tag;						//���:0��ʾδ�鲢,1��ʾ�ѹ鲢
	int num;						//�鲢���е�����������������
	char fn[10];					//�鲢�ζ�Ӧ���ļ���
} FInfo;							//�鲢����Ϣ����
FILE *fp[FILEN];					//�ļ�ָ������,ȫ�ֱ���
int m;								//ʵ�ʵĹ鲢����,ȫ�ֱ���
int k;								//ʵ�ʵĹ鲢·��,ȫ�ֱ���
//--------------------------------------------------------
int Partition(int a[],int s,int t)	//�����㷨
{	int i=s,j=t;
	int tmp=a[s];				//�����еĵ�1����¼��Ϊ��׼
	while (i!=j)				//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && a[j]>=tmp) 
			j--;				//��������ɨ��,�ҵ�1���ؼ���С��tmp��a[j]
		a[i]=a[j];				//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i<j && a[i]<=tmp) 
			i++;				//��������ɨ��,�ҵ�1���ؼ��ִ���tmp��a[i]
		a[j]=a[i];				//��a[i]���Ƶ�a[j]��λ��
	}
	a[i]=tmp;
	return i;
}
void QuickSort(int a[],int s,int t)	//��a[s..t]Ԫ�����н��е�������
{	int i;
	if (s<t) 				//���������ٴ���2��Ԫ�ص����
	{	i=Partition(a,s,t);
		QuickSort(a,s,i-1);	//���������еݹ�����
		QuickSort(a,i+1,t);	//���������еݹ�����
	}
}
int Partition1(FInfo a[],int s,int t)	//�����㷨
{	int i=s,j=t;
	FInfo tmp=a[s];			//�����еĵ�1����¼��Ϊ��׼
	while (i!=j)			//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && a[j].num>=tmp.num) 
			j--;			//��������ɨ��,�ҵ�1���ؼ���С��tmp.num��a[j]
		a[i]=a[j];			//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i<j && a[i].num<=tmp.num) 
			i++;			//��������ɨ��,�ҵ�1���ؼ��ִ���tmp.num��a[i]
		a[j]=a[i];			//��a[i]���Ƶ�a[j]��λ��
	}
	a[i]=tmp;
	return i;
}
void QuickSort1(FInfo a[],int s,int t)	//��a[s..t]Ԫ�����н��е�������
{	int i;
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{	i=Partition1(a,s,t);
		QuickSort1(a,s,i-1);	//���������еݹ�����
		QuickSort1(a,i+1,t);	//���������еݹ�����
	}
}
//--------------------------------------------------------
void CreateFilename(char *fname,int i)	//����һ�����ļ���
{	char fno[3];
	itoa(i,fno,10);						//������iת�����ַ���fno
	strcpy(fname,"F");
	strcat(fname,fno);
	strcat(fname,".dat");				//�����ļ���F0.dat��F1.dat��F2.dat��
}
void CreateFile(int a[],int n)			//������ʼ�ļ�Fin.dat�ļ�
{	int i,e=INF;
	FILE *ifp;
	ifp=fopen("Fin.dat","wb");
	for (i=0;i<n;i++)					//��a������д��Fin.dat�ļ���
		fwrite(&a[i],sizeof(int),1,ifp);
	fclose(ifp);
}
void CreateInitFile(FInfo fi[],int n) 	//����m�����Ȳ�����W�Ĺ鲢��
{	FILE *ifp;
	int i,j,e=INF;
	int b[W];
	char fname[10];
	ifp=fopen("Fin.dat","rb");			//��Fin.dat�ļ�
	m=0;
	for (i=0;i<(n/W);i++)				//ѭ��n/W��
	{	fread(b,sizeof(int),W,ifp);		//���ļ�����W������
		QuickSort(b,0,W-1);				//������b����
		CreateFilename(fname,i);		//����һ������F1.dat���¹鲢���ļ���
		fp[i]=fopen(fname,"wb");		//���¹鲢�ε��ļ�
		fwrite(b,sizeof(int),W,fp[i]);	//д��鲢���ļ���
		fwrite(&e,sizeof(int),1,fp[i]);	//ĩβд��һ����
		fclose(fp[i]);					//�رչ鲢���ļ�
		fi[m].num=W; fi[m].tag=0;		//�����¹鲢�ε���Ϣ
		fi[m].no=m; strcpy(fi[m].fn,fname);
		m++;							//�鲢�θ�����1
	}
	j=n-m*W;							//�������W����������������
	if (j>0)							//�����������W��j����¼
	{	fread(b,sizeof(int),j,ifp);		//�������ļ�����W������
		QuickSort(b,0,j-1);				//������b����
		CreateFilename(fname,i);		//����һ������F1.dat�Ĺ鲢���ļ���
		fp[i]=fopen(fname,"wb");		//��һ���鲢���ļ�
		fwrite(b,sizeof(int),j,fp[i]);	//���ļ���д��j������
		fwrite(&e,sizeof(int),1,fp[i]);	//ĩβд��һ����
		fclose(fp[i]);					//�ر��ļ�
		fi[m].num=j; fi[m].tag=0;		//����鲢�ε���Ϣ
		fi[m].no=m; strcpy(fi[m].fn,fname);
		m++;							//�鲢�θ�����1
	}
	printf("(1)���ɵĳ�ʼ�鲢�θ���=%d,�κŴ�0��%d\n",m,m-1);
	for (i=0;i<m;i++)
		printf("\t�κ�:%d,��¼����:%d\n",fi[i].no,fi[i].num);
	fclose(ifp);
}
int Min(int a[],int &minv)
//��k���鲢�εĵ�ǰֵ������Сֵminv,���������ڵ����minno
{	int i,minno;
	minv=a[0]; minno=0; 				//minv�ó�ֵ
	for (i=1;i<k;i++)
		if (a[i]<minv)
		{	minv=a[i];					//����С��ֵ�ŵ�minv��
			minno=i;					//minno������Сֵ���ڵ����
		}
	return minno;
}
void Insert(FInfo fi[],char *fname,int length)//���¹鲢����Ϣ������뵽fi��
{	int i=0,j;
	while (i<m && fi[i].num<length)
		i++;
	for (j=m;j>=i;j--)
		fi[j+1]=fi[j];
	fi[i].num=length; fi[i].no=m;		//����鲢���ļ�����Ϣ��fi[i]��
	fi[i].tag=0; strcpy(fi[i].fn,fname);
	m++;								//�鲢�θ�����1
}
void Merge(FInfo mergek[],FInfo fi[])	//��k���鲢���ļ��鲢Ϊһ���鲢���ļ�
{	FILE *nfp;
	int i,minno,minv=0,length=0,e=INF;
	bool stop;
	int a[MAXK];
	char fname[10];
	CreateFilename(fname,m);			//����һ������F1.dat���ļ���
	nfp=fopen(fname,"wb");				//�½�һ���鲢���ļ�
	for (i=0;i<k;i++)					//��Ҫ�鲢�����й鲢���ļ��������ܳ���
	{	fp[i]=fopen(mergek[i].fn,"rb");
		length+=mergek[i].num;
	}
	for (i=0;i<k;i++)					//��k���鲢���ļ��зֱ����һ���������������a��
		fread(&a[i],sizeof(int),1,fp[i]);
	while (true)						//ѭ���鲢k���鲢��
	{	stop=true;						//stopΪtrue��ʾ�鲢����,�������
		for (i=0;i<k;i++)				//ֻҪ��һ���鲢��δ����������
			if (a[i]!=INF)
			{	stop=false;
				break;
			}
		if (!stop)						//δ����ʱ�鲢
		{	minno=Min(a,minv);			//����Сֵminv�������ڵ������к�minno
			fwrite(&minv,sizeof(int),1,nfp);	//��minvд���¹鲢���ļ���
			fread(&a[minno],sizeof(int),1,fp[minno]); //ȡ����Ӧ�鲢�ε���һ������
		}
		else break;						//�����й鲢�ι鲢���,�˳�whileѭ��
	}
	fwrite(&e,sizeof(int),1,nfp);		//ĩβд��һ����
	for (i=0;i<k;i++)					//�ر����д򿪵Ĺ鲢���ļ�
		fclose(fp[i]);
	fclose(nfp);						//�ر��½��Ĺ鲢���ļ�
	Insert(fi,fname,length);			//���¹鲢����Ϣ������뵽fi��
}
void EMerge(FInfo fi[])					//ʵ��k·�鲢
{	int i,j,s,rm=m;						//rmΪ���µ�δ�鲢�Ĺ鲢����,��ֵΪm
	FInfo mergek[MAXK];					//һ��Ҫ�鲢��k���鲢��
	printf("(4)�鲢����:\n");
	while (rm>1)						//�鲢��rm=1Ϊֹ
	{	i=0; s=0;
		while (i<m && s<k)				//�ҳ�����С��k���鲢��
		{	if (fi[i].tag==0)
			{	mergek[s]=fi[i];
				s++;
				fi[i].tag=1;			//��Ϊ�ѹ鲢��� 
			}
			i++;
		}
		printf("  �鲢�Ķ�:");
		for (j=0;j<k;j++)
			printf("%d ",mergek[j].no);
		printf("=> %d\n",m);
		rm=rm-k+1;						//����δ�鲢�Ĺ鲢��������k-1��
		Merge(mergek,fi);				//�鲢��k���鲢�β�����һ���µĹ鲢��
	}
}
void AddVirFile(FInfo fi[])				//�������ɸ���鲢��
{	int i,s,e=INF;
	char fname[10];
	s=(m-1)%(k-1);
	if (s!=0)
		for (i=0;i<k-1-s;i++)				//���k-1-s����鲢��,�䳤��Ϊ0
		{	CreateFilename(fname,m);		//����һ������F1.dat���ļ���
			fp[i]=fopen(fname,"wb");		//�����鲢���ļ�
			fwrite(&e,sizeof(int),1,fp[i]);	//��д��һ����
			fclose(fp[i]);					//�ر��ļ�
			fi[m].num=0; fi[m].tag=0;		//�����鲢����Ϣ
			fi[m].no=m; strcpy(fi[m].fn,fname); 
			m++;
		}
	printf("(2)����%d�����\n",k-1-s);
}
void dispFile(char *fname,int no)	//���fname�ļ�������
{	int e;
	FILE *efp;
	efp=fopen(fname,"rb");			//�򿪸��ļ�
	printf("  %s(�κ�Ϊ%d):",fname,no);
	while (true)					//�����������ݲ����
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
	CreateFile(a,n);			//����Fin.dat�ļ�
	CreateInitFile(fi,n);		//������ʼ�����ļ�
	k=3;						//����3·�鲢
	AddVirFile(fi);
	QuickSort1(fi,0,m-1);		//��fi���鰴num��������
	printf("(3)����¼�������������:\n");
	for (i=0;i<m;i++)
		printf("\t�κ�:%d,��¼����:%d\n",fi[i].no,fi[i].num);
	EMerge(fi);
	printf("���й鲢�ε��ļ�:\n");
	for (i=0;i<m;i++)
		dispFile(fi[i].fn,fi[i].no);
}
