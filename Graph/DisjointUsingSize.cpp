#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
	vector<int>parent,size;
public:
	DisjointSet(int n){
		parent.resize(n+1,0);
		size.resize(n+1,0);
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
	void unionBySize(int u,int v){
		int ulti_parU=findUpar(u);
		int ulti_parV=findUpar(v);
		if(ulti_parU==ulti_parV) return;
		if(size[ulti_parU]<size[ulti_parV]){
			parent[ulti_parU]=ulti_parV;
			size[ulti_parV]=+size[ulti_parU];
		}
		else if(size[ulti_parV]<size[ulti_parU]){
			parent[ulti_parV]=ulti_parU;
			size[ulti_parU]=+size[ulti_parV];
		}
		else{
			parent[ulti_parV]=ulti_parU;
			 size[ulti_parU]++;
		}
	}
};
int main(){
	
	DisjointSet ds(7);
	 ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
     if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "3 and 7 are in the same set." << endl;
    } else {
        cout << "3 and 7 are in different sets." << endl;
    }


	return 0;
}