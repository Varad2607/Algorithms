#include <iostream>
#include <vector>
using namespace std;



void move_zeros(int n,int arr[]){
    //At this index the non zero value should be there
    int non_zero=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[non_zero]);
            non_zero+=1;
        }


        }
    }


int main(){
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    move_zeros(n,arr);
    cout<<"Moving all zeros to end: "<<" "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
  
    return 0;

}