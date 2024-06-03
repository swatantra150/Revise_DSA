#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int maxProfit(vector<int>prices){
		int n=prices.size();
		int cap=2;
		vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
		// for(int ind=0;ind<=n;ind++){
		// 	for(int buy=0;buy<=1;buy++){
		// 		dp[ind][buy][0]=0;
		// 	}
		// }
		// for(int buy=0;buy<=1;buy++){
		// 	for(int cap=0;cap<=2;cap++){
		// 		dp[0][buy][cap]=0;
		// 	}
		// }
		for(int ind=n-1;ind>=0;ind--){
			for(int buy=0;buy<=1;buy++){
				for(int cap=1;cap<=2;cap++){
					if(buy){
						dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
					}else{
						dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
					}
				}
			}
		}
		return dp[0][1][2];
	}
};
int main(){
	int m;
	cin>>m;
  vector<int>prices(m,0);
  for(int i=0;i<m;i++){
  	cin>>prices[i];
  }
 Solution s;
  int ans=s.maxProfit(prices);
  cout<<ans<<endl;
	return 0;
}