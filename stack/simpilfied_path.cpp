#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

string simplified_path(string s) {
    stack<string> stk;
    stringstream ss(s);
    string item;
    while (getline(ss, item, '/')) {
        if (item == "" || item == ".")
            continue;
        else if (item == ".." && !stk.empty())
            stk.pop();
        else if (item != "..")
            stk.push(item);
    }

    string res;
    while (!stk.empty()) {
        res = "/" + stk.top() + res;
        stk.pop();
    }

    return res.empty() ? "/" : res;
}

int main() {
    string s;
    getline(cin, s);
    cout << "Simplified Path: " << simplified_path(s) << endl;
    return 0;
}
