#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    int k=totalSum;
     vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;//wha pe true value hai jha pe (target=0) hai
    }
    if(k>=arr[0]){
    dp[0][arr[0]]=true;}
    for(int i=1;i<=n-1;i++){
        for(int target=1;target<=k;target++){
            bool not_take=dp[i-1][target];
            bool take=false;
        if(arr[i]<=target){
            take=dp[i-1][target-arr[i]];
           }
           dp[i][target]=take||not_take;
        }
    }
    int mini=1e9;
    for(int s1=0;s1<=k/2;s1++){
        if(dp[n-1][s1]==true){
            mini=min(mini,abs((totalSum-s1)-s1));
        }
    }
    return mini;
}

int main() {
    
    vector<int>arr{1,2,3,4};
    int n=arr.size();
    int ans=minSubsetSumDifference(arr,n);
    cout<<ans<<endl;
    return 0;
}
