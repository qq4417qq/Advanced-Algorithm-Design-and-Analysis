#include "btree.cpp"						//�����������Ļ��������㷨
int maxsum=0;								//ȫ�ֱ�����������·����
vector<int> maxpath;						//ȫ�ֱ�����������·��
void Findmaxpath(BTNode *bt,vector<int> apath,int asum)
//�����㵽Ҷ����·��������·��
{	if (bt==NULL)							//����ֱ�ӷ���
		return;
	apath.push_back(bt->data);				//bt������apath
	asum+=bt->data;							//�ۼ�·����
	if (bt->lchild==NULL && bt->rchild==NULL)	//bt���ΪҶ���
	{	if (asum>maxsum)
		{	maxsum=asum;
			maxpath.clear();
			maxpath=apath;
		}
	}
	Findmaxpath(bt->lchild,apath,asum);		//���������в���
	Findmaxpath(bt->rchild,apath,asum);		//���������в���
}
void main()
{
	BTNode *bt;
	ElemType a[]={5,2,3,4,1,6};
	ElemType b[]={2,3,5,1,4,6};
	int n=sizeof(a)/sizeof(a[0]);
	bt=CreateBTree(a,b,n);
	printf("ʵ����:\n");
	printf("  ������bt:"); DispBTree(bt); printf("\n");
	printf("  ���·��");
	vector<int> apath;
	int asum=0;
	Findmaxpath(bt,apath,asum);
	printf("  ·����: %d, ·��: ",maxsum);
	for (int i=0;i<maxpath.size();i++)
		printf("%d ",maxpath[i]);
	printf("\n");
	printf("  ������bt\n");
	DestroyBTree(bt);
}
