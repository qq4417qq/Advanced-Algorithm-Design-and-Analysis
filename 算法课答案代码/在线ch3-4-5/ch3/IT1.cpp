#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 200000
//�����ʾ
int a[MAXN];
int n,c;
int BinSearch(int low,int high,int x)	//��a[loww..high]�в���x���ֵĴ���
{
    while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)					//�ҵ�a[mid]=x:������Ϊx�ĸ���
		{
			int count=1,i;
			i=mid-1;
			while(i>=low && a[i]==x)	//��a[mid]�����x�Ĵ���
			{
				count++;
				i--;
			}
			i=mid+1;
			while(i<=high && a[i]==x)	//��a[mid]�ұ���x�Ĵ���
			{
				count++;
				i++;
			}
			return count;
		}
		else if(x>a[mid])				//x>a[mid]:���������в���
			low=mid+1;
		else							//x<a[mid]:���������в���
            high=mid-1;
    }
    return 0;							//û�в��ҷ���0
}
int main()
{
	scanf("%d%d", &n, &c);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);						//������a��������
	int ans=0;
	for(int j=0;j<n-1;j++)
		ans+=BinSearch(j+1,n-1,a[j]+c);
	printf("%d\n",ans);
	return 0;
}
