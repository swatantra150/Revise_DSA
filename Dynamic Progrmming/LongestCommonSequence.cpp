#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
	int LCS(string s1,string s2){
		int n=s1.size();
		int m=s2.size();
		vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       for(int i=0;i<=n;i++){
       	dp[i][0]=0;
       }
       for(int j=0;j<=m;j++){
       	dp[0][j]=0;
       }
       for(int i=1;i<=n;i++){
       	for(int j=1;j<=m;j++){
       		if(s1[i-1]==s2[j-1]){
       			dp[i][j]=1+dp[i-1][j-1];
       		}
       		else{
       			int a=dp[i-1][j];
       			int b=dp[i][j-1];
       			dp[i][j]=max(a,b);
       		}
       	}
       }
          int len=dp[n][m];
        string s(len, '$');
       int i=n;
       int j=m;
       while(i>0 and j>0){
       	if(s1[i-1]==s2[j-1]){
       		s[len]=s1[i-1];
       		len--;
       		i--;
       		j--;
       	}
       	else if(dp[i-1][j]>dp[i][j-1]){
           i--;
         }
           else{
       	j--;
          }
       }
       cout<<s<<endl;

       return dp[n][m];
	}
	// string PrintLcs(string s1,string s2){
	// 	int n=s1.size();
	// 	int m=s2.size();
	// 	   int len =dp[n][m];
    //    string s;
    //    for(int i=0;i<len;i++){
    //    	s[i]='$';
    //    }
    //    int i=n;
    //    int j=m;
    //    while(i>0 or j>0){
    //    	if(s1[i-1]==s2[j-1]){
    //    		s[len]=s1[i-1];
    //    		len--;
    //    		i--;
    //    		j--;
    //    	}
    //    	else if(dp[i-1][j]>dp[i][j-1]){
    //        i--;
    //      }
    //        else{
    //    	j--;
    //       }
    //    }
    //    cout<<endl;
	// }
};
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	Solution s;
	int ans=s.LCS(s1,s2);
	cout<<ans<<endl;
	return 0;
}