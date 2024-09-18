#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int largest_element(vector<int>&arr){
    int smallest=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>smallest){
            smallest=arr[i];
        }
    }
    return smallest;

}


int main(){
 vector<int>arr;
 int n,num;

 cout<<"Enter the number of the elements";

 cin>>n;
 for(int i=0;i<n;i++) {
    cin>>num;
    arr.push_back(num);
 }
 int result=largest_element(arr);

 cout<<"The largest element in the array is "<<result<<endl;
 return 0;
}