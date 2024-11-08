#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int unique_char(string &s){
    unordered_map<char,int> char_count;
    for (char c:s){
        char_count[c]++;
    }
    for (int i=0;i<s.size();i++){
        if(char_count[s[i]]==1){
            return i;
        }
    }
    return -1;

}

int main(){
    string s;
    getline(cin,s);
    cout<<unique_char(s);

}