#include<iostream>
#include<vector>
using namespace std;
class Solution{

public:
	bool isMatched(string s1,string s2){
		int m=s1.size();
		int n=s2.size();
		vector<vector<int>>dp(m+1,vector<int>(n+1,0));
		dp[0][0]=1;
		for(int j=1;j<=m;j++){
			dp[0][j]=0;
		}
		for (int i = 1; i <= m; i++) {
            dp[i][0] = (s1[i - 1] == '*') ? dp[i - 1][0] : 0;
        }
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
					dp[i][j]=dp[i-1][j-1];
				}
				else if(s1[i-1]=='*'){
					dp[i][j]=dp[i-1][j] || dp[i][j-1];
				}
				dp[i][j]=0;
			}
		}
		return dp[m][n];
	}
};
int main(){
	int m,n;
	cin>>m>>n;
	string s1(m,'$');
	string s2(n,'$');
	cin>>s1>>s2;
	Solution s;
	bool ans=s.isMatched(s1,s2);
	cout<<ans<<endl;
	return 0;
}