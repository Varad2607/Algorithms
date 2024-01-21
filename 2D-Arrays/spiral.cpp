#include <iostream>
#include <vector>
using namespace std;

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

    int top,right,bottom,left;
    top=0;
    right=m-1;
    bottom=n-1;
    left=0;

    while(top<=bottom && left<=right){
        // Print top row
        for(int i=left; i<=right; i++){
            cout << arr[top][i] << " ";
        }
        top++;
        
        // Print right column
        for(int i=top; i<=bottom; i++){
            cout << arr[i][right] << " ";
        }
        right--;

        if(top <= bottom){
            // Print bottom row
            for(int i=right; i>=left; i--){
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if(left <= right){
            // Print left column
            for(int i=bottom; i>=top; i--){
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;  // Print the newline at the end of the entire spiral printing
    return 0;
}
