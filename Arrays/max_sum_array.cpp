#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,num;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);

    }
    // We need to decide start and end of the array every time

    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" "<<endl;
        }
    }
}