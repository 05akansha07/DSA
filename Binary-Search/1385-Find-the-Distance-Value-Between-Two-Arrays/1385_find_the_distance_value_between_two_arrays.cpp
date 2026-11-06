#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break; // Now properly scoped inside the if block
                }
            }
            if (isValid) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Expected: 2
    vector<int> a1 = {4, 5, 8};
    vector<int> b1 = {10, 9, 1, 8};
    cout << "Test 1: " << solver.findTheDistanceValue(a1, b1, 2) << endl;

    // Test Case 2: Expected: 2
    vector<int> a2 = {1, 4, 2, 3};
    vector<int> b2 = {-4, -3, 6, 10, 20, 30};
    cout << "Test 2: " << solver.findTheDistanceValue(a2, b2, 3) << endl;

    // Test Case 3: Expected: 1
    vector<int> a3 = {2, 1, 100, 3};
    vector<int> b3 = {-5, -2, 10, -3, 7};
    cout << "Test 3: " << solver.findTheDistanceValue(a3, b3, 6) << endl;

    return 0;
}