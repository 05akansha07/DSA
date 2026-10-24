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
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1; // -1 represents all bits set to 1 in two's complement

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        // If array was already sorted, ans remains -1, so return 0
        return max(ans, 0);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [0, 3, 2, 1] -> Expected: 1
    vector<int> t1 = {0, 3, 2, 1};
    cout << "Test 1: " << solver.sortPermutation(t1) << endl;

    // Test Case 2: [0, 1, 3, 2] -> Expected: 2
    vector<int> t2 = {0, 1, 3, 2};
    cout << "Test 2: " << solver.sortPermutation(t2) << endl;

    // Test Case 3: [3, 2, 1, 0] -> Expected: 0
    vector<int> t3 = {3, 2, 1, 0};
    cout << "Test 3: " << solver.sortPermutation(t3) << endl;

    return 0;
}