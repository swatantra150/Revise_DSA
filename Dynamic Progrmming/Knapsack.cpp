#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
public:
	int Knapsack(vector<int>wt,vector<int>val,int n,int maxWt){
		vector<vector<int>>dp(n,vector<int>(maxWt+1,0));
		for(int w=wt[0];w<=maxWt;w++){
			dp[0][w]=val[0];
		}
		for(int ind=1;ind<n;ind++){
			for(int w=0;w<=maxWt;w++){
               int notTake=0+dp[ind-1][w];
               int take=INT_MIN;
               if(wt[ind]<=w){
               	take=val[ind]+dp[ind-1][w-wt[ind]];
               }
               dp[ind][w]=max(take,notTake);
			}
		}
		return dp[n-1][maxWt];
	}
};
int main(){
	int n,maxWt;
	cin>>n>>maxWt;
	vector<int>wt(n);
	vector<int>val(n);
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	Solution s;
	int ans=s.Knapsack(wt,val,n,maxWt);
	cout<<ans<<endl;
	return 0;
}