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
    int longestMonotonicSubarray(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }
            maxLen = max({maxLen, incLen, decLen});
        }

        return maxLen;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [1, 4, 3, 3, 2] -> Expected: 2
    vector<int> nums1 = {1, 4, 3, 3, 2};
    cout << "Test 1: " << solver.longestMonotonicSubarray(nums1) << endl;

    // Test Case 2: [3, 3, 3, 3] -> Expected: 1
    vector<int> nums2 = {3, 3, 3, 3};
    cout << "Test 2: " << solver.longestMonotonicSubarray(nums2) << endl;

    // Test Case 3: [3, 2, 1] -> Expected: 3
    vector<int> nums3 = {3, 2, 1};
    cout << "Test 3: " << solver.longestMonotonicSubarray(nums3) << endl;

    return 0;
}