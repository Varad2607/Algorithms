#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    vector<int> array;
    int n,temp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        array.push_back(temp);

    }
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[array[i]]++;

    }
    unordered_map<int,int> ::iterator it;
    for(it =mp.begin(); it !=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}