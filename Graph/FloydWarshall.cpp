#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution{
public:
	vector<vector<int>>Floyd(vector<vector<int>>matrix){
		int n=matrix.size();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]==-1){
					matrix[i][j]=1e9;
				}
				if(i==j){
					matrix[i][j]=0;
				}
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]==1e9){
					matrix[i][j]=-1;
				}
			}
		}
		return matrix;
	}
};
int main(){
	int n;
	cin>>n;
	vector<vector<int>>matrix(n,vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	Solution s;
	vector<vector<int>>ans=s.Floyd(matrix);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	return 0;
}