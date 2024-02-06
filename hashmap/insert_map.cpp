#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    map<string,int> fruitprices={{"apple", 50},{"bananna", 30},{"grapes", 100}};

    //Method 1 to traverse over map
    //Pair here says that [key,value], so use pair to loop over dictionary
    for(const auto& pair: fruitprices){
        cout<<pair.first<<" has price"<<pair.second<<endl;
    }
    //If using [key,value] then use cout<<key<<"has price"<<value<<endl;

    //Method 2 to traverse over map
    map<string,int> ::iterator it;
    for(it=fruitprices.begin();it!=fruitprices.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

   
}
