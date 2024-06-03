#include<iostream>
#include<vector>
#include <stack>
using namespace std;
class Solution{
private:
	void Dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
             if(!vis[it]){
             	Dfs(it,adj,st,vis);
             }
        }
        st.push(node);
	}
	void Dfs2(int node,vector<int>adjT[],vector<int>&vis){
		vis[node]=1;
		for(auto it:adjT[node]){
         if(!vis[it]){
         	Dfs2(it,adjT,vis);
            }
		}
	}
public:
	int Kosaraju(int V,vector<int>adj[]){
		vector<int>vis(V,0);
		stack<int>st;
		for(int i=0;i<V;i++){
			if(!vis[i]){
				Dfs(i,adj,st,vis);
			}
		}
		vector<int>adjT[V];
		for(int i=0;i<V;i++){
			for(auto it:adj[i]){
				adjT[it].push_back(i);
			}
		}
		fill(vis.begin(), vis.end(), 0);
		int scc=0;
		while(!st.empty()){
			int node=st.top();
			st.pop();
			if(!vis[node]){
				scc++;
				Dfs2(node,adjT,vis);
			}
		}
		return scc;
	}
};
int main(){
	int V,e;
	cin>>V>>e;
	vector<int>adj[V];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	Solution s;
	int ans=s.Kosaraju(V,adj);
	cout<<ans<<endl;
	return 0;
}