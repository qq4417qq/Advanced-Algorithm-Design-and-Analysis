//���������㷨
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
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{	i=Partition(a,s,t);
		QuickSort(a,s,i-1);		//���������еݹ�����
		QuickSort(a,i+1,t);		//���������еݹ�����
	}
}
