#include <iostream>
#include <vector>
using namespace std;

class Sorted{
    public:

    vector <int> Sorted_array(int n,vector<int> &arr){
        

    }

};

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    vector<int> arr_2;

    Sorted Square;
    arr_2=Square.Sorted_array(n,arr);
    for (auto it:arr_2){
        cout<<"";
    }



}