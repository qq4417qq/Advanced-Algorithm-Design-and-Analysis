#include "LinkList.cpp"			//����������Ļ��������㷨
LinkNode *Reverse(LinkNode *L)	//���ò���ͷ���ĵ�����L
{	LinkNode *p;
	if (L==NULL || L->next==NULL)
		return L;
	p=Reverse(L->next);
	L->next->next=L; 			//��L������ӵ�L->next������
	L->next=NULL;				//��L�����Ϊ�������ú��β���
	return p;
}
void main()						//����������
{
	ElemType a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkNode *L;
	CreateList(L,a,n);
	printf("ʵ����:\n");
	printf("  ����ǰL: "); DispList(L);
	printf("  ִ��L=Reverse(L)\n");
	L=Reverse(L);
	printf("  ���ú�L: "); DispList(L);
	printf("  ����L\n");
	DestroyList(L);				//���ٵ�����
}

