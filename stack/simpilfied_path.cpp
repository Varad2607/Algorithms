#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplified_path(string s){
    stack<string>stk;
    string res;
    string temp;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            continue;
        }
        temp="";
        while(s[i]!='/' && i<s.length()){
            temp+=s[i];
            i++;
        }
        if(temp=="."){
            continue;
        }
        else if(temp==".."){
            if(!stk.empty()){
                stk.pop();
            }
        }
        else {
            stk.push(temp);
        }
        
       

    }  
    while(!stk.empty()){
            res="/"+stk.top()+res;
            stk.pop();
        }
        if(res.size()==0){
            return "/";
        }
    return res;   
        
        

}

int main(){
    string s;
    getline(cin,s);
    cout << simplified_path(s) << endl;
    return 0;

}