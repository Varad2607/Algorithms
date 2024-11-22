#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isvalid_string(string s){

    stack <char> stk;
    for(auto c:s){
        if (c=='(' || c=='[' || c=='{'){
            stk.push(c);
        }
        else{
            if (stk.empty()||
                (c==')' && stk.top()!='('||
                c==']' && stk.top()!='[' ||
                c=='}' && stk.top()!='{'
                )){
                return false;
                }
                
            }
            stk.pop();
        return stk.empty();

    }


}


int main(){
    string s;
    getline(cin,s);
    cout<<isvalid_string(s);

}