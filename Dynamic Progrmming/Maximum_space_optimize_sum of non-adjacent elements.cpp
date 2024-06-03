#include <bits/stdc++.h> 
using namespace std;
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev1= nums[0];
    int prev2=0;
    
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=prev2;
        }
        int not_take=prev1;
        int curr=max(take,not_take);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    // Write your code here.
}
int main(){
    vector<int>nums={1,2,4};
    int ans=maximumNonAdjacentSum(nums);
    cout<<ans<<endl;
    return 0;
}