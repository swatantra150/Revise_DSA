#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Solution{
public:
	vector<int>dijsktra(int v, vector<vector<pair<int, int>>>& adj,int S){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		vector<int>dist(v,INT_MAX);
		dist[S]=0;
		pq.push({0,S});

		while(!pq.empty()){
			int dis=pq.top().first;
			int node=pq.top().second;
			pq.pop();
			for(auto it:adj[node]){
				int edgeWeight=it.second;
				int adjNode=it.first;
				if(dis+edgeWeight<dist[adjNode]){
					dist[adjNode]=dis+edgeWeight;
					pq.push({dist[adjNode],adjNode});
				}
			}
		}
        return dist;
	}
};
int main(){
	int v,e;
 	cin>>v>>e;
 	  vector<vector<pair<int, int>>> adj(v);
  for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Uncomment this line if the graph is undirected
    }
  Solution s;
 vector<int> ans = s.dijsktra(v, adj, 0);
    for (auto it : ans) {
        if (it == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << it << endl;
        }
    }
	return 0;
}