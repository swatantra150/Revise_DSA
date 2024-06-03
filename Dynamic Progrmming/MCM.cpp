#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <bits/stdc++.h> 
using namespace std;

int f(int i,int j,vector<int>&arr){
    if(i==j){
        return 0;
    }
    int miniStep=INT_MAX;
    for(int k=i;k<j;k++){
        int step=f(i,k,arr)+f(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
        miniStep=min(miniStep,step);
    }
    return miniStep;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1,arr.size()-1,arr);
}
int main() {
    vector<int>arr{10,20,30,40};
    int ans=matrixMultiplication(arr,arr.size());
    cout<<ans<<endl;
    return 0;
}
