#include<iostream>
using namespace std;
int huihuan(int n){
	int sum = 0;
	for (int i = 0; i <= n/5; i++){//5��Ǯ�Ķһ�����
		for (int j = 0; j <= n/2; j++)//2��ǰ�Ķһ�����
		{
			for (int k = 0; k <= n; k++){//1��Ǯ�Ķһ�����
				if(k*1+j*2+i*5 == n){
					sum++;//��¼�һ�����
					cout<<i<<j<<k<<endl;//����һ����
				}
			}
		}
	}
	return sum;
}
int main(){
	int n=10;
	// cin>>n;//������Ҫ�һ���Ǯ��
	cout<<huihuan(n)<<endl;
	system("pause");
	return 0;
}