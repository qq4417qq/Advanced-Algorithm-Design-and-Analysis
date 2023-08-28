#include<iostream>
using namespace std;

int hums(int n){
    int num=1;
    if(n==1)
        return 1;
    if(n>1){
        for (int i = 1; i < n/2+1; i++){
            num += hums(i);
        }
        return num;
    }
}
int main()
{
	int n;
    cin>>n;
    cout<<hums(n)<<endl;
    system("pause");
}
