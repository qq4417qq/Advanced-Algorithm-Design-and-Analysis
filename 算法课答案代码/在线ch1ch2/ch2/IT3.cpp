#include <stdio.h>
#include <vector>
using namespace std;
//�����ʾ
int n;
vector<int> item;				//����vector��������������У�����������ɣ�
int solve(int low, int high)	//��������������
{
	int ans=0;
    int ie = item[low];
    int je = item[high];
    while (low<high && ie!=je)	//���������������������������������
	{
        if (ie<je)				//ǰ����С��ǰ����һ��ת������
		{
			low++;
			ie += item[low];
            ++ans;
        }
        else					//������С��������һ��ת������
		{
			high--;
            je += item[high];
            ++ans;
        }
    }
    if (low>=high)				//������ֻ��һ��������Ϊ��
        return ans;
    else						//�����������������������ݹ鴦��������
	{
		low++;
		high--;
        return ans+solve(low,high);
	}
}
int main()
{
	int x;
	scanf("%d",&n);
    for (int i=0; i<n; i++)
	{
		scanf("%d",&x);
		item.push_back(x);
	}
	printf("%d\n",solve(0,n-1));
    return 0;
}
