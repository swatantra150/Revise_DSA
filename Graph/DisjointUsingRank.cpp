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
int main(){
	
	DisjointSet ds(7);
	 ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
     if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "3 and 7 are in the same set." << endl;
    } else {
        cout << "3 and 7 are in different sets." << endl;
    }


	return 0;
}