#include <bits/stdc++.h> 
using namespace std;
int uniquePaths(int m, int n) {
     vector<vector<int>>dp(m,vector<int>(n,-1));
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
            if(i==0 and j==0){
            dp[0][0]=1;}
     else{
         int up=0;
         int left=0;
         if(i>0){up=dp[i-1][j];}
         if(j>0){left=dp[i][j-1];}
           dp[i][j]=up+left;
            }
    }
   }
   return dp[m-1][n-1];
   }

int main(){
    //vector<vector<int>>grid(m,vector<int>(n));
    int m=2;
    int n=2;
    int ans=uniquePaths(m,n);
    cout<<ans<<endl;
    return 0;
}