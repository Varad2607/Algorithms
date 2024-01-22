#include <iostream>
#include <vector>
using namespace std;


void search_matrix(int n,int m,int k,vector<vector<int>>arr){
    int i=0;
    int j=m-1;
    while(i<n && j>=0){
        if(arr[i][j]==k){
            cout<<"Element found at"<<" "<<i<<" "<<j;
            return;
        }
        else if(arr[i][j]>k){
            j--;
        }
        else{
            i++;
        }


    }
    cout<<"Not found";
     

}

int main(){
    int n,m;
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of cols: ";
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int k;
    cout<<"Enter the element to search: ";
    cin>>k;
    search_matrix(n,m,k,arr);

}