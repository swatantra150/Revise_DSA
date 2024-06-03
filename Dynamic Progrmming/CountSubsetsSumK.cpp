#include <iostream>
#include<vector>
using namespace std;
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(k>=arr[0]){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<=n-1;i++){
        for(int sum=0;sum<=k;sum++){
            int not_pick=dp[i-1][sum];
            int pick=0;
           if(sum>=arr[i]) {
               pick=dp[i-1][sum-arr[i]];
               }
           dp[i][sum]=not_pick+pick;
        }
    }
    return dp[n-1][k];
}

int main() {
    vector<int>arr{1,1,4,5};
    int k=5;
    int ans=findWays(arr,k);
    cout<<ans<<endl;
    return 0; 
}
 