#include<iostream>
#include<queue>
#include<vector>
 using namespace std;
 vector<int>topo(int V,vector<int>adj[]){
 	vector<int>indegree(V,0);
 	for(int i=0;i<V;i++){
         for(auto it:adj[i]){
         	indegree[it]++;
         }
     }
    queue<int>q;
    vector<int>topo;
   for(int i=0;i<V;i++){
   	if(indegree[i]==0){
   			q.push(i);
   		}
   }
   while(!q.empty()){
   	int node=q.front();
   	q.pop();
   	topo.push_back(node);
   	for(auto it:adj[node]){
   		indegree[it]--;
   		if(indegree[it]==0){
   			q.push(it);
   		}
   	}
   }
   return topo;
}
 int main(){
 	int V,e;
 	cin>>V>>e;
 	vector<int>adj[V+1];
  for(int i=0;i<e;i++){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
  }
  vector<int>ans=topo(V,adj);
  for(int node:ans){
  	cout<<node<<" ";
  }
  cout<<endl;
 	return 0;
 }