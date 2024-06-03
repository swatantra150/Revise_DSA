#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
class Solution{
public:
    vector<int>dijkstraSet(int v,vector<vector<pair<int, int>>> &adj,int s){
        set<pair<int,int>>st;
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        st.insert({0,s});
        while(!st.empty()){
             auto it = *(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgW=it.second;
                if(dis+edgW<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                      dist[adjNode]=dis+edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    Solution s;
    vector<int>ans=s.dijkstraSet(v,adj,0);
    for (auto it : ans) {
        if (it == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << it << endl;
        }
    }
    return 0;
}