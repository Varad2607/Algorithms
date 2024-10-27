#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int diagonal_sum(const vector<vector<int>>& arr){

    int n=arr.size();
    int primary_diagonal=0;
    int secondary_diagonal=0;

    for(int i=0;i<n;i++){
        primary_diagonal+=arr[i][i];
        secondary_diagonal+=arr[i][n-1-i];
        
        
            }





    return abs(secondary_diagonal-primary_diagonal);
}



int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }

    }

    cout<<diagonal_sum(arr)<<endl;

}






