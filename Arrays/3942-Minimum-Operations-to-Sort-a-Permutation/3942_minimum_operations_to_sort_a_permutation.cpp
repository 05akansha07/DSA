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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int asc_count = 0;
        int des_count = 0;

        for (int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i - 1] + 1) % n);
            des_count += (nums[i - 1] == (nums[i] + 1) % n);
        }

        // Already sorted in increasing order: [0, 1, 2, ..., n-1]
        if (asc_count == n - 1 && nums[0] == 0) {
            return 0;
        }

        // Case 1: Circularly Ascending
        if (asc_count == n - 1) {
            int leftRot = n - nums[0];
            int rightRot = 2 + nums[0];
            return min(leftRot, rightRot);
        }

        // Case 2: Circularly Descending
        if (des_count == n - 1) {
            int leftRot = 1 + (n - nums.back()) % n; // Reverse first, then rotate left
            int rightRot = 1 + (nums[0] + 1) % n;    // Rotate left until 0 is at end, then reverse
            return min(leftRot, rightRot);
        }

        return -1;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [0, 2, 1] -> Expected: 2
    vector<int> t1 = {0, 2, 1};
    cout << "Test 1: " << solver.minOperations(t1) << endl;

    // Test Case 2: [1, 0, 2] -> Expected: 2
    vector<int> t2 = {1, 0, 2};
    cout << "Test 2: " << solver.minOperations(t2) << endl;

    // Test Case 3: [2, 0, 1, 3] -> Expected: -1
    vector<int> t3 = {2, 0, 1, 3};
    cout << "Test 3: " << solver.minOperations(t3) << endl;

    return 0;
}
