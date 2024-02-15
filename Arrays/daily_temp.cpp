#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // Initialize the answer vector with zeros
    int n = temperatures.size();
    vector<int> answer(n, 0);  // Initialize the answer vector with zeros
    stack<int> stack;  // Stack to keep track of temperatures indices

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
            int prev_day = stack.top();
            stack.pop();
            answer[prev_day] = i - prev_day;  // Number of days to wait for warmer temperature
        }
        stack.push(i);
    }

    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
