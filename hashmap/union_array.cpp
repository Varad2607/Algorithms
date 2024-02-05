#include <iostream>
#include <map>
#include <vector>
using namespace std;

int union_sorted(int n,int k,vector<int> &arr, vector<int> &brr){
    map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;

    }
    for(int i=0;i<k;i++){
        mp[brr[i]]++;
    }
    cout<<"Total number of unique elements are "<<endl;
    return mp.size();

}

int main(){
    vector<int>arr;
    vector<int>brr;
    int n;
    cout<<"Enter the number of elements in array1: ";
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    int k;
    cout<<"Enter the number of elements in array2: ";
    cin>>k;
    int temp1;
    for(int i=0;i<n;i++){
        cin>>temp1;
        brr.push_back(temp1);
    }
    cout<<union_sorted(n,k,arr,brr);
}