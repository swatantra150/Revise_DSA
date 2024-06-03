#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
public:
	int Prims(int v,vector<vector<pair<int, int>>>& adj){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>vis(v,0);
     pq.push({0,0});
     int sum=0;
     while(!pq.empty()){
     	auto it=pq.top();
     	pq.pop();
     	int node=it.second;
     	int wt=it.first;
     	if(vis[node]==1){
     		continue;
     	}
     	vis[node]=1;
     	sum+=wt;for(auto it:adj[node]){
     		int adjNode = it.second;
            int edw = it.first;
     		if(!vis[adjNode]){
     			pq.push({edw,adjNode});
     		}
     	}
     }
       return sum;
 }
};
int main(){
Solution sol;
    int v, e;
    cin>>v>>e;
    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  
    }

    int mst_weight = sol.Prims(v, adj);
    cout << "Weight of the Minimum Spanning Tree is: " << mst_weight << endl;

	return 0;
}