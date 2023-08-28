#include<iostream>
// #include <unordered_map>
// #include<string>
#include<vector>
// #include <queue>
// #include<stdio.h>
// #include<memory.h>
// #include<map>
#include<algorithm>
using namespace std;

// void printfun(vector<vector<char>> mat){
//     for (vector<vector<char>>::iterator it = mat.begin(); it != mat.end(); it++)
//     {
//         for(vector<char>::iterator item = (*it).begin();item != (*it).end();item
//         ++){
//             cout<<*item;
//         }
//         cout<<endl;
// }
// }
bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1; i<= num/2; i++){
            if(num% i==0) sum+= i;
        }
        return sum==num;
}
int qiujie(vector<int> &nums,int p,int n,int j,int c){
    int count = 0;
    for (int i = p; i < n; i++)
    {
    j += nums[i];
    c *= nums[i];
    if(j>c){
        count += qiujie(nums,i+1,n,j,c)+1;
    }
    else if (nums[i] == 1)
    {
        count += qiujie(nums,i+1,n,j,c);
    }
    else{
        break;
    }
    j -= nums[i];
    c /= nums[i];
    while(i<n-1&&nums[i] == nums[i+1])
    {
        i++;
    }
    }
    return count;
}
int main(){
    int n,j = 0,c = 0;
    int p = 0;
    cin>>n;
    vector<int> nums;
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    cout<<qiujie(nums,p,n,j,1);
    system("pause");
    return 0;    
}
