#include <bits/stdc++.h> 
using namespace std;
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]= nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=dp[i-2];
        }
        int not_take=0+dp[i-1];
        dp[i]=max(take,not_take);
    }
    return dp[n-1];
    // Write your code here.
}
int main(){
    vector<int>nums={1,2,4};
    int ans=maximumNonAdjacentSum(nums);
    cout<<ans<<endl;
    return 0;
}