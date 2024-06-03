#include<iostream>
#include<vector>
using namespace std;
class BestTimeToBuy2
{
public:
	int maxProfit(vector<int>prices){
		int n=prices.size();
		vector<vector<int>>dp(n+1,vector<int>(2,0));
		dp[n][0]=dp[n][1]=0;
		for(int ind=n-1;ind>=0;ind--){
			for(int buy=0;buy<=1;buy++){
				if(buy){
				dp[ind][buy]=max(dp[ind+1][0]-prices[ind],dp[ind+1][1]);
			   }else{
			   	dp[ind][buy]=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
			   }
			}
		}
		return dp[0][1];
	}
	
};
int main(){
	int m;
	cin>>m;
  vector<int>prices(m,0);
  for(int i=0;i<m;i++){
  	cin>>prices[i];
  }
  BestTimeToBuy2 s;
  int ans=s.maxProfit(prices);
  cout<<ans<<endl;
	return 0;
}