#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize an array of vectors with predefined characters
    vector<char> keypad[] = {
        {}, // 0 has no characters associated
        {}, // 1 has no characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's' },
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z' }
    };

    // Loop through the array of vectors
    for (int i = 0; i < 10; i++) { // Loop from 0 to 9
        cout << "Key " << i << ": ";
        // Loop through each vector in the array
        for (size_t j = 0; j < keypad[i].size(); ++j) {
            cout << keypad[i][j];
        }
        cout << endl; // Newline for each keypad entry
    }
    return 0;
}
