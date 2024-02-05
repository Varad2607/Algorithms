#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    map<string,string> my_dict;
    my_dict.insert(pair<string,string> ("apple","sarfarchanda") );
    for(auto pair:my_dict){
        cout<<pair.first<<" "<<pair.second<<endl;

    }

}
