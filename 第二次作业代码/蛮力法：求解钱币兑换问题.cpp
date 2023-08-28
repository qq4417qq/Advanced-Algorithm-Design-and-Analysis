#include<iostream>
using namespace std;
int huihuan(int n){
	int sum = 0;
	for (int i = 0; i <= n/5; i++){//5分钱的兑换可能
		for (int j = 0; j <= n/2; j++)//2分前的兑换可能
		{
			for (int k = 0; k <= n; k++){//1分钱的兑换可能
				if(k*1+j*2+i*5 == n){
					sum++;//记录兑换可能
					cout<<i<<j<<k<<endl;//输出兑换组合
				}
			}
		}
	}
	return sum;
}
int main(){
	int n=10;
	// cin>>n;//输入需要兑换的钱币
	cout<<huihuan(n)<<endl;
	system("pause");
	return 0;
}