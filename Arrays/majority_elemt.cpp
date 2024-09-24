#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int majority_element(vector<int>&arr ){
    int val=arr.size()/2;
    unordered_map<int,int> count;
    for(int num:arr){
        count[num]++;
        if(count[num]>val){
            return num;
        }
    }
    return -1;
    

}
int main(){
    int n,num;
    cout<<"Enter the number of elements you: ";
    cin>>n;

    vector<int>arr;

    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    cout<<majority_element(arr);



}