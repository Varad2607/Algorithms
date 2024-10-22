#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int coin_change(int n, vector<int> &arr, int x) {
    sort(arr.begin(), arr.end(), greater<int>());
    int sum = 0;
    int i = 0;
    int count = 0;
    
    while (sum < x && i < n) { // Ensure loop exits when sum is greater than or equal to x or all coins are checked
        if (arr[i] <= x - sum) { // Check if the current coin can be used
            sum += arr[i];
            count++;
        } else {
            i++; // Move to the next coin if the current one cannot be used
        }
    }
    
    if (sum == x) {
        return count;
    } else {
        return -1; // Return -1 if it's not possible to make the exact sum
    }
}


int main(){
    int n = 10; // Hardcoded number of elements
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; // Hardcoded array
    int x = 54; // Hardcoded value for x
    
    cout << "Number of elements in the array: " << n << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total you want: " << x << endl;
    
    cout << "Minimum number of coins: " << coin_change(n, arr, x) << endl;
    
    return 0;
}
