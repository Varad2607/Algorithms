#include <iostream>
#include <map>
#include <vector>
using namespace std;



int array_subset(int n,int k, vector<int> const &array_1, vector<int> const &array_2 ){
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[array_1[i]];
    }
    for(auto i:array_2){
        if(mp.find(i)==mp.end()){
            return 0;
        }
    }
    cout<<"Array_2 is a subset of array_1"<<endl;
    return 1;

}




int main(){
    int n,k;
    cout<<"Enter the number of elements for array-1: "<<endl;
    cin>>n; 
    cout<<"Enter the elments for array_1: "<<endl;
    vector<int>array_1;
    int temp,temp_1;
    for(int i=0;i<n;i++){
        cin>>temp;
        array_1.push_back(temp);

    }
    cout<<"Enter number of elements for array-2: "<<endl;
    cin>>k;
    cout<<"Enter the elments for array_2: "<<endl;
    vector<int>array_2;
    for(int i=0;i<k;i++){
        cin>>temp_1;
        array_2.push_back(temp);

    }
    cout<<array_subset(n,k,array_1,array_2);

    
    
    
    
    
    


}