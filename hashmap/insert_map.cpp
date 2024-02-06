#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> fruitPrices;
    string fruit;
    int price;
    int numFruits;

    cout << "How many fruits do you want to enter? ";
    cin >> numFruits;

    for(int i = 0; i < numFruits; i++) {
        cout << "Enter fruit name: ";
        cin >> fruit;
        cout << "Enter " << fruit << "'s price: ";
        cin >> price;
        fruitPrices[fruit] = price;
    }

    // Method 1 to traverse over map
    for(const auto& pair: fruitPrices) {
        cout << pair.first << " has price " << pair.second << endl;
    }

    // Method 2 to traverse over map
    for(auto it = fruitPrices.begin(); it != fruitPrices.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}
