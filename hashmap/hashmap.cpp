#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[v[i]]++;
    }


     


    return 0;
}