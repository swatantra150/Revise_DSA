#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
public:
	int cuttingRod(vector<int>price,int n){
		vector<vector<int>>dp(n,vector<int>(n+1,0));
         for(int i=0;i<=n;i++){
         	dp[0][i]=i*price[0];
         }
         for(int ind=1;ind<n;ind++){
         	for(int N=0;N<=n;N++){
                   int not_take=0+dp[ind-1][N];
                   int take=INT_MIN;
                   int rod_length=ind+1;
                   if(rod_length<=N){
                         take=price[ind]+dp[ind][N-rod_length];
                   }
                   dp[ind][N]=max(take,not_take);
         	}
         }
         // for(int i=0;i<n;i++){
         // 	for(int j=0;j<=n;j++){
         // 		cout<<dp[i][j]<<" ";
         // 	}
         // 	cout<<endl;
         // }
         
         return dp[n-1][n];
	}
};
int main(){
	int n;
	cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++){
    	cin>>price[i];
    }
    Solution s;
    int ans=s.cuttingRod(price,n);
    cout<<ans<<endl;
	return 0;
}