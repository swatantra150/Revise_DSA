#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    public:
    int numberOfisland(vector<vector<int>>&grid){
         int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col]==0 and grid[row][col]==1){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};
int main() {
    vector<vector<int>>grid={{0,1},{1,0},{1,1},{1,0}};
    Solution s;
   int ans=s.numberOfisland(grid);
   cout<<ans;
    return 0;
}
