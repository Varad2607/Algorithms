#include <iostream>
#include <vector>
using namespace std;

vector<int> two_sum(vector<int> &arr, int sum){
    int i, j;
    i = 0;
    j = arr.size() - 1;
    
    while (i < j) {
        int diff = arr[i] + arr[j];
        
        if (diff == sum) {
            return {arr[i], arr[j]}; // Return a vector with the two elements
        } 
        else if (diff > sum) {
            j--;
        } 
        else {
            i++;
        }
    }
    
    return {}; // Return an empty vector if no solution
}

int main() {
    int n;
    cout << "Enter the number of elements you want: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum;
    cout << "Enter the sum you want: ";
    cin >> sum;

    vector<int> result = two_sum(arr, sum);
    
    if (!result.empty()) {
        cout << "Pair found: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}
