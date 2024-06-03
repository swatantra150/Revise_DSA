#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
class Solution{
private:
	stack<int> toposort(int node,vector<pair<int,int>> adj[],vector<int>&vis,stack<int>&st){
		vis[node]=1;
		for(auto it:adj[node]){
			int v=it.first;
             if(!vis[v]){
             	toposort(v,adj,vis,st);
             }
		}
		st.push(node);
		return st;
	}
public:
	vector<int> shortestPath(int N,int M,vector<vector<int>>&edges){
		vector<pair<int,int>>adj[N];
		for(int i=0;i<M;i++){
			int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
		}
		vector<int>vis(N,0);
		stack<int>st;
		for(int i=0;i<N;i++){
			if(!vis[i]){
				toposort(i,adj,vis,st);
			}
		}
		//Realx the edges
	    vector<int> dist(N, INT_MAX);
		dist[0]=0;
		while(!st.empty()){
			int node=st.top();
			st.pop();
			if (dist[node] != INT_MAX){
            for(auto it:adj[node]){
            	int v=it.first;
            	int wt=it.second;
            	if(dist[node]+wt<dist[v]){
            		dist[v]=dist[node]+wt;
            	}
            }
		}
	}
         return dist;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	Solution s;
	vector<vector<int>>edges(m);
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges[i].push_back(u);
		edges[i].push_back(v);
		edges[i].push_back(wt);
	}
	vector<int>ans=s.shortestPath(n,m,edges);
	for(auto it:ans){
		if(it==INT_MAX){
			cout<<"INF";
		}else{
			cout<<it;
		}
		cout<<endl;
	}
	return 0;
}