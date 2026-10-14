#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // 1. In-place absolute values (no extra memory)
        for (int &x : nums) {
            x = abs(x);
        }

        // 2. Sort 32-bit ints directly (faster than 64-bit longs)
        sort(nums.begin(), nums.end());

        long long score = 0;
        int k = n / 2; // Exactly floor(n / 2) smallest values get subtracted

        // 3. Sequential loops without branch evaluation
        for (int i = 0; i < k; i++) {
            score -= 1LL * nums[i] * nums[i];
        }
        for (int i = k; i < n; i++) {
            score += 1LL * nums[i] * nums[i];
        }

        return score;
    }
};
int main() {
    Solution solver;

    // Test Case 1: [1, 2, 3] -> Expected: 12
    vector<int> t1 = {1, 2, 3};
    cout << "Test 1 Output: " << solver.maxAlternatingSum(t1) << endl;

    // Test Case 2: [1, -1, 2, -2, 3, -3] -> Expected: 16
    vector<int> t2 = {1, -1, 2, -2, 3, -3};
    cout << "Test 2 Output: " << solver.maxAlternatingSum(t2) << endl;

    // Test Case 3: [5] -> Expected: 25
    vector<int> t3 = {5};
    cout << "Test 3 Output: " << solver.maxAlternatingSum(t3) << endl;

    return 0;
}