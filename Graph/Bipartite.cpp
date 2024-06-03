#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution{
    private:
    bool check(int start,int v,vector<vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    public:
    bool isBipartite(int v,vector<vector<int>>adj){
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(check(i,v,adj,color)==false){
                    return false;
                }
            }
        }
        return true;  
    }
};
int main() {
    int v = 4; // Number of vertices
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution s;
    bool ans=s.isBipartite(v,adj);
    cout<<ans<<endl;
    return 0;
}
