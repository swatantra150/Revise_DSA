#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int orangeRotten(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visi(n,vector<int>(m,0));;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visi[i][j]=2;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    visi[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visi[i][j]!=2 and grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
int main() {
    vector<vector<int>>grid={{0,1,2},{0,1,2},{2,1,1}};
    Solution s;
   int ans=s.orangeRotten(grid);
   cout<<ans<<endl;
   return 0;
}
