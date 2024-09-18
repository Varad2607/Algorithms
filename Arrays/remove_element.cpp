#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> remove_element(vector<int>& arr, int k) {
    unordered_map<int, int> count;
    vector<int> result;
    
    // Count occurrences of each element
    for (int num : arr) {
        count[num]++;
    }
    
    // Remove the count of k
    count.erase(k);
    
    // Reconstruct the array without k
    for (int num : arr) {
        if (count.find(num) != count.end()) {
            result.push_back(num);
            count[num]--;
            if (count[num] == 0) {
                count.erase(num);
            }
        }
    }
    
    return result;
}

int main() {
    int n, nums;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        cin >> nums;
        arr.push_back(nums);
    }
    
    int k;
    cin >> k;
    
    vector<int> modified_arr = remove_element(arr, k);
    
    // Print the modified array
    for (int num : modified_arr) {
        cout << num << " ";
    }
    cout << endl;
}