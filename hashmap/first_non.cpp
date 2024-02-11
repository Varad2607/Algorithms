#include <iostream>
#include <map>
#include <string>
using namespace std;

void non_repeat_charc(string &s){
    int n=s.size();
    map<char,int>non_repeat;
    for(int i=0;i<n;i++){
        non_repeat[s[i]]++; 

    }
    for(int i=0;i<n;i++){
        if(non_repeat[s[i]]==1){
            cout<<s[i]<<endl;
            break;
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    non_repeat_charc(s);
    
}