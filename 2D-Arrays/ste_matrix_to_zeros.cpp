#include <iostream>
#include <vector>
using namespace std;

// void set_matrix(int n,int m,vector<vector<int>>arr){
//     vector<bool> zerorows(n,false);
//     vector<bool> zerocols(m,false);

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==0){
//                 zerorows[i]=true;
//                 zerocols[j]=false;
//             }

//         }
//     }

//      // Second pass: set rows to zero
//     for(int i = 0; i < n; i++) {
//         if(zerorows[i]) {
//             for(int j = 0; j < m; j++) {
//                 arr[i][j] = 0;
//             }
//         }
//     }

//     // Third pass: set columns to zero
//     for(int j = 0; j < m; j++) {
//         if(zerocols[j]) {
//             for(int i = 0; i < n; i++) {
//                 arr[i][j] = 0;
//             }
//         }
//     }
// }

void set_matrix(int m, int n, vector<vector<int>>& arr) {
    vector<bool> zeroRows(n, false); // To track rows to be zeroed
    vector<bool> zeroCols(m, false); // To track columns to be zeroed

    // First pass: identify rows and columns that need to be zeroed
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Second pass: set rows to zero
    for(int i = 0; i < n; i++) {
        if(zeroRows[i]) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // Third pass: set columns to zero
    for(int j = 0; j < m; j++) {
        if(zeroCols[j]) {
            for(int i = 0; i < n; i++) {
                arr[i][j] = 0;
            }
        }
    }
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

    set_matrix(m,n,arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";

        }
    }
}