#include<iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int editDist(string s1,string s2){
		int m=s1.size();
		int n=s2.size();
		vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
		for(int i=0;i<=m;i++){
			dp[i][0]=i;
		}
		for(int j=1;j<=n;j++){
			dp[0][j]=j;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(s1[i-1]==s2[j-1]){
					dp[i][j]=0+dp[i-1][j-1];
				}else{
					int a=1+dp[i-1][j-1];//Replace
					int b=1+dp[i][j-1];//insert
					int c=1+dp[i-1][j];//delete
                  dp[i][j]=min(a,min(b,c));
				}
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
	int ans=s.editDist(s1,s2);
	cout<<ans<<endl;
	return 0;
}