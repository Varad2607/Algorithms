#include <iostream>
#include <iomanip> // for setw
using namespace std;

void staircase(int n) {
  for (int i = 0; i < n; i++) {
      // Print (n - i - 1) spaces
      cout << string(n - i - 1, ' ');

      // Print (i + 1) '#' symbols
      cout << string(i + 1, '#') << endl;
  }
}

int main() {
  int n;
  cin >> n;

  // Call the staircase function to print the staircase
  staircase(n);

  return 0;
}
