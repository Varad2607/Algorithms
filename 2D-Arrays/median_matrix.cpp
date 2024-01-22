#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void median_matrix(int n, int m, vector<vector<int>> arr) {
    vector<int> mat;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat.push_back(arr[i][j]);
        }
    }

    sort(mat.begin(), mat.end());
    int total_elements = mat.size();
    if (total_elements % 2 != 0) {  // Odd number of elements
        cout << mat[total_elements / 2];
    } else {  // Even number of elements
        cout << (mat[total_elements / 2 - 1] + mat[total_elements / 2]) / 2.0;
    }
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of cols: ";
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));  // Corrected matrix initialization
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    median_matrix(n, m, arr);
}
