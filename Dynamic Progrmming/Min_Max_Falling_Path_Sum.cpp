#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Soltuion{
public:
	int f(int i,int j,vector<vector<int>>&matrix){
		int n=matrix.size();
		int m=matrix[0].size();
		vector<vector<int>>dp(n,vector<int>(m,0));
		//Base Case
		if(j<0 and j>=m){
			return -1e8;
		}
       for(int j=0;j<m;j++){
       	dp[0][j]=matrix[0][j];
       }
      for(int i=1;i<n;i++){
      	for(int j=0;j<m;j++){
      		int u=matrix[i][j]+dp[i-1][j];
              int ld=matrix[i][j];
              if(j-1>=0){
              	ld+=dp[i-1][j-1];
              }else{
              	ld=-1e8;
              }
              int rd=matrix[i][j];
              if(j+1<m){
              	rd+=dp[i-1][j+1];
              }else{
              	rd=-1e8;
              }
              dp[i][j]=max(u,max(ld,rd));
      	}
      }
      int maxi=-1e8;
      for(int j=0;j<m;j++){
      	maxi=max(maxi,dp[n-1][j]);
      }
      return maxi;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>matrix(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}
	Soltuion s;
	int ans=s.f(1,0,matrix);
	cout<<ans;
	return 0;
}