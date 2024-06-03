#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
public:
	vector<int>bellmanFord(int V,vector<vector<int>>&edges,int s){
		vector<int>dist(V,1e8);
		dist[s]=0;
		for(int i=0;i<V-1;i++){
			for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 and dist[u]+wt<dist[v]){
                	dist[v]=dist[u]+wt;
                }
			}
		}
       for(auto it:edges){
       	        int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 and dist[u]+wt<dist[v]){
                	return {-1};
                }
       }
       return dist;
	}
};
int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<int>>edges;
	for(int i=0;i<e;i++){
           int u,v,wt;
           cin>>u>>v>>wt;
           edges.push_back({u,v,wt});
               
	}
	Solution s;
	vector<int>ans=s.bellmanFord(v,edges,0);
    if(ans.size()==1 and ans[0]==-1){
    	cout<<"-ve cycle"<<endl;
    }else{
    	for(auto it:ans){
    		if(ans[it]==1e8){
    			cout<<"INF"<<endl;
    		}else{
    			cout<<ans[it]<<endl;
    		}
    	}
    	cout<<endl;
    }
	return 0;
}