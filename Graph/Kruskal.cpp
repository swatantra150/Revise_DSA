#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
	vector<int>parent,rank;
public:
	DisjointSet(int n){
		parent.resize(n+1,0);
		rank.resize(n+1,0);
		for(int i=0;i<n;i++){
			parent[i]=i;
		}
	}
	int findUpar(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findUpar(parent[node]);
	}
	void unionByRank(int u,int v){
		int ulti_parU=findUpar(u);
		int ulti_parV=findUpar(v);
		if(ulti_parU==ulti_parV) return;
		if(rank[ulti_parU]<rank[ulti_parV]){
			parent[ulti_parU]=ulti_parV;
		}
		else if(rank[ulti_parV]<rank[ulti_parU]){
			parent[ulti_parV]=ulti_parU;
		}
		else{
			parent[ulti_parV]=ulti_parU;
			 rank[ulti_parU]++;
		}
	}
};
class Solution{
public:
	int spanningTree(int V,vector<vector<int>>adj[]){
		vector<pair<int,pair<int,int>>>edge;
		for(int i=0;i<V;i++){
			for(auto it:adj[i]){
                 int adjNode=it[0];
                 int wt=it[1];
                 int node=i;
                 edge.push_back({wt,{node,adjNode}});
			}
		}
		DisjointSet ds(V);
		sort(edge.begin(),edge.end());
		int mst=0;
		for(auto it:edge){
			int wt=it.first;
			int node=it.second.first;
			int adjNode=it.second.second;
			if(ds.findUpar(node)!=ds.findUpar(adjNode)){
                mst+=wt;
                ds.unionByRank(node,adjNode);
			}
		}
		return mst;
	}
};
int main(){
	int V, E;
    cin>>V>>E;
   vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }

    Solution sol;
    int mstWeight = sol.spanningTree(V, adj);
    cout << "Weight of the Minimum Spanning Tree is: " << mstWeight << endl;
	return 0;
}