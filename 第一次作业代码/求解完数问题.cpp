#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkperfectNumber(int num){
    int sum = 0;
    for(int i=1;i<=num/2;i++){
        if(num%i == 0) sum+=i;
    }
    return sum==num;}
int main()
{
	vector<int> nums;
    int n,num1,num2;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num1;cin>>num2;
        int count = 0;
        for(int j = num1;j<=num2;j++){
            if(checkperfectNumber(j)) count++;
        }
        nums.push_back(count);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
    system("pause");
    return 0;
}
