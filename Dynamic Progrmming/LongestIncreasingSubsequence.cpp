#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int LIS(vector<int>&nums,int ind,int prev_ind,int n){
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        int l=0+LIS(nums,ind+1,prev_ind,n);
        if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
            l=max(l,1+LIS(nums,ind+1,ind,n));
        }
        return(dp[ind][prev_ind+1]=l);
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        int prev_ind=-1;
        int ans=LIS(nums,ind,prev_ind,n);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int>nums{10,9,2,5,3,7,101,18};
    int reans=s.lengthOfLIS(nums);
    cout<<reans<<endl;
    return 0;
}
