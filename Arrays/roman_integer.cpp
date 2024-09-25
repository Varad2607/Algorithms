#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int roman_to_integer_conversion(string s) {
    int temp = 0;
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for (int i = 0; i < s.size(); i++) {
        // If the current numeral is smaller than the next, subtract it
        if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
            temp -= roman[s[i]];
        }
        // Otherwise, add the value
        else {
            temp += roman[s[i]];
        }
    }
    return temp;
}

int main() {
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;

    cout << "Integer value: " << roman_to_integer_conversion(roman) << endl;

    return 0;
}
