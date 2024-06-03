#include <bits/stdc++.h> 
#include<vector>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
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
    return dp[n-1][k-1];
}
int main(){
    vector<int>arr{4,3,2,1};
    int k=5;
    int n=arr.size();
    bool ans=subsetSumToK(n,k,arr);
    cout<<ans<<endl;
    return 0;
}