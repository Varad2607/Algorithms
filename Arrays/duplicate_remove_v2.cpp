#include <iostream>
#include <vector>
using namespace std;


int remove_element(vector<int>&arr,int val){
    int i,j;
    i=0;
    j=0;
    int counter=0;
    while(i<arr.size()){
        if(arr[i]!=val){
            counter++;
            swap(arr[i],arr[j]);
            j++;
        }
        i++;
    }
    return  counter;
}

int main(){
    int n,nums;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>nums;
        arr.push_back(nums);

  
    }
    int val;
    cin>>val;
    cout<<"Final ans is"<<remove_element(arr,val);





}