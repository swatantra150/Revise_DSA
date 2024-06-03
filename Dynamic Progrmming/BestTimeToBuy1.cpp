#include<iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int maxProfit(vector<int>prices){
		int mini=prices[0];
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-mini;
            maxprofit=max(profit,maxprofit);
            mini=min(mini,prices[i]);
        }
      return maxprofit;
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