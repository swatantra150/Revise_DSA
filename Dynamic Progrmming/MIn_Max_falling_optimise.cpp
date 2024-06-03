#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Soltuion{
public:
	int f(vector<vector<int>>&matrix){
		int n=matrix.size();
		int m=matrix[0].size();
		vector<int>prev(m,0);
		vector<int>curr(m,0);
		//Base Case
       for(int j=0;j<m;j++){
       prev[j]=matrix[0][j];
       }
      for(int i=1;i<n;i++){
      	for(int j=0;j<m;j++){
      		int u=matrix[i][j]+prev[j];
              int ld=matrix[i][j];
              if(j-1>=0){
              	ld+=prev[j-1];
              }else{
              	ld=-1e8;
              }
              int rd=matrix[i][j];
              if(j+1<m){
              	rd+=prev[j+1];
              }else{
              	rd=-1e8;
              }
              curr[j]=max(u,max(ld,rd));
      	}
      	prev=curr;
      }
      int maxi=-1e8;
      for(int j=0;j<m;j++){
      	maxi=max(maxi,prev[j]);
      }
      return maxi;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>matrix(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}
	Soltuion s;
	int ans=s.f(matrix);
	cout<<ans;
	return 0;
}