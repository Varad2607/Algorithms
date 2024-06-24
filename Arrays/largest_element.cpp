#include <iostream>
#include <vector>
using namespace std;


void largest_element(vector<int> arr){
    int n=arr.size();
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }


    }
    cout<<max;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    largest_element(arr)

}