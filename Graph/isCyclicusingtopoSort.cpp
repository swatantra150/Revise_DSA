#include<iostream>
#include<queue>
#include<vector>
 using namespace std;
 bool isCyclic(int V,vector<int>adj[]){
 	vector<int>indegree(V,0);
 	for(int i=0;i<V;i++){
         for(auto it:adj[i]){
         	indegree[it]++;
         }
     }
    queue<int>q;
   int cnt=0;
   for(int i=0;i<V;i++){
   	if(indegree[i]==0){
   			q.push(i);
   		}
   }
   while(!q.empty()){
   	int node=q.front();
   	q.pop();
   	cnt++;
   	for(auto it:adj[node]){
   		indegree[it]--;
   		if(indegree[it]==0){
   			q.push(it);
   		}
   	}
   }
   if(cnt==V){
      return false;
   }else{
      return true;
   }
   
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
   if(isCyclic(V,adj)){
      cout<<"True"<<endl;
   }else{
      cout<<"False"<<endl;
   }
  cout<<endl;
 	return 0;
 }