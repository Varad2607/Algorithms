#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    return 0;
}

