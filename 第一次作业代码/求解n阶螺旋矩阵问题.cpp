#include<iostream>
using namespace std;

void func(int n)
{
	int a[n][n];
	int x = 0,y = -1;              //x,y��ʾ��ǰ����Ҫ��ֵ��λ�� 
	int x_add = 0, y_add = 1;      //ÿ�θ�ֵʱ,x��y������ 
	int num = n,num_add = n;       //num:�ƶ��������仯��ת���,num_add:ÿ��ת��ʱnum������ 
	for(int i=1;i<=n*n;i++)
	{
		x += x_add;
		y += y_add;
		a[x][y] = i;
		
		if(i == num)        //�ƶ�������ת�� 
		{
			if(y_add == 1 || y_add == -1)         //��������� 
			{
				x_add = y_add;
				y_add = 0;
				num_add--;
				num += num_add;
			}
			else                                  //�������� 
			{
				y_add = -x_add;
				x_add = 0;
				num += num_add;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		func(n);
		cin>>n;
	} 
}
