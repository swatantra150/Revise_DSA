#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution{
public:
	int shortestPath(vector<vector<int>>&grid,pair<int,int>src,pair<int,int>dest){
		queue<pair<int,pair<int,int>>>q;
		int n=grid.size();
		int m=grid[0].size();
		vector<vector<int>>dist(n,vector<int>(m,1e9));
		dist[src.first][src.second]=0;
		q.push({0,{src.first,src.second}});
		vector<int>dr={-1,0,1,0};
			vector<int>dc={0,1,0,-1};
		while(!q.empty()){
			auto it=q.front();
			q.pop();
			int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
			for(int i=0;i<4;i++){
				int newr=r+dr[i];
				int newc=c+dc[i];
				if(newr>=0 and newr<n and newc>=0 and newc<m and grid[newr][newc]==1 and dis+1<dist[newr][newc]){
					dist[newr][newc]=1+dis;
					if(newr==dest.first and newc==dest.second){
						return dis+1;
					}
					q.push({1+dis,{newr,newc}});
				}
			}
		}
		return -1;
	} 
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>grid(n,vector<int>(m));
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int srcX, srcY, destX, destY;
    cin >> srcX >> srcY >> destX >> destY;
     Solution s;
    int result = s.shortestPath(grid, {srcX, srcY}, {destX, destY});
    
    if (result == -1) {
        cout << "No path found" << endl;
    } else {
        cout << "Shortest path length: " << result << endl;
    }
    
	return 0;
}