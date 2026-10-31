#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // stores indices of unresolved days

        for (int i = 0; i < n; i++) {
            // While current day is warmer than the day waiting at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                result[prevDay] = i - prevDay; // days waited
            }
            // Current day waits for a warmer day in the future
            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1 Expected: 1 1 4 2 1 1 0 0
    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res1 = solver.dailyTemperatures(t1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Test Case 2 Expected: 1 1 1 0
    vector<int> t2 = {30, 40, 50, 60};
    auto res2 = solver.dailyTemperatures(t2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}