#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int min_max_array(vector<int>&arr){
    int maximum;
    for(int i=1;i<arr.size();i++){
         maximum=max(arr[i-1],arr[i]);
    }
    return maximum;
}

int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int>arr;
    arr.reserve(n);
    cout<<"Enter the elements for the array: ";

    int nums;

    for(int i=0;i<n;i++){
        cin>>nums;
        arr.push_back(nums);
    }
    cout<<"Maximum_number: "<<min_max_array(arr);

}